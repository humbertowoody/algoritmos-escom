/**
 * @file test_busquedas.c
 * @author Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)
 * @brief Pruebas para los algoritmos de búsquedas.
 * @version 0.1
 * @date 2022-04-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "librerias/busquedas.h"
#include "librerias/ordenamientos.h"
#include "librerias/genera_casos.h"
#include "librerias/arreglo.h"
#include "librerias/nodo_arbol.h"
#include <stdio.h>
#include <stdlib.h>

// Constante con el número de elementos default para las pruebas.
#define NUM_ELEMENTOS_DEFAULT 30000

// Prototipos de funciones.
int prueba_busqueda_lineal(int *, int, int);
// int prueba_busqueda_lineal_p(int*,int);
int prueba_busqueda_abb(int *, int, int);
// int prueba_busqueda_abb_p(int*,int);
int prueba_busqueda_binaria(int *, int, int);
// int prueba_busqueda_binaria_p(int*, int, int);
int prueba_busqueda_exponencial(int *, int, int);
// int prueba_busqueda_exponencial_p(int*, int, int);
int prueba_busqueda_fibonacci(int *, int, int);
// int prueba_busqueda_fibonacci_p(int*, int, int);

// Función principal
int main(int argc, char *argv[])
{
  // Generamos la variable con el número de elementos.
  int NUM_ELEMENTOS = NUM_ELEMENTOS_DEFAULT;

  // Vemos si existe el argumento de valores.
  if (argc == 2)
  {
    NUM_ELEMENTOS = atoi(argv[1]);
  }

  // Lo primero es aleatorizar la semilla para que sean números semi-aleatorios.
  aleatorizar_semilla();

  // Variables locales.
  int *desordenados = genera_arreglo_enteros_aleatorios(NUM_ELEMENTOS, 0, NUM_ELEMENTOS + 1),
      *ordenados = crear_arreglo(NUM_ELEMENTOS),
      elemento_esperado = desordenados[NUM_ELEMENTOS - 3];

  // Creamos el arreglo de números ordenados.
  copiar_arreglo(desordenados, ordenados, NUM_ELEMENTOS);

  // Ordenamos el arreglo de números ordenados.
  ordenar_quick(ordenados, NUM_ELEMENTOS);

  // Mensaje de inicio con parámetros de configuración.
  printf("Prueba de algoritmos de búsqueda.\n");
  printf("Configuración:\n");
  printf("\t- Tamaño de los arreglos: %i\n", NUM_ELEMENTOS);
  printf("Pruebas:\n");

  // Algoritmos que no requieren que los elementos estén ordenados.
  printf("\t- Búsqueda Lineal: %s\n", prueba_busqueda_lineal(desordenados, NUM_ELEMENTOS, elemento_esperado) ? "✅" : "❌");
  // printf("\t- Búsqueda Lineal (paralelizada): %s\n", prueba_busqueda_lineal_p(desordenados, NUM_ELEMENTOS, elemento_esperado) ? "✅" : "❌");
  printf("\t- Búsqueda en ABB: %s\n", prueba_busqueda_abb(desordenados, NUM_ELEMENTOS, elemento_esperado) ? "✅" : "❌");
  // printf("\t- Búsqueda en ABB (paralelizada): %s\n", prueba_busqueda_abb_p(desordenados, NUM_ELEMENTOS, elemento_esperado) ? "✅" : "❌");

  // Algoritmos que requieren que los elementos estén ordenados.
  printf("\t- Búsqueda Binaria: %s\n", prueba_busqueda_binaria(ordenados, NUM_ELEMENTOS, elemento_esperado) ? "✅" : "❌");
  // printf("\t- Búsqueda Binaria (paralelizada): %s\n", prueba_busqueda_binaria_p(ordenados, NUM_ELEMENTOS, elemento_esperado) ? "✅" : "❌");
  printf("\t- Búsqueda Exponencial: %s\n", prueba_busqueda_exponencial(ordenados, NUM_ELEMENTOS, elemento_esperado) ? "✅" : "❌");
  // printf("\t- Búsqueda Exponencial (paralelizada): %s\n", prueba_busqueda_exponencial_p(ordenados, NUM_ELEMENTOS, elemento_esperado) ? "✅" : "❌");
  printf("\t- Búsqueda Fibonacci: %s\n", prueba_busqueda_fibonacci(ordenados, NUM_ELEMENTOS, elemento_esperado) ? "✅" : "❌");
  // printf("\t- Búsqueda Fibonacci (paralelizada): %s\n", prueba_busqueda_fibonacci_p(ordenados, NUM_ELEMENTOS, elemento_esperado) ? "✅" : "❌");

  // Fin de ejecución de pruebas.
  return EXIT_SUCCESS;
}

/**
 * @brief Realiza la prueba del algoritmo de búsqueda lineal.
 *
 * @param arreglo El arreglo con números desordenados para relaizar la búsqueda.
 * @param tamanio El tamaño del arreglo para realizar la búsqueda.
 * @param elemento El elemento a buscar.
 * @return int 1 si funciona, 0 si no funciona.
 */
