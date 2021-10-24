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

void perros_hardCodear(sPerro perros[], int tam)
{
	int i;

	int ids[] = {7000, 7001, 7002};
	char nombre[][TAMNOMBRE] = {"Lobo", "Sheila", "Reina"};
	char raza [][TAMNOMBRE] = {"Sharpei", "Golden", "Galgo"};
	int edad [] = {2, 12, 13};

	for(i = 0; i < tam; i++)
	{
		perros[i].id = ids[i];
		strcpy(perros[i].nombre, nombre[i]);
		strcpy(perros[i].raza, raza[i]);
		perros[i].edad = edad[i];
	}
}
void perros_listar(sPerro perros[], int tam)
{
	int i;

	printf("%-10s - %-20s - %-20s - %-20s\n", "ID", "Nombre", "Raza", "Edad");

	for(i = 0; i < tam; i++)
	{
		printf("%-10d - %-20s - %-20s - %-20d\n", perros[i].id, perros[i].nombre, perros[i].raza, perros[i].edad);
	}

}
float perros_promediarEdad(sPerro perros[], int tam)
{
	int i;
	int acumulador = 0;
	float promedio;

	for(i = 0; i < tam; i++)
	{
		acumulador = acumulador + perros[i].edad;
	}

	promedio = acumulador / (float)3;

	return promedio;
}
void perros_mostrarPromedio(float promedio)
{
	printf("El promedio de edad de los perros es: %.2f\n\n", promedio);
}
