/**
 * @file ordenamientos.c
 * @author Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)
 * @brief Implementación de la librería de ordenamientos.
 * @version 0.1
 * @date 2022-03-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "ordenamientos.h"
#include "nodo_arbol.h"
#include <stdlib.h>

/**
 * @brief Ordena un arreglo de números enteros de forma ascendente utilizando
 *        el algoritmo "Burbuja".
 *
 * @param arreglo Arreglo a ordenar.
 * @param tamano_arreglo Tamaño del arreglo a ordenar.
 */
void ordenar_burbuja_simple(int *arreglo, int tamano_arreglo)
{
  // Variables auxiliares.
  int aux;

  // Recorrido del arreglo.
  for (int i = 0; i < tamano_arreglo - 1; i++)
  {
    // Recorrido del arreglo.
    for (int j = 0; j < tamano_arreglo - 1; j++)
    {
      // Si el elemento actual es menor que el siguiente, se intercambian los valores.
      if (arreglo[j] > arreglo[j + 1])
      {
        aux = arreglo[j];
        arreglo[j] = arreglo[j + 1];
        arreglo[j + 1] = aux;
      }
    }
  }
}

/**
 * @brief Ordena un arreglo de números enteros de forma ascendente utilizando
 *        el algoritmo "Burbuja Optimizada 1".
 *
 * @param arreglo Arreglo a ordenar.
 * @param tamano_arreglo Tamaño del arreglo a ordenar.
 */
void ordenar_burbuja_optimizada_1(int *arreglo, int tamano_arreglo)
{
  // Variables auxiliares.
  int aux;

  // Recorrido del arreglo.
  for (int i = 0; i < tamano_arreglo - 1; i++)
  {
    // Recorrido del arreglo.
    for (int j = 0; j < tamano_arreglo - 1 - i; j++)
    {
      // Si el elemento actual es menor que el siguiente, se intercambian los valores.
      if (arreglo[j] > arreglo[j + 1])
      {
        aux = arreglo[j];
        arreglo[j] = arreglo[j + 1];
        arreglo[j + 1] = aux;
      }
    }
  }
}

/**
 * @brief Ordena un arreglo de números enteros de forma ascendente utilizando
 *        el algoritmo "Burbuja Optimizada 2".
 *
 * @param arreglo Arreglo a ordenar.
 * @param tamano_arreglo Tamaño del arreglo a ordenar.
 */
void ordenar_burbuja_optimizada_2(int *arreglo, int tamano_arreglo)
{
  // Variables auxiliares
  int aux,
      cambios = 1;

  // Inicio de algoritmo
  for (int i = 0; i < (tamano_arreglo - 1) && cambios; i++)
  {
    // Cambiamos la bandera.
    cambios = 0;

    // Iteramos.
    for (int j = 0; j < tamano_arreglo - 1 - i; j++)
    {

      // Si el elemento actual es menor que el siguiente, se intercambian los valores.
      if (arreglo[j] > arreglo[j + 1])
      {
        aux = arreglo[j];
        arreglo[j] = arreglo[j + 1];
        arreglo[j + 1] = aux;
        cambios = 1;
      }
    }
  }
}

/**
 * @brief Ordena un arreglo de números enteros de forma ascendente usando
 *        el algoritmo: "Inserción".
 *
 * @param arreglo El arreglo de enteros a ordenar.
 * @param tamano_arreglo El tamaño del arreglo a ordenar.
 */
void ordenar_insercion(int *arreglo, int tamano_arreglo)
{
  // Variables auxiliares.
  int aux;
  int pos_actual;

  // Recorrido del arreglo.
  for (int i = 0; i < tamano_arreglo; i++)
  {
    // Se asigna el valor del elemento actual como el mínimo.
    aux = arreglo[i];
    pos_actual = i;

    // Recorrido del arreglo.
    while (pos_actual > 0 && aux < arreglo[pos_actual - 1])
    {
      // Si el elemento actual es menor que el mínimo, se asigna el valor del elemento actual como el mínimo.
      arreglo[pos_actual] = arreglo[pos_actual - 1];
      pos_actual--;
    }

    // Si el elemento actual no es el mínimo, se intercambian los valores.
    arreglo[pos_actual] = aux;
  }
}

/**
 * @brief Ordena un arreglo de números enteros de forma ascendente usando
 *        el algoritmo: "Selección".
 *
 * @param arreglo Arreglo a ordenar.
 * @param tamano_arreglo Tamaño del arreglo.
 */
