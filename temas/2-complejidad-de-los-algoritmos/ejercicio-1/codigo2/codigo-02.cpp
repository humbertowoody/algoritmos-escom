/**
 * ESCOM - IPN
 * Análisis de Algoritmos
 * Tema 2 - Ejercicio 1 - Código 2
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
  int i, j,
      contador = 0,
      modelo,
      n;

  // Obtenemos la "n" de argumento del programa.
  n = atoi(argv[1]);

  // Calculamos el modelo matemático.
  modelo = int(((floor(log2(n) - log2(1))) * (n / 2)) - 1);

  // Algoritmo.
  for (j = n; j > 1; j /= 2)
  {
    if (j < (n / 2))
    {
      for (i = 0; i < n; i += 2)
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