int prueba_busqueda_lineal(int *arreglo, int tamanio, int elemento)
{
  // Variables locales.
  int resultado_temp;

  // Realizamos la búsqueda.
  resultado_temp = busqueda_lineal_i(arreglo, tamanio, elemento);

  // Comparamos neustro resultado obtenido.
  return resultado_temp >= 0 && arreglo[resultado_temp] == elemento;
}

/**
 * @brief Realiza la prueba del algoritmo de búsqueda en un ABB.
 *
 * @param arreglo El arreglo con números desordenados para realizar la búsqueda.
 * @param tamanio El tamaño del arreglo para realizar la búsqueda.
 * @param elemento El elemento a buscar.
 * @return int 1 si funciona, 0 si no funciona.
 */
int prueba_busqueda_abb(int *arreglo, int tamanio, int elemento)
{
  // Variables locales.
  nodo_arbol *raiz = NULL,
             *res;

  // Insertamos los elementos en nuestro ABB.
  for (int i = 0; i < tamanio; i++)
  {
    raiz = insertar_en_arbol(raiz, arreglo[i]);
  }

  // Ejecutamos el algoritmo.
  res = busqueda_abb_i(raiz, elemento);

  // Comparamos nuestro resultado obtenido.
  return res != NULL && res->dato == elemento;
}

/**
 * @brief Realiza la prueba del algoritmo de búsqueda binaria.
 *
 * @param arreglo El arreglo con números ordenados para realizar la búsqueda.
 * @param tamanio El tamaño del arreglo para realizar la búsqueda.
 * @param elemento El elemento a buscar.
 * @return int 1 si funciona, 0 si no funciona.
 */
int prueba_busqueda_binaria(int *arreglo, int tamanio, int elemento)
{
  // Variables locales.
  int resultado_temp;

  // Realizamos la búsqueda (asumimos que el arreglo está ordenado).
  resultado_temp = busqueda_binaria_i(arreglo, 0, tamanio, elemento);

  // Comparamos nuestro resultado obtenido.
  return resultado_temp >= 0 && arreglo[resultado_temp] == elemento;
}

/**
 * @brief Realiza la prueba del algoritmo de búsqueda exponencial.
 *
 * @param arreglo El arreglo con números ordenados para realizar la búsqueda.
 * @param tamanio El tamaño del arreglo para realizar la búsqueda.
 * @param elemento El elemento a buscar.
 * @return int 1 si funciona, 0 si no funciona.
 */
int prueba_busqueda_exponencial(int *arreglo, int tamanio, int elemento)
{
  // Variables locales.
  int resultado_temp;

  // Realizamos la búsqueda (asumimos que el arreglo está ordenado).
  resultado_temp = busqueda_exponencial_i(arreglo, tamanio, elemento);

  // Comparamos nuestro resultado obtenido.
  return resultado_temp >= 0 && arreglo[resultado_temp] == elemento;
}

/**
 * @brief Realiza la prueba del algoritmo de búsqueda fibonacci.
 *
 * @param arreglo El arreglo con números ordenados para realizar la búsqueda.
 * @param tamanio El tamaño del arreglo para realizar la búsqueda.
 * @param elemento El elemento a buscar.
 * @return int 1 si funciona, 0 si no funciona.
 */
int prueba_busqueda_fibonacci(int *arreglo, int tamanio, int elemento)
{
  // Variables locales.
  int resultado_temp;

  // Realizamos la búsqueda (asumimos que el arreglo está ordenado).
  resultado_temp = busqueda_fibonacci_i(arreglo, tamanio, elemento);

  // Comparamos nuestro resultado obtenido.
  return resultado_temp >= 0 && arreglo[resultado_temp] == elemento;
}
