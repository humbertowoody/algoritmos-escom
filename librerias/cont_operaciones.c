/**
 * @file cont_operaciones.c
 * @author Humberto Alejandro Ortega Alcocer
 * @brief Implementación de la librería para conteo de operaciones "básicas".
 * @version 0.1
 * @date 2022-03-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "cont_operaciones.h"

/**
 * @brief Inicializa la estructura cont_operaciones.
 *
 * @param cont_operaciones *cont_operaciones_ptr Puntero a la estructura cont_operaciones.
 */
void inicializa_cont_operaciones(cont_operaciones *cont_operaciones_ptr)
{
  cont_operaciones_ptr->asignaciones = 0;
  cont_operaciones_ptr->comparaciones = 0;
  cont_operaciones_ptr->aritmeticas = 0;
}

/**
 * @brief Calcula el total de operaciones realizadas.
 *
 * @param cont_operaciones cont_operaciones Contador de operaciones.
 * @return int Total de operaciones realizadas.
 */
int total_operaciones(cont_operaciones operaciones)
{
  return operaciones.asignaciones + operaciones.comparaciones + operaciones.aritmeticas;
}
