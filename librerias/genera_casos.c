/**
 * @file genera_casos.c
 * @author Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)
 * @brief Implementación de la cabecera para generar casos de prueba.
 * @version 0.1
 * @date 2022-03-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "genera_casos.h"
#include "ordenamientos.h"
#include <stdlib.h>
#include <time.h>

/**
 * @brief Genera un arreglo de números aleatorios entre un limite inferior y un límite superior.
 *
 * @param tamano_arreglo El tamaño del arreglo a generar.
 * @param lim_inf  El límite inferior.
 * @param lim_sup  El límite superior.
 * @return int* Un arreglo de tamaño tamano_arreglo con números aleatorios entre lim_inf y lim_sup.
 */
int *genera_arreglo_enteros_aleatorios(int tamano_arreglo, int lim_inf, int lim_sup)
{
  // Asignación del arreglo.
  int *arreglo = (int *)malloc(sizeof(int) * tamano_arreglo);

  // Asignación de valores aleatorios.
  for (int i = 0; i < tamano_arreglo; i++)
  {
    arreglo[i] = rand() % (lim_sup - lim_inf + 1) + lim_inf;
  }

  // Retorno del arreglo.
  return arreglo;
}

/**
 * @brief Genera un arreglo de números ordenados de forma ascendente.
 *
 * @param tamano_arreglo El tamaño del arreglo a generar.
 * @return int* Un arreglo de tamaño tamano_arreglo con números ordenados de forma ascendente.
 */
int *genera_arreglo_enteros_ordenados(int tamano_arreglo)
{
  // Asignación del arreglo.
  int *arreglo = (int *)malloc(sizeof(int) * tamano_arreglo);

  // Asignación de valores ordenados.
  for (int i = 0; i < tamano_arreglo; i++)
  {
    arreglo[i] = i;
  }

  // Retorno del arreglo.
  return arreglo;
}

/**
 * @brief Utiliza el tiempo actual del CPU para generar una semilla para la función rand().
 *
 */
void aleatorizar_semilla(void)
{
  // Semilla para generación de números aleatorios.
  srand(time(NULL));
}
