/**
 * @file producto-dos-mayores.c
 * @author Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)
 * @brief Implementación del Algoritmo: Producto de Dos Mayores
 * @version 0.1
 * @date 2022-03-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "producto_dos_mayores.h"

/**
 * @brief Implementación del Algoritmo: Producto de Dos Mayores contabilizando las operciones básicas realizadas.
 * @param arreglo Arreglo de enteros
 * @param tamano_arreglo Tamaño del arreglo
 * @param cont_operaciones Puntero a la variable que contabiliza las operaciones
 * @return Producto de dos mayores
 */
int producto_dos_mayores_cont(int *arreglo, int tamano_arreglo, cont_operaciones *conteo)
{
  // Variables auxliares.
  int mayor_1,
      mayor_2,
      i;

  // Determinamos los mayores iniciales.
  if (arreglo[0] > arreglo[1])
  {
    mayor_1 = arreglo[0];
    mayor_2 = arreglo[1];
  }
  else
  {
    mayor_1 = arreglo[1];
    mayor_2 = arreglo[0];
  }

  // Contabilizamos las operaciones.
  conteo->comparaciones++;   // La comparación del if.
  conteo->asignaciones += 2; // La asignación de mayor_1 y mayor_2.

  // Recorrido del arreglo.
  i = 2;
  while (i < tamano_arreglo)
  {
    if (arreglo[i] > mayor_1)
    {
      conteo->comparaciones++; // La comparación del if.

      mayor_2 = mayor_1;
      mayor_1 = arreglo[i];

      conteo->asignaciones += 2; // La asignación de mayor_1 y mayor_2.
    }
    else if (arreglo[i] > mayor_2)
    {
      conteo->comparaciones++; // La comparación del if.
      mayor_2 = arreglo[i];
      conteo->asignaciones++; // La asignación de mayor_2.
    }
    else
    {
      conteo->comparaciones += 2; // En caso de que el if y el else if no se cumplan, igual se contabilizan ambas operaciones.
    }

    i++;
  }

  return mayor_1 * mayor_2;
}

/**
 * @brief Implementación del Algoritmo: Producto de Dos Mayores
 * @param arreglo Arreglo de enteros
 * @param tamano_arreglo Tamaño del arreglo
 * @return Producto de dos mayores
 */
int producto_dos_mayores(int *arreglo, int tamano_arreglo)
{
  // Variables auxliares.
  int mayor_1,
      mayor_2,
      i;

  // Determinamos los mayores iniciales.
  if (arreglo[0] > arreglo[1])
  {
    mayor_1 = arreglo[0];
    mayor_2 = arreglo[1];
  }
  else
  {
    mayor_1 = arreglo[1];
    mayor_2 = arreglo[0];
  }

  // Recorrido del arreglo.
  i = 2;
  while (i < tamano_arreglo)
  {
    if (arreglo[i] > mayor_1)
    {
      mayor_2 = mayor_1;
      mayor_1 = arreglo[i];
    }
    else if (arreglo[i] > mayor_2)
    {
      mayor_2 = arreglo[i];
    }

    i++;
  }

  return mayor_1 * mayor_2;
}
