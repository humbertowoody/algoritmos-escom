/**
 * @file busquedas.h
 * @author Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)
 * @brief Cabecera de libreria para realizar busquedas.
 * @version 0.1
 * @date 2022-04-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef BUSQUEDAS_H_INCLUIDO
#define BUSQUEDAS_H_INCLUIDO

// Para las operaciones que requieran un árbol binario.
#include "nodo_arbol.h"

// Enumeración con los nombres de los algoritmos disponibles.
typedef enum
{
  LINEAL = 0,
  LINEAL_P,
  ABB,
  ABB_P,
  // ABB_R,
  BINARIA,
  BINARIA_P,
  // BINARIA_R,
  EXPONENCIAL,
  EXPONENCIAL_P,
  FIBONACCI,
  FIBONACCI_P
} ALGORITMO_BUSQUEDA;

// Prototipos de funciones.
//   i = implementación iterativa.
//   i_p = implementación iterativa paralelizada.
//   r = implementación recursiva.
int busqueda_lineal_i(int *, int, int);
int busqueda_lineal_i_p(int *, int, int);
nodo_arbol *busqueda_abb_i(nodo_arbol *, int);
nodo_arbol *busqueda_abb_i_p(nodo_arbol *, int);
nodo_arbol *busqueda_abb_r(nodo_arbol *, int);
int busqueda_binaria_i(int *, int, int, int);
int busqueda_binaria_i_p(int *, int, int);
int busqueda_binaria_r(int *, int, int, int);
int busqueda_exponencial_i(int *, int, int);
int busqueda_exponencial_i_p(int *, int, int);
int busqueda_fibonacci_i(int *, int, int);
int busqueda_fibonacci_i_p(int *, int, int);

#endif // BUSQUEDAS_H_INCLUIDO
