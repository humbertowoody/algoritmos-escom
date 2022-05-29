/**
 * @file philosophers-stone.c
 * @author Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)
 * @brief Solución al problema Philosophers Stone en SPOJ.
 * @version 0.1
 * @date 2022-05-28
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

// Constantes de operación.
#define DIMENSION_MAXIMA 101

// Variables globales.
int matriz[DIMENSION_MAXIMA][DIMENSION_MAXIMA],            // Matriz original.
    tabla_memoizacion[DIMENSION_MAXIMA][DIMENSION_MAXIMA]; // Matriz de memoización.

/**
 * @brief Función que obtiene el máximo de tres enteros.
 *
 * @param a El primer entero
 * @param b El segundo entero.
 * @param c El tercer entero.
 * @return int El valor máximo de los tres enteros proporcionados.
 */
int max(int a, int b, int c);

/**
 * @brief Encuentra el máximo valor por fila para la matriz utilizando programación dinámica con una
 * tabla de memoización con los valores previamente calculados para filas anteriores.
 *
 * @param i La fila de la matriz.
 * @param j La columna de la matriz.
 * @param n El número de filas en la matriz.
 * @param m El número de columnas en la matriz.
 * @return int El valor máximo de piedras filosofales disponibles para la fila i.
 */
int recorrido(int i, int j, int n, int m);

// Función principal.
int main()
{
  // Variables locales.
  int t,    // El número de casos de prueba.
      m, n, // Dimensiones de la(s) matriz(ces).
      i, j, // Variables para iteraciones.
      max,  // Para almacenar el máximo temporal de cada iteración sobre la matriz.
      temp; // Para almacenar valores temporales.

  // Leemos el número de casos de prueba.
  scanf("%i", &t);

  // Iteramos para cada caso de prueba.
  while (t--)
  {
    // Leemos las dimensiones de la matriz.
    scanf("%i %i", &n, &m);

    // Inicializamos la tabla de memoización en 0.
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < m; j++)
      {
        tabla_memoizacion[i][j] = 0;
      }
    }

    // Leemos la matriz original.
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < m; j++)
      {
        scanf("%i", &matriz[i][j]);
      }
    }

    // Inicializamos el máximo en 0.
    max = 0;

    // Iteramos sobre el número de filas de la matriz.
    for (i = 0; i < m; i++)
    {
      // Calculamos el máximo para la fila actual.
      temp = recorrido(0, i, n, m);

      // Si el máximo actual es mayor que el máximo global, lo actualizamos.
      if (temp > max)
      {
        max = temp;
      }
    }

    // Imprimimos el máximo global.
    printf("%d\n", max);
  }

  // Finalizamos la ejecución.
  return 0;
}

/**
 * @brief Función que obtiene el máximo de tres enteros.
 *
 * @param a El primer entero
 * @param b El segundo entero.
 * @param c El tercer entero.
 * @return int El valor máximo de los tres enteros proporcionados.
 */
int max(int a, int b, int c)
{
  // Usamos puros operadores ternarios porque no le tenemos miedo a nada.
  return (a > b ? (a > c ? a : c) : (b > c ? b : c));
}

/**
 * @brief Encuentra el máximo valor por fila para la matriz utilizando programación dinámica con una
 * tabla de memoización con los valores previamente calculados para filas anteriores.
 *
 * @param i La fila de la matriz.
 * @param j La columna de la matriz.
 * @param n El número de filas en la matriz.
 * @param m El número de columnas en la matriz.
 * @return int El valor máximo de piedras filosofales disponibles para la fila i.
 */
int recorrido(int i, int j, int n, int m)
{
  // Caso base para la recursión.
  if (j < 0 || i >= n || j >= m || i < 0)
  {
    // Si la posición es inválida, retornamos 0.
    return 0;
  }

  // Si ya se ha calculado el valor, lo retornamos.
  if (tabla_memoizacion[i][j])
  {
    return tabla_memoizacion[i][j];
  }

  // Calculamos el valor de memoización para la posición, el cual será el máximo entre:
  //   - El valor en la esquina superior derecha.
  //   - El valor en la esquina superior izquierda.
  //   - El valor en la esquina inferior derecha.
  int temp = (matriz[i][j] + max(recorrido(i + 1, j - 1, n, m), recorrido(i + 1, j, n, m), recorrido(i + 1, j + 1, n, m)));
  tabla_memoizacion[i][j] = temp;
  return temp;
}