/**
 * @file test_ordenamientos.c
 * @author Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)
 * @brief Test de los algoritmos de ordenamientos para verificar si funcionan,
 *        algunos de los algoritmos "fallan" porque, por la naturaleza del
 *        mismo, se eliminan los elementos duplicados y marca error.
 * @version 0.1
 * @date 2022-03-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "librerias/ordenamientos.h"
#include "librerias/genera_casos.h"
#include "librerias/arreglo.h"
#include <stdio.h>
#include <stdlib.h>

// Constante con el número de elementos para las pruebas.
#define NUM_ELEMENTOS 10000

// Función principal.
int main(void)
{
  // Variables locales.
  int *desordenados = genera_arreglo_enteros_aleatorios(NUM_ELEMENTOS, 0, NUM_ELEMENTOS + 1),
      *ordenados_ref = crear_arreglo(NUM_ELEMENTOS),
      *ordenados = crear_arreglo(NUM_ELEMENTOS);

  // Hacemos copias de los elementos aleatorios generados al inicio.
  copiar_arreglo(desordenados, ordenados_ref, NUM_ELEMENTOS);

  // Hacemos un ordenamiento de referencia.
  ordenar_quick(ordenados_ref, NUM_ELEMENTOS);

  // Mensaje de inicio con parámetros de configuración.
  printf("Prueba de algoritmos de ordenamiento.\n");
  printf("Configuración:\n");
  printf("\t - Tamaño de los arreglos: %i\n", NUM_ELEMENTOS);
  printf("Pruebas:\n");


  // Iteramos sobre los algoritmos.
  for(ALGORITMO_ORDENAMIENTO alg = BURBUJA_SIMPLE; alg <= HEAP; alg++)
  {
    // Generamos datos.
    copiar_arreglo(desordenados, ordenados, NUM_ELEMENTOS);

    // Formato
    printf("\t- ");

    // Elegimos un algoritmo de ordenamiento.
    switch(alg)
    {
      case BURBUJA_SIMPLE:
        printf("Burbuja Simple: ");
        ordenar_burbuja_simple(ordenados, NUM_ELEMENTOS);
        break;

      case BURBUJA_OPTIMIZADA_1:
          printf("Burbuja Optimizada 1: ");
        ordenar_burbuja_optimizada_1(ordenados, NUM_ELEMENTOS);
        break;

      case BURBUJA_OPTIMIZADA_2:
        printf("Burbuja Optimizada 2: ");
        ordenar_burbuja_optimizada_2(ordenados, NUM_ELEMENTOS);
        break;

      case INSERCION:
        printf("Inserción: ");
        ordenar_insercion(ordenados, NUM_ELEMENTOS);
        break;

      case SELECCION:
        printf("Selección: ");
        ordenar_seleccion(ordenados, NUM_ELEMENTOS);
        break;

      case SHELL:
        printf("Shell: ");
        ordenar_shell(ordenados, NUM_ELEMENTOS);
        break;

      case TREE:
        printf("Tree: ");
        ordenar_tree(ordenados, NUM_ELEMENTOS);
        break;

      case MERGE:
        printf("Merge: ");
        ordenar_merge(ordenados, 0, NUM_ELEMENTOS);
        break;

      case HEAP:
        printf("Heap: ");
        ordenar_heap(ordenados, NUM_ELEMENTOS);
        break;

      case QUICK:
      default:
        printf("Quick: ");
        ordenar_quick(ordenados, NUM_ELEMENTOS);
        break;
    }

    // Comparación.
    printf("%s\n", arreglos_iguales(ordenados, ordenados_ref, NUM_ELEMENTOS) == 1 ? "✅" : "❌");
  }

  return EXIT_SUCCESS;
}

