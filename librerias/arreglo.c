/**
 * @file arreglo.c
 * @author Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)
 * @brief Implementación para librería con operaciones básicas de arreglos.
 * @version 0.1
 * @date 2022-03-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "arreglo.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Imprime un arreglo con el formato: [1,2,3]
 *
 * @param arreglo El arreglo a imprimir.
 * @param tamanio El tamaño del arreglo a imprimir.
 */
void imprimir_arreglo(int *arreglo, int tamanio)
{
  printf("[");
  for (int i = 0; i < tamanio; i++)
  {
    printf("%i%c", arreglo[i], (i + 1) < tamanio ? ',' : '\0');
  }
  printf("]");
}

/**
 * @brief Compara cada elemento de dos arreglos para saber si dos arreglos son
 *        iguales.
 *
 * @param a El primer arreglo.
 * @param b El segundo arreglo.
 * @param tamanio El tamaño de los arreglos (deben ser iguales).
 */
int arreglos_iguales(int *a, int *b, int tamanio)
{
  // Iteramos sobre cada elemento.
  for (int i = 0; i < tamanio; i++)
  {
    // Verificamos que cada elemento sea igual en ambos arreglos.
    if (a[i] != b[i])
    {
      return 0; // En auscencia de `false`.
    }
  }

  // Ambos son iguales.
  return 1; // En ausencia de `true`.
}

/**
 * @brief Copia los contenidos de un arreglo en otro.
 *
 * @param origen Arreglo origen.
 * @param destino Arreglo destino.
 * @param tamanio El tamaño de los arreglos.
 */
void copiar_arreglo(int *origen, int *destino, int tamanio)
{
  // Iteramos sobre los elementos del arreglo.
  for (int i = 0; i < tamanio; i++)
  {
    destino[i] = origen[i];
  }
}

/**
 * @brief Crea un nuevo arreglo de forma dinámica para N elementos.
 *
 * @param tamanio El número de elementos para el arreglo.
 */
int *crear_arreglo(int tamanio)
{
  return (int *)malloc(sizeof(int) * tamanio);
}
