/**
 * @file matematicas.c
 * @author Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)
 * @brief Implementación para librería con funciones genéricas de matemáticas.
 * @version 0.1
 * @date 2022-04-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "matematicas.h"

/**
 * @brief Regresa el menor de dos números.
 *
 * @param a El primer número.
 * @param b El segundo número.
 * @return int El menor de ambos números.
 */
int min(int a, int b)
{
  return a < b ? a : b;
}

/**
 * @brief Regresa el mayor de dos números.
 *
 * @param a El primer número.
 * @param b El segundo número.
 * @return int El mayor de ambos números.
 */
int max(int a, int b)
{
  return a > b ? a : b;
}
