/**
 * @file nodo_arbol.c
 * @author Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)
 * @brief Implementación de los métodos para manipulación de nodos de Árboles Binarios.
 * @version 0.1
 * @date 2022-03-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "nodo_arbol.h"
#include <stdlib.h>

/**
 * @brief Función que crea un nuevo "nodo_arbol" con el dato proporcionado.
 *
 * @param dato El dato que tendrá el nodo creado.
 */
nodo_arbol *nuevo_nodo(int dato)
{
  // Generamos el nuevo nodo.
  nodo_arbol *nuevo = (nodo_arbol *)malloc(sizeof(nodo_arbol));

  // Asignamos los valores iniciales.
  nuevo->izq = NULL;
  nuevo->dato = dato;
  nuevo->der = NULL;

  // Regresamos el nodo creado.
  return nuevo;
}

/**
 * @brief Insertar un nuevo nodo en nuestro árbol.
 *
 * @param raiz El nodo raíz de nuestro árbol.
 * @param dato El dato para el nuevo nodo a insertar.
 */
nodo_arbol *insertar_en_arbol(nodo_arbol *raiz, int dato)
{
  // Validamos si el árbol está vacío.
  if (raiz == NULL)
  {
    return nuevo_nodo(dato);
  }

  // En otro caso, insertamos en la posición correcta dentro del árbol.
  if (dato <= raiz->dato)
  {
    // Si el dato nuevo es menor al dato en el nodo actual, lo colocamos en el
    // nodo izquierdo.
    raiz->izq = insertar_en_arbol(raiz->izq, dato);
  }
  else
  {

    // Si el dato nuevo es mayor al dato en el nodo actual, lo colocamos en el
    // nodo derecho.
    raiz->der = insertar_en_arbol(raiz->der, dato);
  }

  // Regresamos el apuntador a la raiz.
  return raiz;
}

/**
 * @brief Almacenar el recorrido inorden de nuestro árbol binario dentro de un
 *        arreglo.
 *
 * @param raiz La raíz de nuestro árbol para recorrer.
 * @param arreglo El arreglo donde almacenar la información.
 * @param pos Un puntero a una variable entera con la posición actual en nuestro
 *            arreglo resultante.
 */
void almacenar_recorrido_inorden(nodo_arbol *raiz, int *arreglo, int *pos)
{
  // Caso base.
  if (raiz != NULL)
  {
    // Primero el izquierdo.
    almacenar_recorrido_inorden(raiz->izq, arreglo, pos);
    // Luego el dato.
    arreglo[(*pos)++] = raiz->dato;
    // Al final el derecho.
    almacenar_recorrido_inorden(raiz->der, arreglo, pos);
  }
}

/**
 * @brief Libera la memoria de un árbol binario.
 *
 * @param nodo El nodo raíz de un árbol.
 */
void liberar_arbol(nodo_arbol *nodo)
{
  // Caso base.
  if (nodo != NULL)
  {
    // Primero el izquierdo.
    liberar_arbol(nodo->izq);
    // Luego el derecho.
    liberar_arbol(nodo->der);
    // Liberamos el nodo.
    free(nodo);
  }
}
