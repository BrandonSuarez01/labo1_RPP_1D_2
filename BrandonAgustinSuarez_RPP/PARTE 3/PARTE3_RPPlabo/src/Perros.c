/*
 * Perros.c
 *
 *  Created on: 7 oct. 2021
 *      Author: brans
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Perros.h"

void perros_hardCodear(sPerro perros[])
{
	int i;

	int ids[] = {7000, 7001, 7002};
	char nombre[][TAMNOMBRE] = {"Lobo", "Sheila", "Reina"};
	char raza [][TAMNOMBRE] = {"Sharpei", "Golden", "Galgo"};
	int edad [] = {2, 12, 13};

	for(i = 0; i < 3; i++)
	{
		perros[i].id = ids[i];
		strcpy(perros[i].nombre, nombre[i]);
		strcpy(perros[i].raza, raza[i]);
		perros[i].edad = edad[i];
		perros[i].estado = OCUPADO;
	}
}
void perros_listar(sPerro perros[], int tam)
{
	int i;

	printf("\n%-10s - %-20s - %-20s - %-20s\n\n", "ID", "Nombre", "Raza", "Edad");

	for(i = 0; i < tam; i++)
	{
		if(perros[i].estado == OCUPADO)
		{
			printf("%-10d - %-20s - %-20s - %-20d\n", perros[i].id, perros[i].nombre, perros[i].raza, perros[i].edad);
		}
	}

}
float perros_promediarEdad(sPerro perros[], int tam)
{
	int i;
	int acumulador = 0;
	float promedio;
	int contador = 0;

	for(i = 0; i < tam; i++)
	{
		if(perros[i].estado == OCUPADO)
		{
			acumulador = acumulador + perros[i].edad;
			contador++;
		}
	}

	promedio = acumulador / (float)contador;

	return promedio;
}
void perros_mostrarPromedio(float promedio)
{
	printf("El promedio de edad de los perros es: %.2f\n\n", promedio);
}
int perros_agregarUno(sPerro perros[], int tam, int *id)
{
	int retorno = -1;
	int index = perros_buscarEspacio(perros, tam);
	int idIncrementada = *id;

	if(index != -1)
	{
		if(perros_establecerUno(perros, tam, id, index) == 0)
		{
			printf("Se establecio el nuevo perrito.\n");
			idIncrementada++;
			*id = idIncrementada;
			retorno = 0;
		}
		else
		{
			printf("Se cancelo la carga del nuevo perrito\n");
		}
	}
	else
	{
		printf("NO hay espacio disponible.\n");
	}
	return retorno;
}
int perros_establecerUno(sPerro perros[], int tam, int *id, int index)
{
	int retorno = -1;

	char auxNombre[21];
	char auxRaza[21];
	int auxEdad;

	pedirString(auxNombre, "Ingrese el nombre del nuevo perrito(Maximo 21 caracteres): ", "ERROR - Ingrese el nombre sin simbolos y hasta 21 caracteres: ", TAMNOMBRE);
	pedirString(auxRaza, "Ingrese la raza del nuevo perrito(Maximo 21 caracteres): ", "ERROR - Ingrese la raza sin simbolos y hasta 21 caracteres: ", TAMNOMBRE);
	obtenerNumeroValido(&auxEdad, "Ingrese la edad del perrito (De 1 a 20 años): ", "ERROR - Ingrese una edad valida (1 a 20 años): ", 1, 20);

	if(perros_verificarConfirmacion("\nDesea crear este nuevo perrito?(Presione 'S' para confirmar)") == 0)
	{
		perros[index].id = *id;
		strcpy(perros[index].nombre, auxNombre);
		strcpy(perros[index].raza, auxRaza);
		perros[index].edad = auxEdad;
		perros[index].estado = OCUPADO;
		retorno = 0;
	}
	return retorno;
}
void perros_inicializarPerros(sPerro perros[], int tam)
{
	int i;

	for(i = 0; i < tam; i++)
	{
		perros[i].estado = VACIO;
	}
}
int perros_buscarEspacio(sPerro perros[], int tam)
{
	int i;
	int index = -1;

	for(i = 0; i < tam; i++)
	{
		if(perros[i].estado == VACIO)
		{
			index = i;
			break;
		}
	}
	return index;
}
int perros_verificarConfirmacion(char* mensaje)
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
int perros_recorrerArray(sPerro perros[], int tam, int idIngresada)
{
	int retorno = -1;

	for(int i = 0; i < tam; i++)
	{
		if(perros[i].id == idIngresada)
		{
			retorno = 0;
		}
	}
	return retorno;
}

