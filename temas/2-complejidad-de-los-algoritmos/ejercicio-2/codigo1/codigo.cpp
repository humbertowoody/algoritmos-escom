/**
 * ESCOM - IPN
 * Análisis de Algoritmos
 * Tema 2 - Ejercicio 2 - Código 1
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
  int contador,
      ft, fc, // tiempo + complejidad
      n, i, j;

  // Obtenemos la "n" de argumento del programa.
  n = atoi(argv[1]);

  // Calculamos el modelo matemático.
  ft = (int)(((3 * n) + 4) * ((3 * powf(2, n)) + 9));
  fc = (int)(n + 3);

  /**
   * Para el análisis del algoritmo, usamos el contador para definir las operaciones
   * que se realizan en cada iteración de cada elemento del algoritmo.
   */
  contador = 1; // asignación inicial primer ciclo. i=1
  for (i = 1; i < n; i++)
  {
    contador++; // comparación de primer ciclo. i<n

    contador++; // asignacion j=n;
    for (j = n; j > 1; j /= 2)
    {
      contador++;    // comparación de segundo ciclo. j>1
      contador += 5; // Número de instrucciones realizadas en cada iteración del ciclo 2.
      contador += 2; // decremento en j segundo ciclo (asignación + aritmética) j = j/2
    }
    contador++; // comparación final ciclo 2. j>1

    contador += 2; // incremento en i primer ciclo (asignación + aritmética). i = i+1
  }
  contador++; // comparación final ciclo 1. i<n

  // Imprimir resultados
  printf("%i,%i,%i,%i\n", n, contador, ft, fc);

  // Fin de ejecución.
  return 0;
}
