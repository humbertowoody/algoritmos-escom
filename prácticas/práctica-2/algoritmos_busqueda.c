/**
 * @file algoritmos_busquedas.c
 * @author Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)
 * @brief Programa que busca un número en un arreglo de números utilizando el algoritmo especificado.
 * @version 0.1
 * @date 2022-04-08
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "librerias/busquedas.h"
#include "librerias/arreglo.h"
#include "librerias/tiempo.h"
#include "librerias/ordenamientos.h"
#include "librerias/nodo_arbol.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Arreglo constante con los nombres de los algoritmos.
const char *const ALGORITMO_STR[] =
    {
        [LINEAL] = "lineal",
        [LINEAL_P] = "lineal_p",
        [ABB] = "abb",
        [ABB_P] = "abb_p",
        [BINARIA] = "binaria",
        [BINARIA_P] = "binaria_p",
        [EXPONENCIAL] = "exponencial",
        [EXPONENCIAL_P] = "exponencial_p",
        [FIBONACCI] = "fibonacci",
        [FIBONACCI_P] = "fibonacci_p"};

// Prototipos de funciones.
void mostrar_uso(char *);
ALGORITMO_BUSQUEDA id_algoritmo_por_nombre(char *);

// Función principal.
int main(int argc, char *argv[])
{
  // Variables locales.
  medicion_tiempo inicio, fin;  // Estructuras para medir los tiempos de ejecución.
  resultados_tiempo resultados; // Estructura para almacenar los resultados de tiempos de ejecución.
  int numero_elementos,         // El número de elementos a leer.
      *elementos,               // El arreglo con los elementos leídos.
      elemento_busqueda;        // El elemento a buscar en el arreglo.
  ALGORITMO_BUSQUEDA algoritmo; // El algoritmo a utilizar.
  nodo_arbol *raiz = NULL;      // En caso de que se use ABB.

  // Validamos el número de argumentos proporcionados al programa.
  if (argc != 4)
  {
    mostrar_uso(argv[0]);
    return EXIT_FAILURE;
  }

  // Obtenemos los valores proporcionados por el usuario.
  algoritmo = id_algoritmo_por_nombre(argv[1]);
  numero_elementos = atoi(argv[2]);
  elemento_busqueda = atoi(argv[3]);

  // Validamos los valores proporcionados.
  if (algoritmo < LINEAL || numero_elementos < 1)
  {
    printf("Error: uno de los argumentos proporcionados es inválido.\n\n");
    mostrar_uso(argv[0]);
    return EXIT_FAILURE;
  }

  // Creamos el arreglo del tamaño solicitado.
  elementos = crear_arreglo(numero_elementos);

  // Leemos los valores de entrada.
  for (int i = 0; i < numero_elementos; i++)
  {
    scanf("%i", elementos + i);
  }

  // Si el algoritmo que vamos a usar requiere los datos ordenados, los ordenamos.
  if (algoritmo != LINEAL && algoritmo != LINEAL_P && algoritmo != ABB && algoritmo != ABB_P)
  {
    ordenar_quick(elementos, numero_elementos);
  }

  // Si el algoritmo que vamos a usar es ABB, armamos el ABB en cuestión.
  if (algoritmo == ABB || algoritmo == ABB_P)
  {
    // Insertamos cada elemento del arreglo en el ABB.
    for (int i = 0; i < numero_elementos; i++)
    {
      raiz = insertar_en_arbol(raiz, elementos[i]);
    }
  }

  // Tomamos la medida del tiempo inicial.
  guardar_tiempo(&inicio);

  // Ejecutamos el algoritmo correspondiente.
  switch (algoritmo)
  {
  case LINEAL:
    busqueda_lineal_i(elementos, numero_elementos, elemento_busqueda);
    break;

  case LINEAL_P:
    busqueda_lineal_i_p(elementos, numero_elementos, elemento_busqueda);
    break;

  case ABB:
    busqueda_abb_i(raiz, elemento_busqueda);
    break;

  case ABB_P:
    // busqueda_abb_i_p(raiz, elemento_busqueda);
    break;

  case BINARIA:
    busqueda_binaria_i(elementos, 0, numero_elementos, elemento_busqueda);
    break;

  case BINARIA_P:
    busqueda_binaria_i_p(elementos, 0, numero_elementos, elemento_busqueda);
    break;

  case EXPONENCIAL:
    busqueda_exponencial_i(elementos, numero_elementos, elemento_busqueda);
    break;

  case EXPONENCIAL_P:
    busqueda_exponencial_i_p(elementos, numero_elementos, elemento_busqueda);
    break;

  case FIBONACCI:
    busqueda_fibonacci_i(elementos, numero_elementos, elemento_busqueda);
    break;

  case FIBONACCI_P:
  default:
    busqueda_fibonacci_i_p(elementos, numero_elementos, elemento_busqueda);
    break;
  }

  // Tomamos la medida del tiempo final.
  guardar_tiempo(&fin);

  // Calculamos los resultados.
  resultados = calcular_resultados(inicio, fin);

  // Imprimimos los resultados en formato CSV.
  // nombre_algoritmo, n, elemento, tiempo_real, tiempo_usuario, tiempo_sistema, tiempo_cpu_wall
  printf("%s,%i,%i,%.10f,%.10f,%.10f,%.10f\n", ALGORITMO_STR[algoritmo], numero_elementos, elemento_busqueda, resultados.real, resultados.user, resultados.sys, resultados.cpu_wall);

  // Fin de programa.
  return EXIT_SUCCESS;
}

/**
 * @brief Función para mostrar el uso del programa.
 *
 * @param ejecutable El nombre del ejecutable de este programa.
 */
void mostrar_uso(char *nombre_ejecutable)
{
  printf("Uso: %s <nombre de algoritmo> <cantidad de números> <número a buscar>\n", nombre_ejecutable);
  printf("\n");
  printf("Algoritmos disponibles:\n");
  for (ALGORITMO_BUSQUEDA alg = LINEAL; alg <= FIBONACCI_P; alg++)
  {
    printf("\t- %s\n", ALGORITMO_STR[alg]);
  }
  printf("\n");
}

/**
 * @brief Función que regresa el ID del enum de algoritmos de ordenamiento a partir
 *        del nombre del algoritmo proporcionado por el usuario.
 *
 * @param nombre El string con el nombre del algoritmo.
 */
ALGORITMO_BUSQUEDA id_algoritmo_por_nombre(char *nombre)
{
  // Buscamos en todos los strings.
  for (ALGORITMO_BUSQUEDA i = LINEAL; i <= FIBONACCI_P; i++)
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