void ordenar_seleccion(int *arreglo, int tamano_arreglo)
{
  // Variables auxiliares.
  int aux;
  int pos_min;

  // Recorrido del arreglo.
  for (int i = 0; i < tamano_arreglo - 1; i++)
  {
    // Se asigna el valor del elemento actual como el mínimo.
    pos_min = i;

    // Recorrido del arreglo.
    for (int j = i + 1; j < tamano_arreglo; j++)
    {
      // Si el elemento actual es menor que el mínimo, se asigna el valor del elemento actual como el mínimo.
      if (arreglo[j] < arreglo[pos_min])
      {
        pos_min = j;
      }
    }

    // Si el elemento actual no es el mínimo, se intercambian los valores.
    if (i != pos_min)
    {
      aux = arreglo[i];
      arreglo[i] = arreglo[pos_min];
      arreglo[pos_min] = aux;
    }
  }
}

/**
 * @brief Ordena un arreglo de números enteros de forma ascendente usando
 *        el algoritmo: "Shell".
 *
 * @param arreglo Arreglo a ordenar.
 * @param tamano_arreglo Tamaño del arreglo.
 */
void ordenar_shell(int *arreglo, int tamano_arreglo)
{
  // Variables auxiliares.
  int k = tamano_arreglo / 2,
      b,
      aux;

  // Iteramos sobre K/2
  while (k >= 1)
  {
    // Empezamos la b en 1.
    b = 1;

    // Iteramos mientras la b != 0 (no sucedió ningún intercambio)
    while (b != 0)
    {
      // Usamos la b como bandera.
      b = 0;

      // Iteramos desde k hasta el fin del arreglo.
      for (int i = k; i < tamano_arreglo; i++)
      {
        // Realizamos el intercambio en caso de que encontremos un valor apropiado.
        if (arreglo[i - k] > arreglo[i])
        {
          aux = arreglo[i];
          arreglo[i] = arreglo[i - k];
          arreglo[i - k] = aux;
          b++;
        }
      }
    }
    // Dividimos el rango a la mitad.
    k = k / 2;
  }
}

/**
 * @brief Ordena un arreglo de números enteros de forma ascendente usando
 *        el algoritmo: "Tree".
 *
 * @param arreglo Arreglo a ordenar.
 * @param tamano_arreglo Tamaño del arreglo.
 */
void ordenar_tree(int *arreglo, int tamano_arreglo)
{
  // Variables auxiliares.
  nodo_arbol *raiz = NULL;

  // Generamos el ABB.
  for (int i = 0; i < tamano_arreglo; i++)
  {
    raiz = insertar_en_arbol(raiz, arreglo[i]);
  }

  // Almacenamos el recorrido inorden de nuestro ABB.
  int posicion = 0; // La posición inicial del recorrido será 0.
  almacenar_recorrido_inorden(raiz, arreglo, &posicion);

  // Liberamos la memoria del ABB.
  liberar_arbol(raiz);
}

/**
 * @brief Ordena un arreglo de números enteros de forma ascendente usando
 *        el algoritmo: "Merge".
 *
 * @param arreglo Arreglo a ordenar.
 * @param inicio El punto de inicio para el ordenamiento.
 * @param tamano_arreglo Tamaño del arreglo.
 */
void ordenar_merge(int *arreglo, int inicio, int tamano_arreglo)
{
  // Variables auxiliares.
  int punto_medio;

  // Validamos el caso base de la recursividad.
  if (inicio < tamano_arreglo)
  {
    // Calculamos nuestro punto medio.
    punto_medio = (int)((inicio + tamano_arreglo) / 2);

    // Llamamos recursivo para cada mitad.
    ordenar_merge(arreglo, inicio, punto_medio);
    ordenar_merge(arreglo, punto_medio + 1, tamano_arreglo);

    // Realizamos la mezcla de los dos arreglos ordenados.
    operacion_merge(arreglo, inicio, punto_medio, tamano_arreglo);
  }
}

/**
 * @brief Función de ayuda para realizar la mezcla ("merge") de dos arreglos
 *        previamente ordenados.
 *
 * @param arreglo El arreglo de resultados.
 * @param inicio El inicio del arreglo a tratar.
 * @param punto_medio El punto medio del arreglo a tratar.
 * @param tamano_arreglo El tamaño del arreglo
 */
