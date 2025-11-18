#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

//#include "lcd_con_api.h"
#include "avr_api.h"
#include "config.h"
#include "fsm.h"

int main(){
   estados_t estado = espera; //primer estado, luego cambiar a inicio
   inicio();
   while (1){
      switch(estado){
	 case espera:
	    estado = estado_espera(0, 150);
	    break;
	 case ciclo_compac:
	    estado = estado_ciccom(0,150);
	    break;
	 case deposito_obs:
	    estado = estado_depobs();
	    break;
	 case deposito_lleno:
	    estado = estado_deplleno();
	    break;
      }
   }
 }
