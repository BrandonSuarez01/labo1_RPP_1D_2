/*
Suarez Brandon: Recuperatorio parcial uno.


*/
#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#include "Estadias.h"
#include "Perros.h"
#include "Duenio.h"
#include "Nexo.h"

#define TAM 5

int main(void)
{
	setbuf(stdout, NULL);

	int opcionMenu;
	int idEstadia = 100000;
	int contadorEstadias = 0;
	float promedio;

	sEstadiaDiaria estadias[TAMESTADIA];
	sPerro perros[TAMPERROS];
	sDuenio duenios[TAMDUENIO];

	duenios_hardCodear(duenios, TAMDUENIO);
	estadia_inicializarEstadia(estadias, TAMESTADIA);
	perros_hardCodear(perros, TAMPERROS);

	do
	{
		pedirEntero(&opcionMenu, "------------------Menu------------------\n"
											"1. RESERVAR ESTADIA.\n"
											"2. MODIFICAR ESTADIA.\n"
											"3. CANCELAR ESTADIA.\n"
											"4. LISTAR ESTADIAS.\n"
											"5. LISTAR PERROS.\n"
											"6. PROMEDIO edad de los perros.\n"
											"7. Salir.\n"
										"-----------------------------------------\n"
											"Ingrese la opcion deseada: ",
											"------------------Menu------------------\n"
											"1. RESERVAR ESTADIA.\n"
											"2. MODIFICAR ESTADIA.\n"
											"3. CANCELAR ESTADIA.\n"
											"4. LISTAR ESTADIAS.\n"
											"5. LISTAR PERROS.\n"
											"6. PROMEDIO edad de los perros.\n "
											"7.Salir.\n"
										"-----------------------------------------\n"
											"ERROR - Reingrese una opcion valida: ", 1, 7);

		switch(opcionMenu)
		{
			case 1 :
				if(estadia_agregarUna(estadias, TAMESTADIA, &idEstadia) == 0)
				{
					contadorEstadias++;
				}
			break;
			case 2 :
			break;
			case 3 :
			break;
			case 4 :
				nexo_listarVarias(estadias,duenios, perros, TAM, TAMESTADIA, TAMPERROS, TAMDUENIO);
			break;
			case 5 :
				perros_listar(perros, TAMPERROS);
			break;
			case 6 :
				promedio = perros_promediarEdad(perros, TAMPERROS);
				perros_mostrarPromedio(promedio);
			break;
			case 7 :
				printf("Finalizo la carga de empleados...");
			break;
		}

	}while(opcionMenu != 7);

	return EXIT_SUCCESS;
}
