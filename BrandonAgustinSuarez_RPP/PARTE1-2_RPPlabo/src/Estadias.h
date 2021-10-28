/*
 * Estadias.h
 *
 *  Created on: 23 oct. 2021
 *      Author: brans
 */

#ifndef ESTADIAS_H_
#define ESTADIAS_H_

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#include "Estadias.h"
#include "Perros.h"
#include "Fecha.h"

#define VACIO 0
#define OCUPADO 1
#define TAMESTADIA 5

typedef struct
{
	int id;
	int idPerro;
	int estado;
	int idDuenio;
	Fecha fecha;

}sEstadiaDiaria;

/**
 * @fn void estadia_inicializarEstadia(sEstadiaDiaria[], int)
 * @brief inicializa las estadias en 0 o VACIO.
 *
 * @param estadias pasa el array de la estructura sEstadiaDiaria.
 * @param tam pasa el tamaño del array de estadias.
 */
void estadia_inicializarEstadia(sEstadiaDiaria estadias[], int tam);
/**
 * @fn int estadia_buscarEspacio(sEstadiaDiaria[], int)
 * @brief busca un espacio disponible en el array de estadias.
 *
 * @param estadias pasa el array de la estructura sEstadiaDiaria.
 * @param tam pasa el tamaño del array de estadias.
 * @return devuelve el idex vacio si lo encontro o -1 si estan todos ocupados.
 */
int estadia_buscarEspacio(sEstadiaDiaria estadias[], int tam);
/**
 * @fn int estadia_verificarConfirmacion(char*)
 * @brief verifica que el usuario confirme los cambios que esta efectuando en las estadias.
 *
 * @param mensaje recibe el mensaje que se mostrara en la funcion.
 * @return devuelve o si se confirma  o -1 si se cancela.
 */
int estadia_verificarConfirmacion(char* mensaje);
/**
 * @fn int estadia_buscarPorId(sEstadiaDiaria[], int, int)
 * @brief busca una estadia previamente cargada en base a su id,
 *
 * @param estadias pasa el array de la estructura sEstadiaDiaria.
 * @param tam pasa el tamaño del array de estadias.
 * @param id pasa la id que se quiere buscar.
 * @return devuelve el index de la estructura si existe el id, sino devuelve -1.
 */
int estadia_buscarPorId(sEstadiaDiaria estadias[], int tam, int id);
/**
 * @fn int estadias_recorrerArray(sEstadiaDiaria[], int, int)
 * @brief recorre el array de estructuras de sEstadiaDiaria y valida que el id haya sido cargado.
 *
 * @param estadias pasa el array de la estructura sEstadiaDiaria.
 * @param tam pasa el tamaño del array de estadias.
 * @param idIngresada pasa la id a validar
 * @return devuelve 0 si la id es correcta.
 */
int estadias_recorrerArray(sEstadiaDiaria estadias[], int tam, int idIngresada);
#endif /* ESTADIAS_H_ */
