#include "config.h"

int cont = 0;
int cont_set = -1;

int main(){
   estados_t estado = inicio; //primer estado
   inicio_AT();
   sei();
   LCD_CONFIG();
   LCD_inicio();
   LCD_CLR();
   while (1){
      switch(estado){
	 case inicio:
	    estado = estado_inicio(&cont_set);
	    break;
	 case espera:
	    estado = estado_espera(&cont, &cont_set);
	    break;
	 case ciclo_compac:
	    estado = estado_ciccom(&cont);
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
