#include "config.h"
#include "avr_api.h"

typedef struct {        
    int contador;
    char enable_alarma;
    char enable_compuerta;
}config_t;

typedef enum{
    espera = 0,
    ciclo_compac = 1,
    deposito_obs = 2,
    deposito_lleno = 3
}estados_t;

estados_t estado_inicio();       //Estado de inicio, configuracion
estados_t estado_espera();       //Estado de espera de sensores
estados_t estado_depobs();       //Estado de depÃ³sito obstruido
estados_t estado_ciccom(int *cont, int cont_set);       //Estado de actuacion de la compactadora
estados_t estado_deplleno();      //Estado de deposito lleno

