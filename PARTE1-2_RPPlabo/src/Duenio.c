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
	char nombre[][TAMNOMBRE] = {"Jose", "Marcos", "Anibal", "Maria", "Marta"};
	int telefono[]= {1560596578, 1567453478, 1509871278, 1576234578, 1545232378};

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


