/*
 * Funciones.c
 *
 *  Created on: 30 sep. 2021
 *      Author: brans
 *  Atoi(funcion que convierte una cadena de caracteres a enteros usando ASCII)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"
#include "Perros.h"
#include "Estadias.h"


int pedirEntero(int* enteroDevuelto, char* mensaje, char* mensajeError, int min, int max)
{
	int numeroIngresado;
	int devolucion;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &numeroIngresado);

	devolucion = isalpha(numeroIngresado);

	while(numeroIngresado < min || numeroIngresado > max || devolucion == 1 || numeroIngresado == '+')
	{
		printf("%s", mensajeError);
		fflush(stdin);
		scanf("%d", &numeroIngresado);
	}

	*enteroDevuelto = numeroIngresado;

	return 0;
}
void pedirString(char* string, char* primerMensaje, char* mensajeError, int max)
{
	char nombreSinValidar[100];
	int tam;

	if(primerMensaje != NULL && mensajeError != NULL)
	{
		printf("%s", primerMensaje);
		fflush(stdin);
		scanf("%[^\n]", nombreSinValidar);
		tam = strlen(nombreSinValidar);

		while(tam > max || validarSigno(nombreSinValidar) == 0 || nombreSinValidar == NULL)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%[^\n]", nombreSinValidar);
			tam = strlen(nombreSinValidar);
		}

		strcpy(string, nombreSinValidar);
	}


}
int pedirFlotante(float* flotanteDevuelto, char* mensaje, char* mensajeError, int min, int max)
{
	float numeroIngresado;

		printf("%s", mensaje);
		fflush(stdin);
		scanf("%f", &numeroIngresado);

		while(numeroIngresado < min || numeroIngresado > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%f", &numeroIngresado);
		}

		*flotanteDevuelto = numeroIngresado;

	return 0;
}
void pedirCaracter(char* caracter, char* mensaje)
{
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%s", caracter);
}
int validarSigno(char* string)
{
	int i;
	int tam;
	int retorno = -1;
	int devolucion;

	if(string != NULL)
	{
		tam = strlen(string);

		for(i = 0; i < tam; i++)
		{
			devolucion = isdigit(string[i]);

			if(devolucion == 1 || string[i] == '/' || string[i] == '.' || string[i] == '?'
				|| string[i] == '{' || string[i] == '}' || string[i] == '[' || string[i] == ']'
				|| string[i] == '_' || string[i] =='-'  || string[i] == ';' || string[i] == ':'
				|| string[i] == '*' || string[i] == '+' || string[i] == '¿' || string[i] == '"'
				|| string[i] == '!' || string[i] == '|' || string[i] ==  '#'|| string[i] == '<'
				|| string[i] == '>' || string[i] == '=' || string[i] == '@' || string[i] == ','
				|| string[i] == '(' || string[i] == ')' || string[i] == '%' || string[i] == '&')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
int esUnNumero(char* string)
{
	int retorno = 0;
	int i;
	int tam;

	if(string != NULL)
	{
		tam = strlen(string);
		for(i = 0; i < tam; i++)
		{
			if(string[i] < 48 || string[i] > 57)
			{
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}
int stringNormal(char* mensaje, char* string)
{
	int retorno = -1;
	char auxStr[200];

	if(mensaje != NULL && string != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", auxStr);

		strcpy(string, auxStr);
		retorno = 0;
	}

	return retorno;
}
int obtenerStringYNumeros(char* mensaje, char* input)
{
	int retorno = -1;
	char auxInput[200];

	if(mensaje != NULL && input != NULL)
	{
		if(stringNormal(mensaje, auxInput) == 0 && esUnNumero(auxInput) == 0)
		{
			strcpy(input, auxInput);
			retorno = 0;
		}
	}
	return retorno;
}
int obtenerNumeroValido(int* numero, char* mensaje, char* mensajeError, int min, int max)
{
	int retorno = 1;
	char auxStrNumber[200];
	int auxNumber;
	int flag;

	if(numero != NULL && mensaje != NULL && min < max)
	{
		flag = obtenerStringYNumeros(mensaje, auxStrNumber);
		auxNumber = atoi(auxStrNumber);

		while(flag != 0 || auxNumber < min || auxNumber > max)
		{
			flag = obtenerStringYNumeros(mensajeError, auxStrNumber);
			auxNumber = atoi(auxStrNumber);
		}
		*numero = auxNumber;
		retorno = 0;
	}
	return retorno;
}
int systemPause(char* message)
{
	int ret=-1;
	if(message!=NULL)
	{
		fflush(stdin);
		printf("\n%s",message);
		getchar();
		ret=0;
	}
	return ret;
}

