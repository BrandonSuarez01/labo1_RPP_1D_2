/*
Suarez Brandon: Recuperatorio parcial uno.

Se necesita gestionar una guardería de perros, la cual cuidará a un perrito por día. Para eso se
deberá desarrollar lo siguiente:

ENTIDADES:

Perro:
● id
● nombre (máximo 21 caracteres)
● raza (máximo 21 caracteres)
● edad

EstadiaDiaria:

● id (comienza en 100000, autoincremental)
● nombreDuenio (cadena de caracteres) Validar
● telefonoContacto (sólo números) Validar
● idPerro (debe existir) Validar
● fecha (Validar día, mes y año)

DATOS PREVIOS:

El array de perros será hardcodeado.
Perros
1) 7000, Lobo, Sharpei, 2
2) 7001, Sheila, Golden, 12
3) 7002, Reina, Galgo, 13

MENÚ DE OPCIONES:

1. RESERVAR ESTADIA
2. MODIFICAR ESTADIA: Se ingresará el id, permitiendo en un submenú modificar:
● El teléfono de contacto
● El perro
3. CANCELAR ESTADÍA: Se ingresará el id de la estadía y se realizará una baja lógica.
4. LISTAR ESTADÍAS: Hacer un listado de las estadías ordenadas por fecha (las más
nuevas irán primero). Ante igualdad de fechas, se ordenará por el nombre del dueño.
5. LISTAR PERROS
6. Promedio de edad de los perros.

PARTE 3:

9. ALTA DE PERRO: Con id autoincremental (comienza en 7002 por los 3 perritos que ya
estaban hardcodeados).
10. La cantidad de dueños que se llaman Alan y que, a su vez, tienen al menos una
estadía reservada.
11. Listado de estadías realizadas por dueñas que se llaman Lucia y cuya fecha de
reserva es durante la segunda quincena de noviembre 2021.

*/
#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#include "Estadias.h"
#include "Perros.h"
#include "Duenio.h"
#include "Nexo.h"

int main(void)
{
	setbuf(stdout, NULL);

	int opcionMenu;
	int idEstadia = 100000;
	int contadorEstadias = 0;
	float promedio;
	int idPerro = 7003;

	sEstadiaDiaria estadias[TAMESTADIA];
	sPerro perros[TAMPERROS];
	sDuenio duenios[TAMDUENIO];

	duenios_hardCodear(duenios, TAMDUENIO);
	perros_inicializarPerros(perros, TAMPERROS);
	estadia_inicializarEstadia(estadias, TAMESTADIA);
	perros_hardCodear(perros);

	do
	{
		obtenerNumeroValido(&opcionMenu, "------------------Menu------------------\n"
										 "\nBienvenido a la guarderia 'PATITAS':\n\n"
											"1. RESERVAR ESTADIA.\n"
											"2. MODIFICAR ESTADIA.\n"
											"3. CANCELAR ESTADIA.\n"
											"4. LISTAR ESTADIAS.\n"
											"5. LISTAR PERROS.\n"
											"6. PROMEDIO edad de los perros.\n"
											"7. MOSTRAR perro con mas estadias.\n"
											"8. MOSTRAR perros con sus estadias.\n"
											"9. AGREGAR nuevo perrito.\n"
											"10. ESTADIAS con duenio 'Alan'.\n"
											"11. LISTADO de estadias con duenia 'Lucia'.\n"
											"12. Salir.\n"
										"-----------------------------------------\n"
											"Ingrese la opcion deseada: ",
										"------------------Menu------------------\n"
											"1. RESERVAR ESTADIA.\n"
											"2. MODIFICAR ESTADIA.\n"
											"3. CANCELAR ESTADIA.\n"
											"4. LISTAR ESTADIAS.\n"
											"5. LISTAR PERROS.\n"
											"6. PROMEDIO edad de los perros.\n"
											"7. MOSTRAR perro con mas estadias.\n"
											"8. MOSTRAR perros con sus estadias.\n"
											"9. AGREGAR nuevo perrito.\n"
											"10.ESTADIAS con duenio 'Alan'.\n"
											"11. LISTADO de estadias con duenia 'Lucia'.\n"
											"12.Salir.\n"
										"-----------------------------------------\n"
											"ERROR - Reingrese una opcion valida: ", 1, 12);

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
					nexo_modificarUnaEstadia(estadias, TAMESTADIA, duenios, perros, TAMDUENIO, TAMPERROS);
				}
				else
				{
					printf("ERROR - Aun no se ah agregado ninguna estadia...\n");
				}
			break;
			case 3 :
				if(contadorEstadias > 0)
				{
					nexo_listarEstadia(estadias, duenios, perros, TAMESTADIA, TAMDUENIO, TAMPERROS);
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
					systemPause("Presione una tecla para continuar...\n");
					nexo_ordenarEstadias(estadias, duenios, TAMESTADIA);
					nexo_listarEstadia(estadias, duenios, perros, TAMESTADIA, TAMDUENIO, TAMPERROS);
				}
				else
				{
					printf("ERROR - Aun no se ah agregado ninguna estadia...\n");
				}
			break;
			case 5 :
				systemPause("Listando...Presione una tecla para continuar...\n");
				perros_listar(perros, TAMPERROS);
			break;
			case 6 :
				promedio = perros_promediarEdad(perros, TAMPERROS);
				systemPause("Calculando promedio...Presione una tecla para continuar...\n");
				perros_mostrarPromedio(promedio);
			break;
			case 7 :
				if(contadorEstadias > 0)
				{
					nexo_perroMasEstadias(estadias, TAMESTADIA, perros);
				}
				else
				{
					printf("ERROR - Aun no se ah agregado ninguna estadia...\n");
				}
			break;
			case 8:
				if(contadorEstadias > 0)
				{
					systemPause("Listando...Presione una tecla para continuar...\n");
					nexo_mostrarPerrosConSusEstadias(estadias, perros, duenios, TAMESTADIA, TAMPERROS, TAMDUENIO);
				}
				else
				{
					printf("ERROR - Aun no se ah agregado ninguna estadia...\n");
				}
			break;
			case 9 :
				perros_agregarUno(perros, TAMPERROS, &idPerro);
			break;
			case 10 :
				if(contadorEstadias > 0)
				{
					systemPause("Listando...Presione una tecla para continuar...\n");
					nexo_mostrarCantidadAlan(estadias, duenios, TAMESTADIA);
				}
				else
				{
					printf("ERROR - Aun no se ah agregado ninguna estadia...\n");
				}
			break;
			case 11 :
				if(contadorEstadias > 0)
				{
					systemPause("Listando...Presione una tecla para continuar...\n");
					nexo_mostrarEstadiasLucia(estadias, duenios, perros, TAMESTADIA, TAMDUENIO, TAMPERROS);
				}
				else
				{
					printf("ERROR - Aun no se ah agregado ninguna estadia...\n");
				}
			break;
			case 12 :
				printf("Finalizo la carga de estadias...");
			break;
		}

	}while(opcionMenu != 12);

	return EXIT_SUCCESS;
}
