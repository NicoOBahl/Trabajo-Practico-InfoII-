#include "config.h"
#include "fsm.h"

/*estados_t estado_inicio(){
}*/

estados_t estado_espera (int *cont, int cont_set){ //estado de espera
    int contador = 0;
    //apago motor
      while (SN1 && SN2){
	 contador++;
	 _delay_ms(100);         //cuento 0.1s
	 if (contador >= 100) return ciclo_compac;       //si ambos estÃ¡n encendidos durante 10s cambio de estado
      }
      if (!SN1 || !SN2){
	 contador = 0;			//si no cuento los 10 segundos vuelvo al estado de espera
      }
      if (SC) return deposito_obs;			//si detecta el sensor de obstruccion, cambio de estado
      if (*cont == cont_set) return deposito_lleno;		//si el contador llega al limite, cambio de estado
      return espera;
}


estados_t estado_ciccom (int *cont, int cont_set){     //estado de movimiento de compactadora
    //giro hacia delante
    if (IC && !FC){
        CM1 = 1;
        CM2 = 0;
        CEN = 1;
    }
    while (!FC){}			//espero que actue el fin de carrera
    _delay_ms(1000);
    //giro hacia atrás
    if (!IC && FC){
        CM1 = 0;
        CM2 = 1;
    }
    while (!IC){}		//espero que actue el inicio de carrera
      CEN=0;			//paro el motor
    return espera;
}

estados_t estado_depobs(){
    if (!IC && FC){
       CM1 = 0;
       CM2 = 1;
    }
    while (!IC){}		//espero que actue el inicio de carrera
      CEN=0;   
   TESTIGO = 1;
   ELVAL = 1;
   //añadir mensaje en lcd
   if (!SN1 && !SN2 && !SC && PRESET){
      TESTIGO = 0;
      ELVAL = 0;
      //añadir mensaje en lcd
      return espera;
   }
   return deposito_obs;
}

estados_t estado_deplleno(){
   //hago un giro hacia atras, para poner la compactadora en posicion de reposo
    if (!IC && FC){
       CM1 = 0;
       CM2 = 1;
    }
    while (!IC){}		//espero que actue el inicio de carrera
    CEN=0;
    TESTIGO = 1;
    //hacer mensaje en lcd
    return espera;
}
