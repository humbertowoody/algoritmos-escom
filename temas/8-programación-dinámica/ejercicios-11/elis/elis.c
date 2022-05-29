/**
 * @file elis.c
 * @author Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)
 * @brief Solución al problema ELIS en SPOJ.
 * @version 0.1
 * @date 2022-05-28
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

// Constantes de ejecución.
#define LONGITUD_MAXIMA_ARREGLO 10

/**
 * @brief Algoritmo que calcula el subconjunto de números consecutivos que se encuentren
 * ordenados de menor a mayor.
 *
 * @param arr El arreglo de números.
 * @param n La longitud de arr.
 * @return int Un entero con el número de elementos del subconjunto que cumpla las condiciones dadas.
 */
int lis(int *arr, int n);

/**
 * @brief Encuentra el número máximo dentro de un arreglo de enteros.
 *
 * @param arr El arreglo a buscar.
 * @param n El número de elementos del arreglo.
 * @return int El elemento máximo encontrado.
 */
int maximo_de_arreglo(int *arr, int n);

// Función principal.
int main()
{
  // Variables locales.
  int arr[LONGITUD_MAXIMA_ARREGLO], // El arreglo con los datos.
      n;                            // La longitud del arreglo.

  // Leemos la longitud del arreglo.
  scanf("%i", &n);

  // Leemos los datos del arreglo.
  for (int i = 0; i < n; i++)
  {
    scanf("%i", &arr[i]);
  }

  // Llamamos a la función LIS calculando la longitud del subconjunto que cumpla las condiciones dadas.
  printf("%i\n", lis(arr, n));

  // Finalizamos la ejecución.
  return 0;
}

/**
 * @brief Algoritmo que calcula el subconjunto de números consecutivos que se encuentren
 * ordenados de menor a mayor.
 *
 * @param arr El arreglo de números.
 * @param n La longitud de arr.
 * @return int Un entero con el número de elementos del subconjunto que cumpla las condiciones dadas.
 */
int lis(int arr[], int n)
{
  // Variables locales.
  int memoizacion[n]; // El arreglo de memoización para el algoritmo.

  // Iniciamoz la primer posición de nuestro arreglo de memoización en 1.
  memoizacion[0] = 1;

  // Iteramos sobre las dimensiones de nuestro arreglo.
  for (int i = 1; i < n; i++)
  {
    // Iniciamos la posición actual en 1.
    memoizacion[i] = 1;

    // Iteramos sobre las posiciones anteriores.
    for (int j = 0; j < i; j++)
    {
      // Si el elemento en i es mayor que el elemento en j y la longitud de la subsecuencia
      // calculada en j es mayor que la longitud de la subsecuencia calculada en i, entonces
      // actualizamos la longitud de la subsecuencia en i a aquella calculada en j y sumamos 1.
      if (arr[i] > arr[j] && memoizacion[i] < memoizacion[j] + 1)
        memoizacion[i] = memoizacion[j] + 1;
    }
  }

  // Retornamos el valor máximo de nuestro arreglo de memoización.
  return maximo_de_arreglo(memoizacion, n);
}

/**
 * @brief Encuentra el número máximo dentro de un arreglo de enteros.
 *
 * @param arr El arreglo a buscar.
 * @param n El número de elementos del arreglo.
 * @return int El elemento máximo encontrado.
 */
int maximo_de_arreglo(int *arr, int n)
{
  // Variables locales.
  int max = arr[0]; // Asumimos como máximo el primer elemento.

  // Iteramos sobre el resto de elementos en el arreglo.
  for (int i = 1; i < n; i++)
  {
    // Si el elemento actual es mayor que el máximo, lo actualizamos.
    if (arr[i] > max)
    {
      max = arr[i];
    }
  }

  // Retornamos el máximo.
  return max;
}
