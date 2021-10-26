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
				if(nexo_agregarUnaEstadia(estadias, duenios, perros, TAMESTADIA, &idEstadia, TAMDUENIO, TAMPERROS) == 0)
				{
					contadorEstadias++;
				}
				else
				{
					printf("ERROR");
				}
			break;
			case 2 :
				if(contadorEstadias > 0)
				{
					nexo_modificarUnaEstadia(estadias, TAMESTADIA, duenios);
				}
				else
				{
					printf("ERROR - Aun no se ah agregado ninguna estadia...\n");
				}
			break;
			case 3 :
				if(contadorEstadias > 0)
				{
					if(!nexo_borrarUnaEstadia(estadias, TAMESTADIA, duenios))
					{
						contadorEstadias--;
					}
				}
				else
				{
					printf("ERROR - Aun no se ah agregado ninguna estadia...\n");
				}
			break;
			case 4 :
				if(contadorEstadias > 0)
				{
					printf("\nListando estadias...\n\n");
					nexo_ordenarEstadias(estadias, duenios, TAMESTADIA);
					system("pause");
					nexo_listarEstadia(estadias, duenios, perros, TAMESTADIA, TAMDUENIO, TAMPERROS);

				}
				else
				{
					printf("ERROR - Aun no se ah agregado ninguna estadia...\n");
				}
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
