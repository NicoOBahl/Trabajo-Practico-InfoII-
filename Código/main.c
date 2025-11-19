#include "config.h"

int cont = 0;
int cont_set = -1;

int main(){
   estados_t estado;  //primer estado, luego cambiar a inicio
   estados_t (*fsm[]) (void) = {estado_inicio, estado_espera, estado_ciccom, estado_depobs, estado_deplleno};
   inicio_AT();
   do{
      estado = estado_inicio();
   } while (estado != espera);
   while (1) estado = (*fsm[estado])();
   return 0;
 }
