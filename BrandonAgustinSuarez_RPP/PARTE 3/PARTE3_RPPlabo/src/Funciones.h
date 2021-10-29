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

/// @fn int esUnNumero(char*)
/// @brief comprueba que el string que recibe por parametro sea un numero utilizando codigo ASCII.
///
/// @param string es el numero que recibe pra validar.
/// @return devuelve 0 si el numero es un entero o 1 si es un caracter o simbolo.
int esUnNumero(char* string);
/// @fn int validarSigno(char*)
/// @brief valida que el parametro string no tenga signos.
///
/// @param string recibe el parametro a validar.
/// @return devuelve 0 si el string posee algun simbolo.
int validarSigno(char* string);
/// @fn int stringNormal(char*, char*)
/// @brief pide una cadena de caracteres normal.
///
/// @param mensaje recibe el mensaje a mostrar en la funcion.
/// @param string es la cadena que devuelve.
/// @return devulve 0 si funciono correctamente.
int stringNormal(char* mensaje, char* string);
/// @fn void pedirCaracter(char*, char*)
/// @brief pide un unico caracter.
///
/// @param caracter es el caracter que recibe.
/// @param mensaje recibe el mensaje a mostrar en la funcion.
void pedirCaracter(char* caracter, char* mensaje);
/// @fn int obtenerStringYNumeros(char*, char*)
/// @brief llama a las funciones esUnNumero y stringNormal.
///
/// @param mensaje recibe el mensaje a mostrar
/// @param input recibe dato validado por las funciones anteriores.
/// @return devuelve 0 si funciono correctamente.
int obtenerStringYNumeros(char* mensaje, char* input);
/// @fn void pedirString(char*, char*, char*, int)
/// @brief pide y valida una cadena de caracteres orientada a nombres y descripciones sin numeros.
///
/// @param string es la cadena de caracteres que devuelve.
/// @param primerMensaje primer mensaje a mostrar dentro de la funcion.
/// @param mensajeError mensaje de error que recibe para mostrar.
/// @param max maximo de caracteres que puede tener el string.
void pedirString(char* string, char* primerMensaje, char* mensajeError, int max);
/// @fn int obtenerNumeroValido(int*, char*, char*, int, int)
/// @brief llama a la funcion obtenerStringYNumeros y le pasa los parametros, valida el rango y convierte
/// la cadena de caracteres en un entero.
///
/// @param numero es el numero que va a retornar
/// @param mensaje es el primer mensaje que recibe para mostrar.
/// @param mensajeError mensaje que aparece si ocurrio un error.
/// @param min numero minimo que recibe.
/// @param max numero maximo que recibe.
/// @return devuelve 0 si funciono correctamente.
int obtenerNumeroValido(int* numero, char* mensaje, char* mensajeError, int min, int max);
/// @fn int pedirEntero(int*, char*, char*, int, int)
/// @brief pide al usuario el ingreso de un numero entero dentro de un rango.
///
/// @param enteroDevuelto es el entero que devuelve.
/// @param mensaje es el mensaje a mostrar en la funcion.
/// @param mensajeError el mensaje de error a mostrar si se hace un incorrecto ingreso de datos.
/// @param min rango minimo.
/// @param max rango maximo.
/// @return devuelve 0 si funciono correctamente.
int pedirEntero(int* enteroDevuelto, char* mensaje, char* mensajeError, int min, int max);
/// @fn int pedirFlotante(float*, char*, char*, int, int)
/// @brief pide un numero flotante.
///
/// @param flotanteDevuelto es el numero flotante que devuelve.
/// @param mensaje es el mensaje a mostrar en la funcion.
/// @param mensajeError el mensaje de error a mostrar si se hace un incorrecto ingreso de datos.
/// @param min rango minimo.
/// @param max rango maximo.
/// @return devuelve 0 si funciono correctamente.
int pedirFlotante(float* flotanteDevuelto, char* mensaje, char* mensajeError, int min, int max);
/// @fn int systemPause(char*)
/// @brief hace una pausa falsa en el sistema para mostrar ordenamente donde se requiera.
///
/// @param message recibe el mensaje a mostrar en la funcion.
/// @return devuelve 0 si funciono correctamente.
int systemPause(char* message);



#endif /* FUNCIONES_H_ */
