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


void estadia_inicializarEstadia(sEstadiaDiaria estadias[], int tam);
int estadia_buscarEspacio(sEstadiaDiaria estadias[], int tam);
int estadia_agregarUna(sEstadiaDiaria estadias[], int tam, int* id);
int estadia_establecerEstadia(sEstadiaDiaria estadias[], int i, int id);
int estadia_verificarConfirmacion(char* mensaje);
#endif /* ESTADIAS_H_ */
