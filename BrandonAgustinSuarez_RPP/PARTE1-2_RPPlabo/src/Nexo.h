/*
 * Nexo.h
 *
 *  Created on: 23 oct. 2021
 *      Author: brans
 */

#ifndef NEXO_H_
#define NEXO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estadias.h"
#include "Perros.h"
#include "Funciones.h"

/**
 * @fn int nexo_agregarUnaEstadia(sEstadiaDiaria[], sDuenio[], sPerro[], int, int*, int, int)
 * @brief Permite agregar una estadia y aumenta el contandor de estadias si el retorno es 0.
 *
 * @param estadias pasa el array de la estructura sEstadiaDiaria.
 * @param duenios pasa el array de la estructura sDuenio.
 * @param perros pasa el array de la estructura sPerro.
 * @param tamEstadias pasa el tamaño de el array de  estadias.
 * @param id pasa el id de la estadia a agregar.
 * @param tamDuenios pasa el tamaño de el array de los dueños.
 * @param tamPerros pasa el tamaño de el array de los perros.
 * @return retorna 0 si se pudo cargar la estadia o -1 si se cancelo o no hay mas espacio.
 */
int nexo_agregarUnaEstadia(sEstadiaDiaria estadias[], sDuenio duenios[], sPerro perros[], int tamEstadias, int* id, int tamDuenios, int tamPerros);
/**
 * @fn int nexo_establecerEstadia(sEstadiaDiaria[], sDuenio[], sPerro[], int, int*, int, int)
 * @brief establece los valores de la estructura sEstadiaDiaria a ser cargados en el array.
 *
 * @param estadias pasa el array de la estructura sEstadiaDiaria.
 * @param duenios pasa el array de la estructura sDuenio.
 * @param perros pasa el array de la estructura sPerro.
 * @param i pasa el index vacio.
 * @param id pasa el id de la estadia cargada.
 * @param tamDuenios pasa el tamño de el array de los dueños.
 * @param tamPerros pasa el tamaño de el array de los perros.
 * @return devuelve 0 si se colocaron los datos correctamente o -1 si hubo algun error.
 */
int nexo_establecerEstadia(sEstadiaDiaria estadias[], sDuenio duenios[], sPerro perros[], int i, int* id, int tamDuenios, int tamPerros);
/**
 * @fn int nexo_borrarUnaEstadia(sEstadiaDiaria[], int, sDuenio[])
 * @brief borra logicamente una estadia previamente cargada.
 *
 * @param estadias pasa el array de la estructura sEstadiaDiaria.
 * @param tam pasa el tamaño de el array de estadias.
 * @param duenios pasa el array de la estructura sDuenio.
 * @return devuelve 0 si se confirmo la baja de la estadia o -1 si se cancelo o hubo algun error.
 */
int nexo_borrarUnaEstadia(sEstadiaDiaria estadias[], int tam, sDuenio duenios[]);
/**
 * @fn int nexo_listarEstadia(sEstadiaDiaria[], sDuenio[], sPerro[], int, int, int)
 * @brief lista las estadias si estas se encuentran ocupadas.
 *
 * @param estadias pasa el array de la estructura sEstadiaDiaria.
 * @param duenios pasa el array de la estructura sDuenio.
 * @param perros pasa el array de la estructura sPerro.
 * @param tamEstadias pasa el tamaño de el array de estadias.
 * @param tamDuenios pasa el tamaño de el array de dueños.
 * @param tamPerros pasa el tamaño de el array de perros.
 * @return devuelve 0 si pudo listar correctamente o -1 si hubo un error.
 */
int nexo_listarEstadia(sEstadiaDiaria estadias[], sDuenio duenios[], sPerro perros[], int tamEstadias, int tamDuenios, int tamPerros);
/**
 * @fn int nexo_mostrarPerrosConSusEstadias(sEstadiaDiaria[], sPerro[], sDuenio[], int, int, int)
 * @brief muestra a los perros y debajo las estadias que les fueron asignadas.
 *
 * @param estadias pasa el array de la estructura sEstadiaDiaria.
 * @param perros pasa el array de la estructura sPerro.
 * @param duenios pasa el array de la estructura sDuenio.
 * @param tamEstadias pasa el tamaño de el array de estadias.
 * @param tamPerros pasa el tamaño de el array de perros.
 * @param tamDuenios pasa el tamaño de el array de dueños.
 * @return devuelve 0 si pudo cumplir su funcion o -1 si hubo un error.
 */
int nexo_mostrarPerrosConSusEstadias(sEstadiaDiaria estadias[], sPerro perros[],sDuenio duenios[], int tamEstadias, int tamPerros, int tamDuenios);
/**
 * @fn int nexo_perroMasEstadias(sEstadiaDiaria[], int)
 * @brief muestra el nombre del perro con mas estadias asignadas.
 *
 * @param estadias pasa el array de la estructura sEstadiaDiaria.
 * @param tamEstadias pasa el tamaño de el array de estadias.
 * @return devuelve 0 si pudo cumplir su funcion o -1 si hubo un error.
 */
int nexo_perroMasEstadias(sEstadiaDiaria estadias[], int tamEstadias);
/**
 * @fn int nexo_modificarUnaEstadia(sEstadiaDiaria[], int, sDuenio[], sPerro[], int, int)
 * @brief permite el ingreso de un id de una estadia ya existente y permite modificar el telefono o el perro seleccionado.
 *
 * @param estadias pasa el array de la estructura sEstadiaDiaria.
 * @param tam pasa el tamaño de el array de estadias.
 * @param duenios pasa el array de la estructura sDuenio.
 * @param perros pasa el array de la estructura sPerro.
 * @param tamDuenios pasa el tamaño de el array de dueños.
 * @param tamPerros pasa el tamaño de el array de perros.
 * @return devuelve 0 si se realizo la modificacion o -1 si se cancelo.
 */
int nexo_modificarUnaEstadia(sEstadiaDiaria estadias[], int tam, sDuenio duenios[], sPerro perros[], int tamDuenios, int tamPerros);
/**
 * @fn int nexo_ordenarEstadias(sEstadiaDiaria[], sDuenio[], int)
 * @brief ordena las estadias por fecha y si estas son iguales por nombre de la A-Z
 *
 * @param estadias pasa el array de la estructura sEstadiaDiaria.
 * @param duenios pasa el array de la estructura sDuenio.
 * @param tam pasa el tamaño de el array de estadias.
 * @return devuelve 0 si se pudo ordenar o -1 si hubo un error.
 */
int nexo_ordenarEstadias(sEstadiaDiaria estadias[], sDuenio duenios[], int tam);

#endif /* NEXO_H_ */
