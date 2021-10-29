/*
 * Dueño.c
 *
 *  Created on: 15 oct. 2021
 *      Author: brans
 */
#include "Duenio.h"

int duenios_hardCodear(sDuenio duenios[], int tam)
{
	int retorno = -1;
	int i;

	int ids[] = {30000, 30001, 30002, 30003, 30004};
	char nombre[][TAMNOMBRE] = {"Jose", "Marcos", "Alan", "Maria", "Lucia"};
	int telefono[]= {60596578, 67453478, 19871278, 76234578, 45232378};

	if(duenios != NULL)
	{
		for(i = 0; i < tam; i++)
		{
			duenios[i].id = ids[i];
			strcpy(duenios[i].nombre, nombre[i]);
			duenios[i].telefono = telefono[i];
			duenios[i].estado = OCUPADO;
		}
		retorno = 0;
	}

	return retorno;
}
void duenios_mostrarUno(sDuenio* duenios)
{
	printf("%-10d %-20s %-20d\n", (*duenios).id, (*duenios).nombre, (*duenios).telefono);
}
int duenios_mostrarVarios(sDuenio duenios[], int tamDuenios)
{
	int retorno = -1;
	int i;

	printf("\n%-10s %-20s %-20s\n\n", "ID Dueño", "Nombre del dueño", "Telefono de contacto");

	for(i = 0; i < tamDuenios; i++)
	{
		if(duenios[i].estado == OCUPADO)
		{
			duenios_mostrarUno(&duenios[i]);
			retorno = 0;
		}
	}


	return retorno;
}


