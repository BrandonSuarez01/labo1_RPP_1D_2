/*
 * Perros.h
 *
 *  Created on: 7 oct. 2021
 *      Author: brans
 */

#ifndef PERROS_H_
#define PERROS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estadias.h"
#include "Funciones.h"

#define TAMNOMBRE 21
#define TAMPERROS 6


typedef struct
{
	int id;
	char nombre[TAMNOMBRE];
	char raza[TAMNOMBRE];
	int edad;
	int estado;
}sPerro;


void perros_inicializarPerros(sPerro perros[], int tam);
int perros_agregarUno(sPerro perros[], int tam, int *id);
int perros_buscarEspacio(sPerro perros[], int tam);
int perros_establecerUno(sPerro perros[], int tam, int *id, int index);
int perros_verificarConfirmacion(char* mensaje);
int perros_recorrerArray(sPerro perros[], int tam, int idIngresada);
/**
 * @fn void perros_hardCodear(sPerro[], int)
 * @brief hard codea 3 estructuras de perros.
 *
 * @param perros recibe el array de perros como parametro.
 * @param tam recibe el tamaño de el array de perros.
 */
void perros_hardCodear(sPerro perros[]);
/**
 * @fn void perros_listar(sPerro[], int)
 * @brief lista a todos los perros del array.
 *
 * @param perros recibe el array de perros como parametro.
 * @param tam recibe el tamaño de el array de perros.
 */
void perros_listar(sPerro perros[], int tam);
/**
 * @fn float perros_promediarEdad(sPerro[], int)
 * @brief promedia la edad de todos los perros del array.
 *
 * @param perros recibe el array de perros como parametro.
 * @param tam recibe el tamaño de el array de perros.
 * @return devuelve el promedio calculado.
 */
float perros_promediarEdad(sPerro perros[], int tam);
/**
 * @fn void perros_mostrarPromedio(float)
 * @brief muestra el promedio de la edad de todos los perros del array.
 *
 * @param promedio recibe el promedio calculado en otra funcion.
 */
void perros_mostrarPromedio(float promedio);
#endif /* PERROS_H_ */
