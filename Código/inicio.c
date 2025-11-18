#include "config.h"

void inicio(){
   GpioInitStructure_AVR entradas, generico;
   
   entradas.modo = avr_GPIO_mode_Input;
   entradas.port = SyP_PORT;
   entradas.pines = SN1_PIN | SN2_PIN | SC_PIN | PRUN_PIN | PRESET_PIN | PEMER_PIN| IC_PIN | FC_PIN;
   init_gpio(entradas);

   generico.modo = avr_GPIO_mode_Output;
   generico.port = GENERICO_PORT;
   generico.pines = TESTIGO_PIN | ELVAL_PIN | CM1_PIN | CM2_PIN | CEN_PIN;
   init_gpio(generico);
}
