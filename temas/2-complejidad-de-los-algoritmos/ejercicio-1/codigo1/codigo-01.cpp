/**
 * ESCOM - IPN
 * Análisis de Algoritmos
 * Tema 2 - Ejercicio 1 - Código 1
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
  int i,
      contador = 0,
      modelo,
      n;

  // Obtenemos la "n" de argumento del programa.
  n = atoi(argv[1]);

  // Calculamos el modelo matemático.
  modelo = int(floor(log2(5 * n) - log2(10))) + 1;

  // Algoritmo.
  for (i = 10; i <= n * 5; i *= 2)
  {
    contador++;
  }

  // Imprimir resultados
  printf("%i,%i,%i\n", n, contador, modelo);

  // Fin de ejecución.
  return 0;
}
