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

/**
 * @fn int duenios_hardCodear(sDuenio[], int)
 * @brief hard codea todos los espacios en la estructura de 5 deuños.
 *
 * @param duenios pasa el array de los dueños.
 * @param tam pasa el tamaño de el array de dueños.
 * @return devuelve 0 si pudo hardcodear los dueños correctamente.
 */
int duenios_hardCodear(sDuenio duenios[], int tam);
/**
 * @fn void duenios_mostrarUno(sDuenio*)
 * @brief muestra solo un dueño del array.
 *
 * @param duenios pasa el array de los dueños.
 */
void duenios_mostrarUno(sDuenio* duenios);
/**
 * @fn int duenios_mostrarVarios(sDuenio[], int)
 * @brief muestra todos los dueños con el estado OCUPADO del array.
 *
 * @param duenios pasa el array de los dueños.
 * @param tamDuenios pasa el tamaño de el array de dueños.
 * @return devuelve 0 si pudo mostrar correctamente.
 */
int duenios_mostrarVarios(sDuenio duenios[], int tamDuenios);

#endif /* DUENIO_H_ */
