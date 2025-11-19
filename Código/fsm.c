#include "config.h"

static int etapa_ciclo = 0;
static int etapa_deposito = 0;
static int etapa_obstruido = 0;

static int flag = 0;
static int flag_msj = 0;
static int flag_msj1 = 0;

estados_t estado_inicio(){
   if (!flag){
      mensaje_set();
      flag = 1;
   }
   if (lectura_seteo() && flag) return espera;
   if (lectura_run() && flag){
      mensaje_ciclos();
      cont_set++;
      LCD_INT(cont_set);
   }
   if (PRESET && flag){
      mensaje_ciclos();
      cont_set--;
      LCD_INT(cont_set);
   }
   return inicio;
}

estados_t estado_espera(){ // estado de espera
    if (!flag_msj && !(cont == cont_set) ){
      mensaje_espera();
      LCD_INT(cont);
      flag_msj = 1;
    }
    if (lectura_nivel() == ciclo_compac) return ciclo_compac; // si detecta el nivel, cambio de estado
    if (lectura_compuerta() == deposito_obs) return deposito_obs; // si detecta el sensor de obstruccion, cambio de estado
    if (cont == cont_set) return deposito_lleno; // si el contador llega al limite, cambio de estado
    return espera;
}

estados_t estado_ciccom(){
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
	    cont++;
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
    case 0:
        if (lectura_fincarrera()){
            retroceso_compactadora();
            etapa_deposito = 1;
        }else{
            parar_motor();
	    flag_msj1 = 0;
            etapa_deposito = 1;
        }
        break;
    case 1:
	if (!flag_msj1){
	    aviso_deplleno();
	    flag_msj1 = 1;
	}
	if (lectura_reset()){
	    cont = 0;
	    etapa_deposito = 0;
	    flag_msj = 0;
	    aviso_depok();
	    return espera;
	}
        break;
    }
    return deposito_lleno;
}
