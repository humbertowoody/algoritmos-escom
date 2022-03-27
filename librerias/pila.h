/**
 * @file pila.h
 * @author Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)
 * @brief Cabecera con la estructura y prototoipos de funciones para el uso de Pilas.
 * @version 0.1
 * @date 2022-03-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef PILA_H_INCLUIDO
#define PILA_H_INCLUIDO

// Estructura que representa un elemento en una pila.
typedef struct pila_t
{
  int dato,
      contador,
      tope;
  struct pila_t *siguiente;
} pila;



#endif // PILA_H_INCLUIDO

