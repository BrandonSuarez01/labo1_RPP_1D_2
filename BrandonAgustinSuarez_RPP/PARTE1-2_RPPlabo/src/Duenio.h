/*
 * Due�o.h
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

/**
 * @fn int duenios_hardCodear(sDuenio[], int)
 * @brief hard codea todos los espacios en la estructura de 5 deu�os.
 *
 * @param duenios pasa el array de los due�os.
 * @param tam pasa el tama�o de el array de due�os.
 * @return devuelve 0 si pudo hardcodear los due�os correctamente.
 */
int duenios_hardCodear(sDuenio duenios[], int tam);
/**
 * @fn void duenios_mostrarUno(sDuenio*)
 * @brief muestra solo un due�o del array.
 *
 * @param duenios pasa el array de los due�os.
 */
void duenios_mostrarUno(sDuenio* duenios);
/**
 * @fn int duenios_mostrarVarios(sDuenio[], int)
 * @brief muestra todos los due�os con el estado OCUPADO del array.
 *
 * @param duenios pasa el array de los due�os.
 * @param tamDuenios pasa el tama�o de el array de due�os.
 * @return devuelve 0 si pudo mostrar correctamente.
 */
int duenios_mostrarVarios(sDuenio duenios[], int tamDuenios);

#endif /* DUENIO_H_ */
