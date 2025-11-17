#ifndef LCD_APIAVR_H
#define LCD_APIAVR_H

#include "avr_api.h"
#include <util/delay.h>

#define LCD_GPIO avr_GPIOB_OUT
#define LCD_PORT avr_GPIO_B

#define RS avr_GPIOB_OUT_1
#define RS_PIN avr_GPIO_PIN_1

#define E avr_GPIOB_OUT_3
#define E_PIN avr_GPIO_PIN_3

#define D4 avr_GPIOB_OUT_4
#define D4_PIN avr_GPIO_PIN_4

#define D5 avr_GPIOB_OUT_5
#define D5_PIN avr_GPIO_PIN_5

#define D6 avr_GPIOB_OUT_6
#define D6_PIN avr_GPIO_PIN_6

#define D7 avr_GPIOB_OUT_7
#define D7_PIN avr_GPIO_PIN_7


void LCD_inicio(void);         // Inicializa el display LCD
void LCD_CLR(void);             // Borra el LCD
void LCD_OUT(char dato);        // Caracter al LCD
void LCD_NL(void);              // Cambia de l?nea en el LCD
void LCD_STR(const char *pun);  // Cadena de caracteres al LCD
void LCD_INT(int n);            // Entero al LCD
void LCD_CONFIG(void);          //Configura el LCD para utilizar con el ATMEGA segun la api

#endif
