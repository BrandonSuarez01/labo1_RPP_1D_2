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
#include "Nexo.h"

int nexo_agregarUnaEstadia(sEstadiaDiaria estadias[], sDuenio duenios[], sPerro perros[], int tam, int* id, int tamDuenios, int tamPerros)
{
	int retorno = -1;
	int index = estadia_buscarEspacio(estadias, tam);
	int idIncrementada = *id;

	if(index != -1)
	{
		if(nexo_establecerEstadia(estadias, duenios, perros, index, id, tamDuenios, tamPerros) == 0)
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
int nexo_establecerEstadia(sEstadiaDiaria estadias[], sDuenio duenios[], sPerro perros[], int i, int *id, int tamDuenios, int tamPerros)
{
	int retorno = -1;

	estadias[i].id = *id;
	duenios_mostrarVarios(duenios, tamDuenios);
	obtenerNumeroValido(&estadias[i].idDuenio, "\nIngrese el ID del dueño deseado: ", "\nERROR - reingrese el ID correctamente: ", 30000, 30004);
	perros_listar(perros, tamPerros);
	obtenerNumeroValido(&estadias[i].idPerro, "\nIngrese el ID del perro deseado: ", "\nERROR - reingrese el ID correctamente: ",7000, 7002);
	obtenerNumeroValido(&estadias[i].fecha.dia, "Ingrese el dia deseado (1 - 30): ", "ERROR - Ingrese un dia valido (1 - 30): ", 1, 30);
	obtenerNumeroValido(&estadias[i].fecha.mes, "Ingrese el mes deseado (1 - 12): ", "ERROR - Ingrese un mes valido (1 - 12): ", 1 , 12);
	obtenerNumeroValido(&estadias[i].fecha.anio, "Ingrese el año deseado (2020 - 2021): ", "ERROR - Ingrese un año valido (1 - 12): ", 2020 , 2021);

	if(estadia_verificarConfirmacion("\nIngrese 'S' para confirmar la carga de la estadia: ") == 0)
	{
		estadias[i].estado = OCUPADO;
		retorno = 0;
	}

	return retorno;
}
int nexo_borrarUnaEstadia(sEstadiaDiaria estadias[], int tam, sDuenio duenios[])
{
	int retorno = -1;
	int id;
	int index;

	obtenerNumeroValido(&id, "Ingrese el ID de la estadia que desea cancelar: ", "ERROR - Ese ID no existe, reingrese: ", 100000, 100003);
	index = estadia_buscarPorId(estadias, tam, id);

	if(index != -1)
	{
		if(estadia_verificarConfirmacion("Ingrese 'S' para confirmar la baja de la estadia: ") == 0)
		{
			estadias[index].estado = VACIO;
			printf("\nEstadia %d dada de baja correctamente!\n", estadias[index].id);
		}
		else
		{
			printf("\nSe cancelo la baja de la estadia\n");
		}
		retorno = 0;

	}
	else
	{
		printf("\nERROR - Estadia no encontrada...\n");
	}

	return retorno;
}
int nexo_mostrarEstadia(sEstadiaDiaria estadias[], sDuenio duenios[], sPerro perros[], int tamEstadias, int tamDuenios, int tamPerros)
{
	int retorno = -1;
	int i;
	int j;
	int k;

	for(i = 0; i < tamEstadias; i++)
		{
			for(j = 0; j < tamDuenios; j++)
			{
				if(estadias[i].idDuenio == duenios[j].id && duenios[j].estado == OCUPADO)
				{
					for(k = 0; k < tamPerros; k++)
					{
						if(estadias[i].idPerro == perros[k].id)
						{
							printf("%-10d - %-20s - %-20d - %-20s - %d/%d/%d\n",
									estadias[i].id, duenios[j].nombre, duenios[j].telefono, perros[k].nombre, estadias[i].fecha.dia, estadias[i].fecha.mes, estadias[i].fecha.anio);
							break;
						}
					}
				}
			}
		}
	return retorno;
}
void nexo_listarVarias(sEstadiaDiaria estadias[],  sDuenio duenios[], sPerro perros[], int tamEstadias, int tamPerros, int tamDuenios)
{
	int i;

	printf("%-10s - %-20s - %-20s - %-20s - %-20s\n\n", "ID Estadia", "Nombre del dueño", "Telefono de contacto", "Nombre del perro", "Fecha");
	for(i = 0; i < tamEstadias; i++)
	{
		if(estadias[i].estado == OCUPADO)
		{
			nexo_mostrarEstadia(&estadias[i], &duenios[i], &perros[i], tamEstadias, tamPerros, tamDuenios);
		}

	}
}
int nexo_ordenarEstadias(sEstadiaDiaria estadias[], sDuenio duenios[], int tam)
{
	int retorno = -1;
	int flagSwap;
	int i;
	int nuevoLimite;
	sEstadiaDiaria auxEstadia;

	do
	{
		nuevoLimite = tam - 1;
		flagSwap = 0;

		for(i = 0; i < nuevoLimite; i++)
		{
			if(estadias[i].fecha.dia < estadias[i + 1].fecha.dia && estadias[i].fecha.mes < estadias[i + 1].fecha.mes && estadias[i].fecha.anio < estadias[i + 1].fecha.anio)
			{
				auxEstadia = estadias[i];
				estadias[i] = estadias[i + 1];
				estadias[i + 1] = auxEstadia;
				flagSwap = 1;
			}
			else
			{
				if(estadias[i].fecha.dia == estadias[i + 1].fecha.dia && estadias[i].fecha.mes == estadias[i + 1].fecha.mes && estadias[i].fecha.anio == estadias[i + 1].fecha.anio)
				{
					if(strcmp(duenios[i].nombre, duenios[i + 1].nombre) == -1)
					{
						auxEstadia = estadias[i];
						estadias[i] = estadias[i + 1];
						estadias[i + 1] = auxEstadia;
						flagSwap = 1;

					}
				}
			}
			retorno = 0;

		}

	}while(flagSwap);


	return retorno;
}
