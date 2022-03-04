/**
 * ESCOM - IPN
 * Análisis de Algoritmos
 * Tema 2 - Ejercicio 1 - Código 3
 * Humberto Alejandro Ortega Alcocer (2016630495)
 * 3/Marzo/2022
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Función principal
int main(int argc, char *argv[])
{
  // Variables locales.
  int i, j, k,
      contador = 0,
      modelo,
      n;

  // Obtenemos la "n" de argumento del programa.
  n = atoi(argv[1]);

  // Calculamos el modelo matemático.
  modelo = 0;
  for (int it = 0; it < 4 * n; it++)
  {
    modelo += (int)(((5 * n) - floor(log2(4 * n) - log2(it))) / 3);
  }

  // Algoritmo.
  for (i = 1; i < 4 * n; i *= 2)
  {
    for (j = i; j < 5 * n; j += 3)
    {
      contador++;
    }
  }

  // Imprimir resultados
  printf("%i,%i,%i\n", n, contador, modelo);

  // Fin de ejecución.
  return 0;
}
