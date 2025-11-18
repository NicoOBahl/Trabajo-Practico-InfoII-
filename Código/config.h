#ifndef CONFIG_H
#define CONFIG_H

#include "avr_api.h"

void inicio(); //funcion de inicializacion de micro

//Definicion de puertos y elementos a utilizar

#define SyP_PORT avr_GPIO_D

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