void operacion_merge(int *arreglo, int inicio, int punto_medio, int tamano_arreglo)
{
  // Variables auxiliares
  int l = tamano_arreglo - inicio + 1,
      i = inicio,
      j = punto_medio + 1,
      *arreglo_temp;

  // Inicializamos el arreglo temporal.
  arreglo_temp = (int *)malloc(sizeof(int) * l);

  // Iteramos para crear el nuevo arreglo (ordenado).
  for (int k = 0; k < l; k++)
  {
    // Lógica para ordenar el elemento en cuestión.
    if (i <= punto_medio && j <= tamano_arreglo)
    {
      if (arreglo[i] < arreglo[j])
      {
        arreglo_temp[k] = arreglo[i];
        i++;
      }
      else
      {
        arreglo_temp[k] = arreglo[j];
        j++;
      }
    }
    else if (i <= punto_medio)
    {
      arreglo_temp[k] = arreglo[i];
      i++;
    }
    else
    {
      arreglo_temp[k] = arreglo[j];
      j++;
    }
  }

  // Copiamos los valores en el arreglo temporal para la sección determinada.
  for (int r = inicio, p = 0; r < tamano_arreglo && p < l; r++, p++)
  {
    arreglo[r] = arreglo_temp[p];
  }

  // Limpiamos la memoria usada por arreglo_temp
  free(arreglo_temp);
}

/**
 * @brief Ordena un arreglo de números enteros de forma ascendente usando
 *        el algoritmo: "QuickSort".
 *
 * @param arreglo Arreglo a ordenar.
 * @param tamano_arreglo Tamaño del arreglo.
 */
void ordenar_quick(int *arreglo, int tamano_arreglo)
{
  // Variables auxiliares.
  int aux;
  int izq;
  int der;
  int pivote;

  // Recorrido del arreglo.
  izq = 0;
  der = tamano_arreglo - 1;
  pivote = arreglo[0];

  // Recorrido del arreglo.
  while (izq < der)
  {
    // Recorrido del arreglo.
    while (arreglo[izq] <= pivote && izq < der)
    {
      izq++;
    }

    // Recorrido del arreglo.
    while (arreglo[der] > pivote)
    {
      der--;
    }

    // Si el elemento actual no es el mínimo, se intercambian los valores.
    if (izq < der)
    {
      aux = arreglo[izq];
      arreglo[izq] = arreglo[der];
      arreglo[der] = aux;
    }
  }

  // Si el elemento actual no es el mínimo, se intercambian los valores.
  arreglo[0] = arreglo[der];
  arreglo[der] = pivote;

  // Si el arreglo tiene más de un elemento, se llama recursivamente al método.
  if (der > 0)
  {
    ordenar_quick(arreglo, der);
  }

  // Si el arreglo tiene más de un elemento, se llama recursivamente al método.
  if (der + 1 < tamano_arreglo)
  {
    ordenar_quick(arreglo + der + 1, tamano_arreglo - der - 1);
  }
}

/**
 * @brief Ordena un arreglo de números enteros de forma ascendente usando
 *        el algoritmo: "HeapSort".
 *
 * @param arreglo Arreglo a ordenar.
 * @param tamano_arreglo Tamaño del arreglo.
 */
void ordenar_heap(int *arreglo, int tamano_arreglo)
{
  // Variables auxiliares.
  int aux;
  int pos_actual;
  int pos_padre;

  // 1) Convertir nuestro arreglo en el orden de una pila.
  for (int i = tamano_arreglo / 2 - 1; i >= 0; i--)
  {
    // Recorrido del arreglo.
    pos_actual = i;

    // Recorrido del arreglo.
    while (pos_actual < tamano_arreglo / 2)
    {
      // Se asigna el valor del elemento actual como el mínimo.
      pos_padre = (pos_actual - 1) / 2;

      // Si el elemento actual es menor que el mínimo, se intercambian los valores.
      if (arreglo[pos_actual] < arreglo[pos_padre])
      {
        aux = arreglo[pos_actual];
        arreglo[pos_actual] = arreglo[pos_padre];
        arreglo[pos_padre] = aux;

        // Se asigna el valor del elemento actual como el mínimo.
        pos_actual = pos_padre;
      }
      else
      {
        break;
      }
    }
  }

  // 2) Extraemos los datos representados en la pila.
  for (int i = tamano_arreglo - 1; i >= 0; i--)
  {
    // Se asigna el valor del elemento actual como el mínimo.
    aux = arreglo[0];
    arreglo[0] = arreglo[i];
    arreglo[i] = aux;

    // Recorrido del arreglo.
    pos_actual = 0;

    // Recorrido del arreglo.
    while (pos_actual < tamano_arreglo / 2)
    {
      // Se asigna el valor del elemento actual como el m minimo.
      pos_padre = (pos_actual - 1) / 2;

      // Si el elemento actual es menor que el mínimo, se intercambian los valores.
      if (arreglo[pos_actual] < arreglo[pos_padre])
      {
        aux = arreglo[pos_actual];
        arreglo[pos_actual] = arreglo[pos_padre];
        arreglo[pos_padre] = aux;

        // Se asigna el valor del elemento actual como el mínimo.
        pos_actual = pos_padre;
      }
      else
      {
        break;
      }
    }
  }
}
