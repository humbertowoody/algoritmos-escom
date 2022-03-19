/**
 * @file codigo_1.c
 * @author Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)
 * @brief Ejercicio 4, Código 2: Simulación de mejor, peor y caso medio.
 * @version 0.1
 * @date 2022-03-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "librerias/genera_casos.h"
#include "librerias/cont_operaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definición de constante para el número de casos de prueba.
#ifndef NUM_PRUEBAS
#define NUM_PRUEBAS 10
#endif

// Prototipos de funciones.
int algoritmo(int, int, cont_operaciones *);
int modelo_mejor_caso();
int modelo_peor_caso(int);
int modelo_caso_medio(int);
int fibonacci(int);

int main(void)
{
  // Variables locales.
  cont_operaciones operaciones;

  // Imprimimos la cabecera CSV.
  printf("caso,iteración,m,n,ops_totales,modelo_matemático\n");

  // Mejor caso
  // Cuando los dos números son iguales.
  for (int i = 0; i < NUM_PRUEBAS; i++)
  {
    inicializa_cont_operaciones(&operaciones);

    algoritmo(i, i, &operaciones);

    // Imprimmos la fila CSV.
    printf("mejor_caso,%d,%d,%d,%d,%d\n", i, i, i, total_operaciones(operaciones), modelo_mejor_caso());
  }

  // Peor caso
  // Dos números consecutivos de la serie de Fibonacci.
  for (int i = 0; i < NUM_PRUEBAS; i++)
  {
    inicializa_cont_operaciones(&operaciones);
    algoritmo(fibonacci(i), fibonacci(i + 1), &operaciones);

    // Imprimmos la fila CSV.
    printf("peor_caso,%d,%d,%d,%d,%d\n", i, fibonacci(i), fibonacci(i + 1), total_operaciones(operaciones), modelo_peor_caso(fibonacci(i)));
  }

  // Caso medio.
  // Cuando los números están aleatorizados dentor del arreglo.
  for (int i = 0; i < NUM_PRUEBAS; i++)
  {
    int *arreglo = genera_arreglo_enteros_aleatorios(2, 1, 1000);
    inicializa_cont_operaciones(&operaciones);
    algoritmo(arreglo[0], arreglo[1], &operaciones);
    // Imprimmos la fila CSV.
    printf("caso_medio,%d,%d,%d,%d,%d\n", i, arreglo[0], arreglo[1], total_operaciones(operaciones), modelo_caso_medio(arreglo[0]));
    free(arreglo);
  }

  return 0;
}

/**
 * @brief Implementación de algoritmo: "Algoritmo de Euclides"
 *
 * @param m Entero m
 * @param n Entero n
 * @param operaciones Apuntador para contar las operaciones realizadas.
 * @return int El resultado del algoritmo.
 */
int algoritmo(int m, int n, cont_operaciones *operaciones)
{
  // Variables locales.
  int a, b, r = 1;

  // Determinamos el mayor de ambos.
  if (m > n)
  {
    a = m;
    b = n;
  }
  else
  {
    a = n;
    b = m;
  }

  while (r > 0)
  {
    r = a % b;                  // Operación fundamental básica.
    operaciones->aritmeticas++; // El módulo.
    a = b;
    b = r;
  }

  // Regresamos el máximo común divisor.
  return a;
}

/**
 * @brief Implementación del modelo del mejor caso.
 *
 * @return int El resultado del modelo.
 */
int modelo_mejor_caso()
{
  // En este caso, es constante.
  return 1;
}

/**
 * @brief Implementación del modelo matemático del peor caso.
 *
 * @return int El resultado del modelo.
 */
int modelo_peor_caso(int n)
{
  return (int)log10(n);
}

/**
 * @brief Implementación del modelo matemático del caso medio.
 *
 * @return int El resultado del modelo.
 */
int modelo_caso_medio(int n)
{
  // Return the average complexity of the euclides algorithm.
  return (int)((12 / (pow(M_PI, 2)) * log(2) * log(n))) + 0.6;
}

/**
 * @brief Obtener el n-ésimo número de la serie de Fibonacci.
 *
 * @param n La posición del elemento a encontrar en la serie Fibonacci.
 * @return int El elemento de la serie de Fibonacci.
 */
int fibonacci(int n)
{
  if (n == 0)
  {
    return 0;
  }
  else if (n == 1)
  {
    return 1;
  }
  else
  {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}
