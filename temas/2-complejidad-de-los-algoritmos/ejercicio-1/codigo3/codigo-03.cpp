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
  modelo = int(((5 * n) / 2) * ((2 * n) * (n - (2 * n))));

  // Algoritmo.
  for (i = 0; i < n * 5; i += 2)
  {
    for (j = 0; j < 2 * n; j++)
    {
      for (k = j; j < n; j++)
      {
        contador++;
      }
    }
  }

  // Imprimir resultados
  printf("%i,%i,%i\n", n, contador, modelo);

  // Fin de ejecución.
  return 0;
}
