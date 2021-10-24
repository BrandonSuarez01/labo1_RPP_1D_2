/*
 * Nexo.c
 *
 *  Created on: 23 oct. 2021
 *      Author: brans
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estadias.h"
#include "Perros.h"
#include "Funciones.h"
#include "Duenio.h"

int nexo_mostrarEstadia(sEstadiaDiaria estadias[], sDuenio duenios[], sPerro perros[], int tamEstadias, int tamDuenios, int tamPerros)
{
	int retorno = -1;

	for(int i = 0; i < tamEstadias; i++)
		{
			for(int j = 0; j < tamDuenios; j++)
			{
				for(int k = 0; k < tamPerros; k++)
				{
					if(estadias[i].idDuenio == duenios[j].id && estadias[i].idPerro == perros[k].id)
					{
						printf("%-10d - %-20s - %-20d - %-20s - %d/%d/%d\n",
								estadias[i].id, duenios[j].nombre, duenios[j].telefono, perros[k].nombre, estadias[i].fecha.dia, estadias[i].fecha.mes, estadias[i].fecha.anio);
						break;
					}

				}

			}
		}
	return retorno;
}
void nexo_listarVarias(sEstadiaDiaria estadias[],  sDuenio duenios[], sPerro perros[], int tam, int tamEstadias, int tamPerros, int tamDuenios)
{
	int i;

	printf("%-10s - %-20s - %-20s - %-20s - %-20s\n\n", "ID Estadia", "Nombre del dueño", "Telefono de contacto", "Nombre del perro", "Fecha");
	for(i = 0; i < tam; i++)
	{
		if(estadias[i].estado == OCUPADO)
		{
			nexo_mostrarEstadia(estadias, duenios, perros, tamEstadias, tamPerros, tamDuenios);
		}

	}
}
