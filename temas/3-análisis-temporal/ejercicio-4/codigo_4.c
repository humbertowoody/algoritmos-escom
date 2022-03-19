/**
 * @file codigo_1.c
 * @author Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)
 * @brief Ejercicio 4, Código 4: Simulación de mejor, peor y caso medio.
 * @version 0.1
 * @date 2022-03-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "librerias/cont_operaciones.h"
#include "librerias/genera_casos.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definición de constante para el número de casos de prueba.
#ifndef NUM_PRUEBAS
#define NUM_PRUEBAS 10
#endif

// Definición de constante para el tamaño del problema.
#ifndef NUM_ELEMENTOS
#define NUM_ELEMENTOS 5000
#endif

// Prototipos de funciones.
int algoritmo(int *, int, cont_operaciones *);
int modelo_mejor_caso(int);
int modelo_peor_caso(int);
int modelo_caso_medio(int);

int main(void)
{
  // Variables locales.
  cont_operaciones operaciones;

  // Aleatorizamos la semilla.
  aleatorizar_semilla();

  // Imprimimos la cabecera CSV.
  printf("caso,iteración,n,ops_asignacion,ops_comparacion,ops_aritmética,ops_totales,modelo_matemático\n");

  // Mejor caso
  // Cuando el arreglo está ordenado ascendentemente.
  for (int i = 0; i < NUM_PRUEBAS; i++)
  {
    int *arreglo = genera_arreglo_enteros_ordenados(NUM_ELEMENTOS);

    inicializa_cont_operaciones(&operaciones);

    algoritmo(arreglo, NUM_ELEMENTOS, &operaciones);

    // Imprimmos la fila CSV.
    printf("mejor_caso,%d,%d,%d,%d,%d,%d,%d\n", i, NUM_ELEMENTOS, operaciones.asignaciones, operaciones.comparaciones, operaciones.aritmeticas, total_operaciones(operaciones), modelo_mejor_caso(NUM_ELEMENTOS));

    free(arreglo);
  }

  // Peor caso
  // Cuando el arreglo cuenta con los números repetidos en el mismo orden.
  for (int i = 0; i < NUM_PRUEBAS; i++)
  {
    int *arreglo = genera_arreglo_enteros_ordenados_esp1(NUM_ELEMENTOS);
    inicializa_cont_operaciones(&operaciones);
    algoritmo(arreglo, NUM_ELEMENTOS, &operaciones);
    // Imprimmos la fila CSV.
    printf("peor_caso,%d,%d,%d,%d,%d,%d,%d\n", i, NUM_ELEMENTOS, operaciones.asignaciones, operaciones.comparaciones, operaciones.aritmeticas, total_operaciones(operaciones), modelo_peor_caso(NUM_ELEMENTOS));
    free(arreglo);
  }

  // Caso medio.
  // Cuando los números están aleatorizados dentro del arreglo.
  for (int i = 0; i < NUM_PRUEBAS; i++)
  {
    int *arreglo = genera_arreglo_enteros_aleatorios(NUM_ELEMENTOS, 0, NUM_ELEMENTOS);
    inicializa_cont_operaciones(&operaciones);
    algoritmo(arreglo, NUM_ELEMENTOS, &operaciones);
    // Imprimmos la fila CSV.
    printf("caso_medio,%d,%d,%d,%d,%d,%d,%d\n", i, NUM_ELEMENTOS, operaciones.asignaciones, operaciones.comparaciones, operaciones.aritmeticas, total_operaciones(operaciones), modelo_caso_medio(NUM_ELEMENTOS));
    free(arreglo);
  }

  return 0;
}

/**
 * @brief Implementación de algoritmo: "Frecuencia Mínima de Números"
 *
 * @param arreglo Arreglo de enteros.
 * @param tamano_arreglo El tamaño del arreglo.
 * @param operaciones Apuntador para contar las operaciones realizadas.
 * @return int El resultado del algoritmo.
 */
int algoritmo(int *arreglo, int tamano_arreglo, cont_operaciones *operaciones)
{
  // Declaración de variables.
  int i, j, f = 0, num;

  // Implementación del algoritmo.

  for (i = 0; i < tamano_arreglo; i++)
  {
    int ntemp = arreglo[i];
    int ftemp = 0;

    for (j = 0; j < tamano_arreglo; j++)
    {
      if (ntemp == arreglo[j])
      {
        ftemp++;
        operaciones->aritmeticas++; // El incremento de ftemp.
      }
      operaciones->comparaciones++; // La comparación del if.
    }

    if (f < ftemp)
    {
      f = ftemp;
      num = ntemp;
      operaciones->asignaciones += 2; // Las asignaciones.
    }
    operaciones->comparaciones++; // La comparación del if.
  }

  return f + num;
}

/**
 * @brief Implementación del modelo del mejor caso.
 *
 * @return int El resultado del modelo.
 */
int modelo_mejor_caso(int n)
{
  return (int)floor(pow(n, 2) + n);
}

/**
 * @brief Implementación del modelo matemático del peor caso.
 *
 * @return int El resultado del modelo.
 */
int modelo_peor_caso(int n)
{
  return (int)floor((2 * pow(n, 2)) + (3 * n));
}

/**
 * @brief Implementación del modelo matemático del caso medio.
 *
 * @return int El resultado del modelo.
 */
int modelo_caso_medio(int n)
{
  return (int)floor(((3 * pow(n, 2)) + (4 * n)) / 2);
}
