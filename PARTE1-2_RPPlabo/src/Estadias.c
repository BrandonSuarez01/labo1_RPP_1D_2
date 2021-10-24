/*
 * Estadias.c
 *
 *  Created on: 23 oct. 2021
 *      Author: brans
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#include "Estadias.h"
#include "Perros.h"

void estadia_inicializarEstadia(sEstadiaDiaria estadias[], int tam)
{
	int i;

	for(i = 0; i < tam; i++)
	{
		estadias[i].estado = VACIO;
	}
}
int estadia_buscarEspacio(sEstadiaDiaria estadias[], int tam)
{
	int i;
	int index = -1;

	for(i = 0; i < tam; i++)
	{
		if(estadias[i].estado == VACIO)
		{
			index = i;
			break;
		}
	}

	return index;
}
int estadia_agregarUna(sEstadiaDiaria estadias[], int tam, int* id)
{
	int retorno = -1;
	int index = estadia_buscarEspacio(estadias, tam);
	int idIncrementada = *id;

	if(index != -1)
	{
		if(!estadia_establecerEstadia(estadias, index, *id))
		{
			printf("Se establecio la estadia.\n");
			idIncrementada++;
			*id = idIncrementada;
		}
		else
		{
			printf("Se cancelo la carga de la estadia.\n");
		}
		retorno = 0;
	}
	else
	{
		printf("NO hay espacio disponible.\n");
	}
	return retorno;
}
int estadia_establecerEstadia(sEstadiaDiaria estadias[], int i, int id)
{
	int retorno = -1;

	estadias[i].id = id;;
	obtenerNumeroValido(&estadias[i].idDuenio, "Ingrese el ID del dueño deseado: ", "ERROR - reingrese el ID correctamente: ", 30000, 30004);
	pedirEntero(&estadias[i].idPerro, "Ingrese el ID del perro deseado: ", "ERROR - reingrese el ID correctamente: ",7000, 7002);
	pedirEntero(&estadias[i].fecha.dia, "Ingrese el dia deseado (1 - 30): ", "ERROR - Ingrese un dia valido (1 - 30): ", 1, 30);
	pedirEntero(&estadias[i].fecha.mes, "Ingrese el mes deseado (1 - 12): ", "ERROR - Ingrese un mes valido (1 - 12): ", 1 , 12);
	pedirEntero(&estadias[i].fecha.anio, "Ingrese el año deseado (2020 - 2021): ", "ERROR - Ingrese un año valido (1 - 12): ", 2020 , 2021);

	if(estadia_verificarConfirmacion("\nIngrese 'S' para confirmar la carga de la estadia: ") == 0)
	{
		estadias[i].estado = OCUPADO;
		retorno = 0;
	}

	return retorno;
}
int estadia_verificarConfirmacion(char* mensaje)
{
	int retorno = -1;
	char respuesta;

	pedirCaracter(&respuesta, mensaje);
	if(respuesta == 's' || respuesta == 'S')
	{
		retorno = 0;
	}

return retorno;
}

