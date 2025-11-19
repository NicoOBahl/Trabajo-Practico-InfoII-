#ifndef CONFIG_H
#define CONFIG_H

#include "avr_api.h"
#include "fsm.h"
#include "lcd_con_api.h"

extern int cont;
extern int cont_set;

extern volatile int systick_100ms;

/* LECTURAS DEL MICRO */

estados_t lectura_nivel();	//funcion para leer los sensores de nivel
estados_t lectura_compuerta();	//funcion para leer el sensor de la compuerta

int lectura_iniciocarrera();	//lee el inicio de la carrera de la compactadora
int lectura_fincarrera();	//lee el fin de la carrera de la compactadora
int lectura_reset_compuerta();	//lee que se reseteen los sensores de nivel y compuerta
int lectura_reset();        //lee el pulsador de reset		
int lectura_run();          //lee el pulsador de run
int lectura_seteo();        //detecta los sensores para setear el contador

/* SALIDAS DEL MICRO */

void inicio_AT();			//funcion de inicializacion de micro
void avance_compactadora();	//ejecuta el avance de la compactadora
void retroceso_compactadora();	//ejecuta el retrocesod de la compactadora
void parar_motor();		//ejecuta la parada de la compactadora
void activar_compuerta();	//ejecuta la activacion de la compuerta
void reset_compuerta();		//ejecuta el reset de la compuerta

/* FUNCIONES DE LCD */

void aviso_depok();		//avisa que el deposito esta listo
void aviso_deplleno();		//avisa que el deposito esta lleno
void aviso_obstruccion();	//avisa que hubo una obstruccion
void mensaje_set();		//mensaje para seteo de contador
void mensaje_avancecompac();	//avisa que la compactadora avanza
void mensaje_retrocompac();	//avisa que la compactadora retrocede
void mensaje_espera();		//mensaje de estado espera
void mensaje_ciclos();		//muestra cantidad de ciclos

//handler del timer

void handler_100ms();

//Definicion de puertos y elementos a utilizar

#define SyP_PORT avr_GPIO_D			//puertos de sensores y pulsadores

#define SN1 avr_GPIOD_IN_0			//Sensor de nivel 1
#define SN1_PIN avr_GPIO_PIN_0

#define SN2 avr_GPIOD_IN_1			//Sensor de nivel 2
#define SN2_PIN avr_GPIO_PIN_1

#define SC avr_GPIOD_IN_2			//Sensor de compuerta
#define SC_PIN avr_GPIO_PIN_2

#define PRUN avr_GPIOD_IN_3			//Pulsador de marcha
#define PRUN_PIN avr_GPIO_PIN_3

#define PRESET avr_GPIOD_IN_4			//Pulsador de reset
#define PRESET_PIN avr_GPIO_PIN_4

#define IC avr_GPIOD_IN_6			//inicio de carrera
#define IC_PIN avr_GPIO_PIN_6

#define FC avr_GPIOD_IN_7			//fin de carrera
#define FC_PIN avr_GPIO_PIN_7

#define GENERICO_PORT avr_GPIO_C

#define TESTIGO avr_GPIOC_OUT_0			//Luz de aviso de contenedor lleno
#define TESTIGO_PIN avr_GPIO_PIN_0

#define ELVAL avr_GPIOC_OUT_1			//Electrovalvula de la compuerta
#define ELVAL_PIN avr_GPIO_PIN_1

#define CM1 avr_GPIOC_OUT_2           //PIN CONTROL 293 1
#define CM1_PIN avr_GPIO_PIN_2

#define CM2 avr_GPIOC_OUT_3           //PIN CONTROL 293 2
#define CM2_PIN avr_GPIO_PIN_3

#define CEN avr_GPIOC_OUT_4           //PIN ENABLE 293 
#define CEN_PIN avr_GPIO_PIN_4

#endif
