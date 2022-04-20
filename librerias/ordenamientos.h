/**
 * @file ordenamientos.h
 * @author Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)
 * @brief Cabecera para librería de ordenamientos
 * @version 0.1
 * @date 2022-03-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef ORDENAMIENTOS_H_INCLUIDO
#define ORDENAMIENTOS_H_INCLUIDO

// Enumeración con los nombres de los algoritmos disponibles
typedef enum
{
  BURBUJA_SIMPLE = 0, // Para asegurarnos que la enumeración inicie en 0.
  BURBUJA_OPTIMIZADA_1,
  BURBUJA_OPTIMIZADA_2,
  INSERCION,
  SELECCION,
  SHELL,
  TREE,
  MERGE,
  QUICK,
  HEAP
} ALGORITMO_ORDENAMIENTO;

// Prototipos de funciones de ordenamiento.
void ordenar_burbuja_simple(int *, int);
void ordenar_burbuja_optimizada_1(int *, int);
void ordenar_burbuja_optimizada_2(int *, int);
void ordenar_insercion(int *, int);
void ordenar_seleccion(int *, int);
void ordenar_heap(int *, int);
void operacion_heapify(int *, int, int);
void ordenar_merge(int *, int, int);
void operacion_merge(int *, int, int, int);
void ordenar_quick(int *, int);
void ordenar_shell(int *, int);
void ordenar_tree(int *, int);

#endif // ORDENAMIENTOS_H_INCLUIDO
