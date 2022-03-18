/**
 * @file cont_operaciones.h
 * @author Humberto Alcocer (humbertoalejandroortegalcocer@gmail.com)
 * @brief Librería para conteo de operaciones "básicas"
 * @version 0.1
 * @date 2022-03-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef CONT_OPERACIONES_H_INCLUIDO
#define CONT_OPERACIONES_H_INCLUIDO

/**
 * @brief Estructura para conteo de operaciones
 *
 */
typedef struct cont_operaciones
{
  int asignaciones;  // Número de asignaciones. a = b;
  int comparaciones; // Número de comparaciones. a < b; a > b; a <= b; a >= b; a == b; a != b; a && b; a || b;
  int aritmeticas;   // Número de operaciones aritméticas. a + b; a - b; a * b; a / b; a % b;
} cont_operaciones;

void inicializa_cont_operaciones(cont_operaciones *);
int total_operaciones(cont_operaciones);

#endif // CONT_OPERACIONES_H_INCLUIDO
