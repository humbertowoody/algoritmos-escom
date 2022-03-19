/**
 * @file codigo_1.c
 * @author Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)
 * @brief Ejercicio 4, Código 1: Simulación de mejor, peor y caso medio.
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
  // Cuando los tres números mayores están al inicio del arreglo.
  for (int i = 0; i < NUM_PRUEBAS; i++)
  {
    int *arreglo = genera_arreglo_enteros_ordenados(NUM_ELEMENTOS);

    arreglo[0] = arreglo[NUM_ELEMENTOS - 1];
    arreglo[1] = arreglo[NUM_ELEMENTOS - 2];
    arreglo[2] = arreglo[NUM_ELEMENTOS - 3];
    arreglo[NUM_ELEMENTOS - 1] = NUM_ELEMENTOS - 4;
    arreglo[NUM_ELEMENTOS - 2] = NUM_ELEMENTOS - 5;
    arreglo[NUM_ELEMENTOS - 3] = NUM_ELEMENTOS - 6;

    inicializa_cont_operaciones(&operaciones);

    algoritmo(arreglo, NUM_ELEMENTOS, &operaciones);

    // Imprimmos la fila CSV.
    printf("mejor_caso,%d,%d,%d,%d,%d,%d,%d\n", i, NUM_ELEMENTOS, operaciones.asignaciones, operaciones.comparaciones, operaciones.aritmeticas, total_operaciones(operaciones), modelo_mejor_caso(NUM_ELEMENTOS));

    free(arreglo);
  }

  // Peor caso
  // Cuando los tres números mayores están al final del arreglo.
  for (int i = 0; i < NUM_PRUEBAS; i++)
  {
    int *arreglo = genera_arreglo_enteros_ordenados(NUM_ELEMENTOS);
    inicializa_cont_operaciones(&operaciones);
    algoritmo(arreglo, NUM_ELEMENTOS, &operaciones);
    // Imprimmos la fila CSV.
    printf("peor_caso,%d,%d,%d,%d,%d,%d,%d\n", i, NUM_ELEMENTOS, operaciones.asignaciones, operaciones.comparaciones, operaciones.aritmeticas, total_operaciones(operaciones), modelo_peor_caso(NUM_ELEMENTOS));
    free(arreglo);
  }

  // Caso medio.
  // Cuando los números están aleatorizados dentor del arreglo.
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
 * @brief Implementación de algoritmo: "Suma Cuadrática 3 Mayores"
 *
 * @param arreglo Arreglo de enteros.
 * @param tamano_arreglo El tamaño del arreglo.
 * @param operaciones Apuntador para contar las operaciones realizadas.
 * @return int El resultado del algoritmo.
 */
int algoritmo(int *arreglo, int tamano_arreglo, cont_operaciones *operaciones)
{
  // Declaración de variables.
  int m1, m2, m3; // Los tres números mayores.

  // Implementación del algoritmo.

  if (arreglo[0] > arreglo[1] && arreglo[0] > arreglo[2])
  {
    operaciones->comparaciones += 3; // 3 comparaciones del if.

    m1 = arreglo[0];

    operaciones->asignaciones++; // 1 asignación del m1.

    if (arreglo[1] > arreglo[2])
    {
      operaciones->comparaciones++; // comparación del if.
      m2 = arreglo[1];
      m3 = arreglo[2];
      operaciones->asignaciones += 2; // 2 asignaciones del m2 y m3.
    }
    else
    {
      operaciones->comparaciones++; // comparación del if.
      m2 = arreglo[2];
      m3 = arreglo[1];
      operaciones->asignaciones += 2; // 2 asignaciones del m2 y m3.
    }
  }
  else if (arreglo[1] > arreglo[0] && arreglo[1] > arreglo[2])
  {
    operaciones->comparaciones += 3; // 3 comparaciones del if.
    m1 = arreglo[1];
    operaciones->asignaciones++; // 1 asignación del m1.

    if (arreglo[0] > arreglo[2])
    {
      operaciones->comparaciones++; // comparación del if.
      m2 = arreglo[0];
      m3 = arreglo[2];
      operaciones->asignaciones += 2; // 2 asignaciones del m2 y m3.
    }
    else
    {
      operaciones->comparaciones++; // comparación del if.
      m2 = arreglo[2];
      m3 = arreglo[0];
      operaciones->asignaciones += 2; // 2 asignaciones del m2 y m3.
    }
  }
  else
  {
    operaciones->comparaciones += 6; // 3 comparaciones del if + 3 comparaciones del else if.
    m1 = arreglo[2];
    operaciones->asignaciones++; // 1 asignación del m1.

    if (arreglo[0] > arreglo[1])
    {
      operaciones->comparaciones++; // comparación del if.
      m2 = arreglo[0];
      m3 = arreglo[1];
      operaciones->asignaciones += 2; // 2 asignaciones del m2 y m3.
    }
    else
    {
      operaciones->comparaciones++; // comparación del if.
      m2 = arreglo[1];
      m3 = arreglo[0];
      operaciones->asignaciones += 2; // 2 asignaciones del m2 y m3.
    }
  }

  int i = 3;

  while (i < tamano_arreglo)
  {
    if (arreglo[i] > m1)
    {
      operaciones->comparaciones++; // 1 comparación del if.
      m3 = m2;
      m2 = m1;
      m1 = arreglo[i];
      operaciones->asignaciones += 3; // 3 asignaciones del m1, m2 y m3.
    }
    else if (arreglo[i] > m2)
    {
      operaciones->comparaciones += 2; // 1 comparación del if + 1 comparación del else if.
      m3 = m2;
      m2 = arreglo[i];
      operaciones->asignaciones += 2; // 2 asignaciones del m2 y m3.
    }
    else if (arreglo[i] > m3)
    {
      operaciones->comparaciones += 3; // 1 comparación del if + 2 comparaciones del else if.
      m3 = arreglo[i];
      operaciones->asignaciones++; // 1 asignación del m3.
    }
    else
    {
      operaciones->comparaciones += 3; // 1 comparación de if + 2 comparaciones del else if.
    }

    i++; // No contabilizamos las operaciones del iterador.
  }

  // Regresamos el cuadrado de los mayores.
  return pow(m1 + m2 + m3, 2);
}

/**
 * @brief Implementación del modelo del mejor caso.
 *
 * @return int El resultado del modelo.
 */
int modelo_mejor_caso(int n)
{
  return (int)floor((3 * n) - 2);
}

/**
 * @brief Implementación del modelo matemático del peor caso.
 *
 * @return int El resultado del modelo.
 */
int modelo_peor_caso(int n)
{
  return (int)floor((4 * n) - 2);
}

/**
 * @brief Implementación del modelo matemático del caso medio.
 *
 * @return int El resultado del modelo.
 */
int modelo_caso_medio(int n)
{
  return (int)floor(((14 * n) - 8) / 4);
}
