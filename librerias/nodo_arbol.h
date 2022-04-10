/**
 * @file nodo_arbol.h
 * @author Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)
 * @brief Cabecera con la estructura y prototipos de función para manipulación de Árboles Binarios.
 * @version 0.1
 * @date 2022-03-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef NODO_ARBOL_H_INCLUIDO
#define NODO_ARBOL_H_INCLUIDO

// Estructura que representa el nodo en un árbol.
typedef struct nodo_arbol_t
{
  int dato;
  struct nodo_arbol_t *izq,
      *der;
} nodo_arbol;

// Prototipos de funciones para operaciones con árboles.
nodo_arbol *nuevo_nodo(int);
nodo_arbol *insertar_en_arbol(nodo_arbol *, int);
void almacenar_recorrido_inorden(nodo_arbol *, int *, int *);

#endif // NODO_ARBOL_H_INCLUIDO
