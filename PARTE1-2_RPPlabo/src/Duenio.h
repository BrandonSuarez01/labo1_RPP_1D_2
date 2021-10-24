/*
 * Dueño.h
 *
 *  Created on: 15 oct. 2021
 *      Author: brans
 */

#ifndef DUENIO_H_
#define DUENIO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estadias.h"
#include "Perros.h"
#include "Funciones.h"

#define TAMNOMBRETRES 41
#define TAMDUENIO 5

typedef struct
{
	int id;
	char nombre[TAMNOMBRETRES];
	int telefono;
	int estado;

}sDuenio;

int duenios_hardCodear(sDuenio duenios[], int tam);
#endif /* DUENIO_H_ */
