#ifndef FSM_H
#define FSM_H

#include "config.h"
#include "avr_api.h"

typedef struct {        //
    int contador;
    char enable_alarma;
    char enable_compuerta;
}config_t;

typedef enum{
    inicio = 0,
    espera = 1,
    ciclo_compac = 2,
    deposito_obs = 3,
    deposito_lleno = 4
}estados_t;

estados_t estado_inicio(int *cont_set0);       //Estado de inicio, configuracion
estados_t estado_espera(int *cont1, int *cont_set1);       //Estado de espera de sensores
estados_t estado_ciccom(int *cont2);       //Estado de actua cion de la compactadora
estados_t estado_depobs();       //Estado de depÃ³sito obstruido
estados_t estado_deplleno();      //Estado de deposito lleno

#endif