/**
 * @file lcs.c
 * @author Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)
 * @brief Solución al problema de LCS en OmegaUp.
 * @version 0.1
 * @date 2022-05-28
 *
 * @copyright Copyright (c) 2022
 */
#include <stdio.h>
#include <string.h> // Para obtener la longitud de las cadenas.

// Constantes de ejecución.
#define LONGITUD_MAXIMA_CADENA 10000

/**
 * LCS - Algoritmo que calcula la subsecuencia de cadenas más larga entre
 * dos cadenas de entrada.
 * @param A la primer cadena.
 * @param m longitud de la cadena A.
 * @param B la segunda cadena.
 * @param n longitud de la cadena B.
 * @return Un entero con la subsecuencia más larga para A y B.
 */
int lcs(char *A, int m, char *B, int n);

// Función principal.
int main()
{
  // Variables locales.
  char cadenaA[LONGITUD_MAXIMA_CADENA], // Para almacenar la cadena A.
      cadenaB[LONGITUD_MAXIMA_CADENA];  // Para almacenar la cadena B.

  // Leemos ambas cadenas.
  scanf("%s\n%s", cadenaA, cadenaB);

  // Llamamos a la función LCS calculando la longitud de las cadenas e imprimimos el resultado.
  printf("%i\n", lcs(cadenaA, strlen(cadenaA), cadenaB, strlen(cadenaB)));

  // Finalizamos la ejecución.
  return 0;
}

/**
 * LCS - Algoritmo que calcula la subsecuencia de cadenas más larga entre
 * dos cadenas de entrada.
 * @param A la primer cadena.
 * @param m longitud de la cadena A.
 * @param B la segunda cadena.
 * @param n longitud de la cadena B.
 * @return Un entero con la subsecuencia más larga para A y B.
 */
int lcs(char *A, int m, char *B, int n)
{
  // Variables locales.
  int memoizacion[m + 1][n + 1]; // La tabla de memoización para el algoritmo.

  // Iteramos sobre las dimensiones de las cadenas proporcionadas.
  for (int i = 0; i <= m; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      if (i == 0 || j == 0)
      {
        // Si es cero alguno de los valores, la memoización en (i,j) será 0.
        memoizacion[i][j] = 0;
      }
      else if (A[i - 1] == B[j - 1])
      {
        // Si no es 0 y son iguales las cadenas en A(i-1) y B(j-1), entonces
        // el valor para la memoización será el resultado de la esquina superior
        // derecha más uno.
        memoizacion[i][j] = memoizacion[i - 1][j - 1] + 1;
      }
      else
      {
        // En otro caso, almacenamos en (i,j) el máximo entre (i-1,j) y (i, j-1).
        memoizacion[i][j] = memoizacion[i - 1][j] > memoizacion[i][j - 1] ? memoizacion[i - 1][j] : memoizacion[i][j - 1];
      }
    }
  }

  // La tabla de memoización, en la posición (m,n) contiene el resultado de LCS.
  return memoizacion[m][n];
}
