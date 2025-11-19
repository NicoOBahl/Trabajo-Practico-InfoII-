#ifndef FSM_H
#define FSM_H

#include "config.h"
#include "avr_api.h"

typedef enum{
    inicio = 0,
    espera = 1,
    ciclo_compac = 2,
    deposito_obs = 3,
    deposito_lleno = 4
}estados_t;

estados_t estado_inicio();       //Estado de inicio, configuracion
estados_t estado_espera();       //Estado de espera de sensores
estados_t estado_ciccom();       //Estado de actuacion de la compactadora
estados_t estado_depobs();       //Estado de deposito obstruido
estados_t estado_deplleno();      //Estado de deposito lleno

#endif

