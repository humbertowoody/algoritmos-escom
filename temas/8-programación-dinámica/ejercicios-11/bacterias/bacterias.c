/**
 * @file bacterias.c
 * @author Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)
 * @brief Solución al problema de Bacterias en OmegaUp
 * @version 0.1
 * @date 2022-05-28
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

// Constanes de ejecución.
#define VALOR_MAXIMO_M 102
#define VALOR_MAXIMO_N 102
#define VALOR_INVALIDO -1
#define ENTERO_ENORME 999999

// Variables globales.
int matriz[VALOR_MAXIMO_M][VALOR_MAXIMO_N],      // Matriz original.
    memoizacion[VALOR_MAXIMO_M][VALOR_MAXIMO_N], // Matriz de memoización.
    m,                                           // Dimensión m de las matrices.
    n;                                           // Dimensión n de las matrices.

/**
 * @brief Realiza el recorrido de la colonia de bacterias a través de la matriz.
 *
 * @param i La coordenada de la fila.
 * @param j La coordenada de la columna.
 * @return int El valor c del recorrido de la colonia de bacterias.
 */
int recorrido(int i, int j);

/**
 * @brief Función que retorna el mínimo de dos enteros.
 *
 * @param a Primer entero.
 * @param b Segundo entero.
 * @return int El entero menor.
 */
int min(int a, int b) { return a < b ? a : b; }

// Función principal.
int main()
{
  // Leemos las dimensiones de las matrices.
  scanf("%i %i", &m, &n);

  // Leemos la matriz original.
  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      // Leemos el valor de la matriz.
      scanf("%i", &matriz[i][j]);

      // Inicializamos la matriz de memoización.
      memoizacion[i][j] = VALOR_INVALIDO;
    }
  }

  // Realizamos la búsqueda partiendo de la posición (1,1).
  printf("%i\n", recorrido(1, 1));

  // Finalizamos la ejecución.
  return 0;
}

/**
 * @brief Realiza el recorrido de la colonia de bacterias a través de la matriz.
 *
 * @param i La coordenada de la fila.
 * @param j La coordenada de la columna.
 * @return int El valor c del recorrido de la colonia de bacterias.
 */
int recorrido(int i, int j)
{
  if (i == m && j == n)
  {
    // Si nos encontramos en la posición destino (m,n), retornamos el valor de la matriz.
    return matriz[i][j];
  }

  if (i > n || j > n)
  {
    // Si nos encontramos en una posición fuera de la matriz, retornamos 0.
    return ENTERO_ENORME;
  }

  if (memoizacion[i][j] == VALOR_INVALIDO)
  {
    // Si no se ha calculado el valor de la matriz de memoizacion, lo calcularemos,
    // siendo el resultado el valor mínimo entre el valor del recorrido desplazándonos a
    // la siguiente fila y el valor del recorrido desplazándonos a la siguiente columna, a
    // esto sumamos el valor en la posición actual de la matriz original.
    memoizacion[i][j] = min(recorrido(i + 1, j), recorrido(i, j + 1)) + matriz[i][j];
  }

  // Retornamos el valor de la matriz de memoización.
  return memoizacion[i][j];
}
