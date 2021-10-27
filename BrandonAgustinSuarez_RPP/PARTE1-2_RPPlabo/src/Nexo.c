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

int nexo_agregarUnaEstadia(sEstadiaDiaria estadias[], sDuenio duenios[], sPerro perros[], int tamEstadias, int* id, int tamDuenios, int tamPerros)
{
	int retorno = -1;
	int index = estadia_buscarEspacio(estadias, tamEstadias);
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
	int auxIdDuenio;
	int auxIdPerro;
	int auxDia;
	int auxMes;
	int auxAnio;


	estadias[i].id = *id;
	duenios_mostrarVarios(duenios, tamDuenios);
	obtenerNumeroValido(&auxIdDuenio, "\nIngrese el ID del dueño deseado: ", "\nERROR - reingrese el ID correctamente: ", 30000, 30004);
	perros_listar(perros, tamPerros);
	obtenerNumeroValido(&auxIdPerro, "\nIngrese el ID del perro deseado: ", "\nERROR - reingrese el ID correctamente: ",7000, 7002);
	obtenerNumeroValido(&auxDia, "Ingrese el dia deseado (1 - 30): ", "ERROR - Ingrese un dia valido (1 - 30): ", 1, 30);
	obtenerNumeroValido(&auxMes, "Ingrese el mes deseado (1 - 12): ", "ERROR - Ingrese un mes valido (1 - 12): ", 1 , 12);
	obtenerNumeroValido(&auxAnio, "Ingrese el año deseado (2020 - 2021): ", "ERROR - Ingrese un año valido (2020 - 2021): ", 2020 , 2021);

	if(estadia_verificarConfirmacion("\nIngrese 'S' para confirmar la carga de la estadia: ") == 0)
	{
		estadias[i].idDuenio = auxIdDuenio;
		estadias[i].idPerro = auxIdPerro;
		estadias[i].fecha.dia = auxDia;
		estadias[i].fecha.mes = auxMes;
		estadias[i].fecha.anio = auxAnio;
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

	obtenerNumeroValido(&id, "\nIngrese el ID de la estadia que desea cancelar: ", "ERROR - Ese ID no existe, reingrese: ", 100000, 100005);
	index = estadia_buscarPorId(estadias, tam, id);

	if(index != -1)
	{
		if(estadia_verificarConfirmacion("Ingrese 'S' para confirmar la baja de la estadia: ") == 0)
		{
			estadias[index].estado = VACIO;
			printf("\nEstadia %d dada de baja correctamente!\n", estadias[index].id);
			retorno = 0;
		}
		else
		{
			printf("\nSe cancelo la baja de la estadia\n");
		}
	}
	else
	{
		printf("\nERROR - Estadia no encontrada...\n");
	}

	return retorno;
}
int nexo_listarEstadia(sEstadiaDiaria estadias[], sDuenio duenios[], sPerro perros[], int tamEstadias, int tamDuenios, int tamPerros)
{
	int retorno = -1;

	printf("\n%-10s - %-20s - %-20s - %-20s - %-20s\n\n", "ID Estadia", "Nombre", "Telefono", "Nombre del perro", "Fecha");
	for(int i = 0; i < tamEstadias; i++)
	{
		for(int j = 0; j < tamDuenios; j++)
		{
			for(int k = 0; k < tamPerros; k++)
			{

				if(estadias[i].idDuenio == duenios[j].id && estadias[i].idPerro == perros[k].id && estadias[i].estado == OCUPADO)
				{
					printf("%-10d - %-20s - %-20d - %-20s - %d/%d/%d\n",
					estadias[i].id, duenios[j].nombre, duenios[j].telefono, perros[k].nombre, estadias[i].fecha.dia, estadias[i].fecha.mes, estadias[i].fecha.anio);
					break;
					retorno = 0;
				}
			}
		}
	}

	return retorno;
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
			if(estadias[i].fecha.dia == estadias[i+1].fecha.dia && estadias[i].fecha.mes == estadias[i+1].fecha.mes && estadias[i].fecha.anio == estadias[i+1].fecha.anio)
			{
				if(strcmp(duenios[i].nombre, duenios[i + 1].nombre) == 1 && estadias[i].fecha.anio < estadias[i+1].fecha.anio)
				{
					auxEstadia = estadias[i];
					estadias[i] = estadias[i + 1];
					estadias[i + 1] = auxEstadia;
					flagSwap = 1;
				}
			}
			else
			{
				if(estadias[i].fecha.dia < estadias[i+1].fecha.dia && estadias[i].fecha.mes < estadias[i+1].fecha.mes && estadias[i].fecha.anio < estadias[i+1].fecha.anio)
				{
					auxEstadia = estadias[i];
					estadias[i] = estadias[i + 1];
					estadias[i + 1] = auxEstadia;
					flagSwap = 1;
				}
			}
			retorno = 0;
		}
	}while(flagSwap);

	return retorno;
}
int nexo_modificarUnaEstadia(sEstadiaDiaria estadias[], int tam, sDuenio duenios[], sPerro perros[], int tamDuenios, int tamPerros)
{
	int retorno = -1;
	int opcionSubMenu;
	int idIngresada;
	int index;
	int auxTelefono;
	int auxPerro;

	nexo_listarEstadia(estadias, duenios, perros, tam, tamDuenios, tamPerros);
	obtenerNumeroValido(&idIngresada, "\nIngrese el ID de la estadia a modificar: ", "\nERROR - Esa ID no existe, reingrese: ", 100000, 100005);
	index = estadia_buscarPorId(estadias, tam, idIngresada);

	do
	{
		pedirEntero(&opcionSubMenu, "\n----------MODIFICAR----------\n"
										"1. Modificar telefono\n"
										"2. Modificar id del Perro\n"
										"3. Salir.\n"
										"---------------------------\n"
										"Ingrese la opcion deseada: ",
										"\n----------MODIFICAR----------\n"
										"1. Modificar telefono\n"
										"2. Modificar id del Perro\n"
										"3. Salir.\n"
										"---------------------------\n"
										"ERROR - reingrese la opcion deseada: ", 1, 3);
			switch(opcionSubMenu)
			{
				case 1 :
					if(index != -1)
					{
						obtenerNumeroValido(&auxTelefono, "Ingrese el nuevo numero del cliente: ", "ERROR - Ese no es un numero valido, reingrese: ",10000000 , 99999999);
						printf("\nDesea modificar el siguiente numero de telefono %d ingresado en la estadia por %d?\n", duenios[index].telefono, auxTelefono);
						if(estadia_verificarConfirmacion("Ingrese 'S' para confirmar: ") == 0)
						{
							duenios[index].telefono = auxTelefono;
							printf("Numero modificado correctamente...\n");
						}
						else
						{
							printf("Se cancelo la modificacion del telefono...\n");
						}
					retorno = 0;
					}
					system("pause");
				break;
				case 2 :
					if(index != -1)
					{

						obtenerNumeroValido(&auxPerro, "Ingrese el nuevo ID del perro nuevo: ", "ERROR - Ese ID de perro no existe, reingrese: ", 7000, 7002);
						printf("\nDesea modificar el siguiente ID de perro %d ingresado en la estadia por %d?\n", estadias[index].idPerro, auxPerro);
						if(estadia_verificarConfirmacion("Ingrese 'S' para confirmar: ") == 0)
						{
							estadias[index].idPerro = auxPerro;
							printf("ID del perro modificado correctamente...\n");
						}
						else
						{
							printf("Se cancelo la modificacion del ID del perro...\n");
						}
					}
					system("pause");
				break;
			}
	}while(opcionSubMenu != 3);

	return retorno;
}
int nexo_perroMasEstadias(sEstadiaDiaria estadias[], int tamEstadias)
{
	int retorno = -1;
	int i;
	int auxIdPerro = 0;
	int contadorLobo = 0;
	int contadorSheila = 0;
	int contadorReina = 0;

	for(i = 0; i < tamEstadias; i++)
	{
		if(estadias[i].estado == OCUPADO)
		{
			auxIdPerro = estadias[i].idPerro;
		}
		switch(auxIdPerro)
		{
			 case 7000 :
				 contadorLobo++;
			 break;
			 case 7001 :
				 contadorSheila++;
			 break;
			 case 7002 :
				 contadorReina++;
			 break;
		}
	}
	if(contadorLobo > contadorSheila && contadorLobo > contadorReina)
	{
		printf("El perro con la mayor cantidad de estadias es Lobo.\n");
		retorno = 0;
	}
	else
	{
		if(contadorSheila > contadorReina)
		{
			printf("El perro con la mayor cantidad de estadias es Sheila.\n");
			retorno = 0;
		}
		else
		{
			printf("El perro con la mayor cantidad de estadias es Reina.\n");
			retorno = 0;
		}
	}

	return retorno;
}
int nexo_mostrarPerrosConSusEstadias(sEstadiaDiaria estadias[], sPerro perros[],sDuenio duenios[], int tamEstadias, int tamPerros, int tamDuenios)
{
	int retorno = -1;
	int i;
	int j;
	int k;

	for(i = 0; i < tamPerros; i++)
	{
		printf("Nombre: %s - ID : %d\n",perros[i].nombre, perros[i].id);
		for(j = 0; j < tamEstadias; j++)
		{
			for(k = 0; k < tamDuenios; k++)
			{
				if(estadias[j].estado == OCUPADO && perros[i].id == estadias[j].idPerro && estadias[j].idDuenio == duenios[k].id)
				{
					printf("%-10d %-20s %-20d\n", estadias[j].id, duenios[k].nombre, duenios[k].telefono);
					retorno = 0;
				}

			}
		}
	}

	return retorno;
}


