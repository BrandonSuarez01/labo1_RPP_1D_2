/*
 * Funciones.h
 *
 *  Created on: 30 sep. 2021
 *      Author: brans
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Perros.h"
#include "Estadias.h"

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int pedirEntero(int* enteroDevuelto, char* mensaje, char* mensajeError, int min, int max);
void pedirString(char* string, char* primerMensaje, char* mensajeError, int max);
int pedirFlotante(float* flotanteDevuelto, char* mensaje, char* mensajeError, int min, int max);
void pedirCaracter(char* caracter, char* mensaje);
int validarSigno(char* string);
int esUnNumero(char* string);
int obtenerNumeroValido(int* numero, char* mensaje, char* mensajeError, int min, int max);
int obtenerStringYNumeros(char* mensaje, char* input);

#endif /* FUNCIONES_H_ */
