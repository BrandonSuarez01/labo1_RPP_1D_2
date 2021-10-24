/*
 * Nexo.h
 *
 *  Created on: 23 oct. 2021
 *      Author: brans
 */

#ifndef NEXO_H_
#define NEXO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estadias.h"
#include "Perros.h"
#include "Funciones.h"

int nexo_mostrarEstadia(sEstadiaDiaria estadias[], sDuenio duenios[], sPerro perros[], int tamEstadias, int tamDuenios, int tamPerros);
void nexo_listarVarias(sEstadiaDiaria estadias[],  sDuenio duenios[], sPerro perros[], int tam, int tamEstadias, int tamPerros, int tamDuenios);

#endif /* NEXO_H_ */
