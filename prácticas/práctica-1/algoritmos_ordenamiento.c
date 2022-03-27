/**
 * @file algoritmos_ordenamiento.c
 * @author Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)
 * @brief Programa que ordena n números usando el algoritmo especificado. 
 * @version 0.1
 * @date 2022-03-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "librerias/ordenamientos.h"
#include "librerias/tiempo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Arreglo constante con los nombres de los algoritmos.
const char * const ALGORITMO_STR[] =
{
  [BURBUJA_SIMPLE] = "burbuja_simple",
  [BURBUJA_OPTIMIZADA_1] = "burbuja_optimizada_1",
  [BURBUJA_OPTIMIZADA_2] = "burbuja_optimizada_2",
  [INSERCION] = "insercion",
  [SELECCION] = "seleccion",
  [SHELL] = "shell",
  [TREE] = "tree",
  [MERGE] = "merge",
  [QUICK] = "quick",
  [HEAP] = "heap"
};

// Prototipos de funciones.
void mostrar_uso(char*); 
int id_algoritmo_por_nombre(char*);

// Función principal.
int main(int argc, char *argv[])
{
  // Variables locales.
  medicion_tiempo inicio, fin; // Estructuras para medir los tiempos de ejecución.
  resultados_tiempo resultados; // Estructura para almacenar los resultados de ejecución.
  int n,        // El número de números a ordenar.
      *arreglo; // El arreglo con los números a ordenar.
  ALGORITMO_ORDENAMIENTO algoritmo; // El algoritmo de ordenamiento a usar.

  // Validamos el número de argumentos proporcionados.
  if (argc != 3)
  {
    mostrar_uso(argv[0]);
    return EXIT_FAILURE;
  }

  // Obtenemos los valores proporcionados por el usuario.
  algoritmo = id_algoritmo_por_nombre(argv[1]);
  n = atoi(argv[2]);

  // Validamos los valores proporcionados.
  if (algoritmo == -1 || n < 1)
  {
    printf("Error: uno de los argumentos proporcionados es inválido.\n\n");
    mostrar_uso(argv[0]);
    return EXIT_FAILURE;
  }

  // Creamos el arreglo del tamaño solicitado.
  arreglo = (int*) malloc(sizeof(int) * n);

  // Leemos los valores de entrada.
  for (int i = 0; i < n; i++)
  {
    scanf("%i", arreglo + i);
  }
  
  // Tomamos la medida de tiempo inicial.
  guardar_tiempo(&inicio);

  // Ejecutamos el algoritmo correspondiente.
  switch(algoritmo)
  {
    case BURBUJA_SIMPLE:
      ordenar_burbuja_simple(arreglo,n);
      break;

    case BURBUJA_OPTIMIZADA_1:
      ordenar_burbuja_optimizada_1(arreglo,n);
      break;

    case BURBUJA_OPTIMIZADA_2:
      ordenar_burbuja_optimizada_2(arreglo,n);
      break;

    case INSERCION:
      ordenar_insercion(arreglo,n);
      break;

    case SELECCION:
      ordenar_seleccion(arreglo,n);
      break;

    case SHELL:
      ordenar_shell(arreglo,n);
      break;

    case TREE:
      ordenar_tree(arreglo,n);
      break;

    case MERGE:
      ordenar_merge(arreglo,0,n);
      break;

    case QUICK:
      ordenar_quick(arreglo,n);
      break;

    case HEAP:
    default:
      ordenar_heap(arreglo,n);
      break;
  }

  // Tomamos la medida del tiempo final.
  guardar_tiempo(&fin);

  // Calculamos los resultados.
  resultados = calcular_resultados(inicio,fin);

  // Imprimimos los resultados en formato CSV.
  printf("%s,%i,%.10f,%.10f,%.10f,%.10f\n",ALGORITMO_STR[algoritmo],n,resultados.real,resultados.user,resultados.sys,resultados.cpu_wall);

  return EXIT_SUCCESS;
}

/**
 * @brief Función para mostrar el uso del programa.
 *
 * @param ejecutable El nombre del ejecutable de este programa.
 */
void mostrar_uso(char *nombre_ejecutable)
{
  printf("Uso: %s <nombre de algoritmo> <cantidad de números>\n", nombre_ejecutable);
  printf("\n");
  printf("Algoritmos disponibles:\n");
  for(ALGORITMO_ORDENAMIENTO alg = BURBUJA_SIMPLE; alg <= HEAP; alg++)
  {
    printf("\t- %s\n",ALGORITMO_STR[alg]);
  }
  printf("\n");
}

/**
 * @brief Función que regresa el ID del enum de algoritmos de ordenamiento a partir
 *        del nombre del algoritmo proporcionado por el usuario.
 *
 * @param nombre El string con el nombre del algoritmo.
 */
int id_algoritmo_por_nombre(char *nombre)
{
  // Buscamos en todos los strings.
  for (int i = BURBUJA_SIMPLE; i <= HEAP; i++)
  {
    // Validamos si los strings son iguales.
    if (strcmp(ALGORITMO_STR[i], nombre) == 0)
    {
      // Si lo encontramos, regresamos el ID correspondiente.
      return i;
    }
  }

  // Si no se encontró nada, regresamos inválido (-1).
  return -1;
}

