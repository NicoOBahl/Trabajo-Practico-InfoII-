#include "lcd_con_api.h"

void LCD_inicio(void){
    LCD_GPIO = LCD_GPIO | 0x20;     // Bus de 4 bits
    E = 1;
    _delay_ms(100);           // Dato sin validar
    E = 0;		// Comando al LCD
    RS = 0;
    LCD_OUT(0x28);  // Bus de 4 bits
    LCD_OUT(0x06);  // Display quieto
    LCD_OUT(0x0C);  // Dispaly ON - Cursor OFF - Sin parpadeo
    _delay_ms(100);
    LCD_CLR();      // BORRO EL LCD
}
// Borra la pantalla del display LCD
   void LCD_CLR(void){
    RS = 0;
    LCD_OUT(0x01); // Borra display
    LCD_OUT(0x02); // Cursor a Home
}
// Env?a un caracter al display LCD
void LCD_OUT(char dato){
_delay_ms(10);
    LCD_GPIO = LCD_GPIO | (dato & 0xF0); 	// El LCD toma el dato que est? en el puerto
    E = 1;
_delay_ms(10);// Dato sin validar
    E = 0;
    LCD_GPIO = LCD_GPIO & 0x0F;
    LCD_GPIO = LCD_GPIO | ((dato << 4) & 0xF0);	// El LCD toma el dato que est? en el puerto
    E = 1;
_delay_ms(10);
    E = 0;         // Dato sin validar
    LCD_GPIO = LCD_GPIO & 0x0F;
}
// Combia de l?nea en el display LCD
void LCD_NL(void){
    RS = 0;           // Comando al LCD
    LCD_OUT(0xC0);  // Comando para cambiar de l?nea
}
// Env?a una cadena de caracteres al display LCD
void LCD_STR(const char *pun){
    RS = 1;               // Dato al LCD
    while(*pun) {       // Mientras el caracter no sea nulo....
        LCD_OUT(*pun);  // Env?o el caracter al LCD
        pun++;          // Cambio al siguiente caracter
    }
    
}
// ENV?A UN ENTERO AL LCD
void LCD_INT(int n){
    int m,c,d,u;                // Declaro variables
    m=n/1000;                   // Miles
    c=(n-m*1000)/100;           // Centenas
    d=(n-(m*1000+c*100))/10;    // Decenas
    u=n-(d*10+c*100+m*1000);    // Unidades
    RS = 1;			//dato al LCD
    LCD_OUT(m+48);              // Imprimo los miles
    LCD_OUT(c+48);              // Imprimo las centenas
    LCD_OUT(d+48);              // Imprimo las decenas
    LCD_OUT(u+48);              // Imprimo las unidades
}

void LCD_CONFIG(){
    GpioInitStructure_AVR LCD;      //defino la variable LCD segun la estructura del AVR

    LCD.modo = avr_GPIO_mode_Output;        //defino que el LCD es una salida
    LCD.pines = RS_PIN | E_PIN | D4_PIN | D5_PIN | D6_PIN |D7_PIN;             // Configuro los pines del LCD
    LCD.port = LCD_PORT;                    //Configuro el puerto del LCD
    init_gpio(LCD);                         //Envio la configuracion
}

