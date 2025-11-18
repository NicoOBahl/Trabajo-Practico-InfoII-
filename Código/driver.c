#include "config.h"

volatile int systick_100ms = 0;
volatile int systick_10ms = 0;

void handler_100ms(){
   systick_100ms = 1;
}
void handler_10ms(){
   systick_10ms = 1;
}

void inicio_AT(){
   GpioInitStructure_AVR entradas, generico;
   SystickInitStructure_AVR config100, config10;
   
   entradas.modo = avr_GPIO_mode_Input;
   entradas.port = SyP_PORT;
   entradas.pines = SN1_PIN | SN2_PIN | SC_PIN | PRUN_PIN | PRESET_PIN | IC_PIN | FC_PIN;
   init_gpio(entradas);

   generico.modo = avr_GPIO_mode_Output;
   generico.port = GENERICO_PORT;
   generico.pines = TESTIGO_PIN | ELVAL_PIN | CM1_PIN | CM2_PIN | CEN_PIN;
   init_gpio(generico);
   
   config100.timernumber = avr_TIM1;	//uso el tmr1 de 16 bits
   config100.time_ms = 100;
   config100.avr_systick_handler = handler_100ms;
   init_Systick_timer(config100);
   
   config10.timernumber = avr_TIM3;	//uso el tmr1 de 16 bits
   config10.time_ms = 10;
   config10.avr_systick_handler = handler_10ms;
   init_Systick_timer(config10);
}

estados_t lectura_nivel (){			//funcion para leer los sensores de nivel y verifica si se mantiene en 10s
    static int contador = 0;			//static para mantener el valor entre llamadas
    if (systick_100ms){				//si ya contó los 100ms entonces va incrementando si los sensores leen hasta los 10 seg
	    systick_100ms=0;
	    if (SN1 && SN2){
	       contador++;
	       if (contador >= 100) return ciclo_compac;       //si se cumple, entonces cambio de estado
	    }else{
	    contador = 0;			//si no cuento los 10 segundos reseteo el contador
	    }
    }
    return espera;			//si no se cumple ninguna condicion vuelvo a esperar
}

estados_t lectura_compuerta(){
    return (SC == 1) ? deposito_obs : espera;	//si el sensor esta leyendo, voy a deposito obstruido, si no sigo esperando
}

int lectura_iniciocarrera(){
   return ((IC && !FC) == 1) ? 1 : 0;
}

int lectura_fincarrera(){
   return ((!IC && FC)==1) ? 1 : 0;
}

int lectura_reset_compuerta(){
   return ((!SN1 && !SN2 && !SC && PRESET) == 1) ? 1 : 0;
}

int lectura_reset(){
   return (PRESET == 1) ? 1 : 0;
}

int lectura_run(){
   return (PRUN == 1) ? 1 : 0;
}

int lectura_seteo(){
   return ((PRUN && SN1 && SN2) == 1) ? 1 : 0;
}

void avance_compactadora(){
   CM1 = 1;
   CM2 = 0;
   CEN = 1;
}

void retroceso_compactadora(){
   CM1 = 0;
   CM2 = 1;
   CEN = 1;
}

void parar_motor(){
   CM1 = 0;
   CM2 = 0;
   CEN = 0;
}

void activar_compuerta(){
   TESTIGO = 1;
   ELVAL = 1;
}

void reset_compuerta(){
   TESTIGO = 0;
   ELVAL = 0;
}

void aviso_deplleno(){
   LCD_CLR();
   LCD_STR("    ATENCION    ");
   LCD_NL();
   LCD_STR(" DEPOSITO LLENO ");
   TESTIGO = 1;
}

void aviso_depok(){
   LCD_CLR();
   LCD_STR("    DEPOSITO    ");
   LCD_NL();
   LCD_STR("      LISTO     ");
   TESTIGO = 0;
}

void aviso_obstruccion(){
   LCD_CLR();
   LCD_STR("    ATENCION    ");
   LCD_NL();
   LCD_STR(" SISTEMA TAPADO ");
}

void mensaje_set(){
      LCD_CLR();
      LCD_STR("Por favor elija ");
      LCD_NL();
      LCD_STR("Cant. de ciclos ");
}

void mensaje_ciclos(){
      LCD_CLR();
      LCD_STR("Numero de ciclos");
      LCD_NL();
}

void mensaje_avancecompac(){
   LCD_CLR();
   LCD_STR("  COMPACTADORA  ");
   LCD_NL();
   LCD_STR("  AVANZANDO...  ");
}

void mensaje_retrocompac(){
   LCD_CLR();
   LCD_STR("  COMPACTADORA  ");
   LCD_NL();
   LCD_STR("RETROCEDIENDO...");
}

void mensaje_espera(){
   LCD_CLR();
   LCD_STR("  ESPERANDO...  ");
   LCD_NL();
   LCD_STR(" CONTADOR: ");
}
