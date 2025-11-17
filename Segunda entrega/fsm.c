#include "config.h"

static int etapa_ciclo = 0;
static int etapa_deposito = 0;
static int etapa_obstruido = 0;

static int flag = 0;
static int flag_msj = 0;

estados_t estado_inicio(int *cont_set0){
   if (!flag){
      mensaje_set();
      flag = 1;
   }
   if (lectura_seteo() && flag) return espera;
   if (lectura_run() && flag){
      mensaje_ciclos();
      (*cont_set0)++;
      LCD_INT(*cont_set0);
   }
   if (PRESET && flag){
      mensaje_ciclos();
      (*cont_set0)--;
      LCD_INT(*cont_set0);
   }
   return inicio;
}

estados_t estado_espera(int *cont1, int *cont_set1){ // estado de espera
    if (!flag_msj && !(*cont1 == *cont_set1) ){
      mensaje_espera();
      LCD_INT(*cont1);
      flag_msj = 1;
    }
    if (lectura_nivel() == ciclo_compac) return ciclo_compac; // si detecta el nivel, cambio de estado
    if (lectura_compuerta() == deposito_obs) return deposito_obs; // si detecta el sensor de obstruccion, cambio de estado
    if (*cont1 == *cont_set1) return deposito_lleno; // si el contador llega al limite, cambio de estado
    return espera;
}

estados_t estado_ciccom(int *cont2){
    switch (etapa_ciclo){
    case 0:
        if (lectura_iniciocarrera()){
            avance_compactadora();
	    mensaje_avancecompac();
            etapa_ciclo = 1;
        }
        break;
    case 1:
        if (lectura_fincarrera()){
            retroceso_compactadora();
	    mensaje_retrocompac();
            etapa_ciclo = 2;
        }
        break;
    case 2:
        if (lectura_iniciocarrera()){
            parar_motor();
            etapa_ciclo = 0;
	    (*cont2)++;
	    flag_msj = 0;
            return espera;
        }
        break;
    }
    return ciclo_compac;
}

estados_t estado_depobs(){
    switch (etapa_obstruido){
    case 0:
        if (!lectura_iniciocarrera()){
            retroceso_compactadora();
            etapa_obstruido = 1;
        } else {
            etapa_obstruido = 1;
        }
        break;
    case 1:
        if (lectura_iniciocarrera()){
            parar_motor();
            activar_compuerta();
	    aviso_obstruccion();
            etapa_obstruido = 2;
        }
        break;
    case 2:
        if (lectura_reset_compuerta()){
            reset_compuerta();
            etapa_obstruido = 0;
	    flag_msj = 0;
            return espera;
        }
        break;
    }
    return deposito_obs;
}

estados_t estado_deplleno(){
    switch (etapa_deposito){
    case 0: // Inicio del retroceso
        if (lectura_fincarrera()){
            retroceso_compactadora();
            etapa_deposito = 1;
        }else{
            parar_motor();
            etapa_deposito = 1;
        }
        break;
    case 1: // Esperando volver al inicio
	aviso_deplleno();
        etapa_deposito = 0;
	flag_msj = 0;
        return espera;
        break;
    }
    return deposito_lleno;
}
