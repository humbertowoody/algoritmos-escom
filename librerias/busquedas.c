/**
 * @file busquedas.c
 * @author Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)
 * @brief Implementación de librería de algoritmos de búsqueda.
 * @version 0.1
 * @date 2022-04-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "busquedas.h"
#include "nodo_arbol.h"
#include "matematicas.h"
#include "arreglo.h"
#include <stdlib.h>
#include <pthread.h>

/**
 * @brief Si no está definido el número máximo de hilos, se define a 5 por defecto.
 *        Esto pues 5 es múltiplo de los tamaños de arreglo que se plantean en los
 *       ejemplos.
 */
#ifndef NUMERO_MAXIMO_HILOS
#define NUMERO_MAXIMO_HILOS 5
#endif // NUMERO_MAXIMO_HILOS

// Estructura para almacenar los datos de los hilos.
typedef struct
{
  int *arreglo;
  int num_elementos;
  int elemento_buscado;
  int inicio;
  int fin;
  nodo_arbol *nodo_raiz;
  nodo_arbol nodo_buscado;
} datos_hilo;

// Estructura para almacenar los resultados de los hilos.
typedef struct
{
  int indice;
  nodo_arbol *nodo_resultado;
} resultado_hilo;

// Prototipos de funciones.
void *busqueda_lineal_hilo(void *);
void *busqueda_binaria_hilo(void *);
void *busqueda_exponencial_hilo(void *);
void *busqueda_fibonacci_hilo(void *);
void *busqueda_abb_hilo(void *);

/**
 * @brief Busca un entero dentro de un arreglo de enteros y, en caso de que el
 *        elemento sea encontrado, regresa el índice de su posición dentro del
 *        arreglo. Implementación iterativa.
 *
 * @param arreglo El arreglo para realizar la búsqueda.
 * @param tamanio El tamaño del arreglo dónde realizar la búsqueda.
 * @param elemento El elemento que estamos buscando.
 * @return int El índice del elemento encontrado, -1 si no se encontró.
 */
int busqueda_lineal_i(int *arreglo, int tamanio, int elemento)
{
  // Iteramos sobre todo el arreglo buscando el elemento.
  for (int i = 0; i < tamanio; i++)
  {
    if (arreglo[i] == elemento)
    {
      return i;
    }
  }

  // El elemento no se encuentra dentro del arreglo.
  return -1;
}

/**
 * @brief Busca un entero dentro de un arreglo de enteros y, en caso de que el
 *        elemento sea encontrado, regresa el índice de su posición dentro del
 *       arreglo. Implementación iterativa en paralelo.
 *
 *
 * @param arreglo El arreglo para realizar la búsqueda.
 * @param tamanio El tamaño del arreglo dónde realizar la búsqueda.
 * @param elemento El elemento que estamos buscando.
 * @return int El índice del elemento encontrado, -1 si no se encontró.
 */
int busqueda_lineal_i_p(int *arreglo, int tamanio, int elemento)
{
  // Variables locales.
  pthread_t hilos[NUMERO_MAXIMO_HILOS];                     // Arreglo de hilos.
  int tamanio_sub_arreglos = tamanio / NUMERO_MAXIMO_HILOS, // Tamaño de los subarreglos.
      resultado_final = -1;                                 // Resultado final.
  resultado_hilo *resultados_hilos[NUMERO_MAXIMO_HILOS];    // Arreglo de resultados de los hilos.
  datos_hilo datos_para_los_hilos[NUMERO_MAXIMO_HILOS];     // Datos para los hilos.

  // Iniciamos el arreglo de hilos.
  for (int i = 0; i < NUMERO_MAXIMO_HILOS; i++)
  {
    // Asignamos datos para hilos.
    datos_para_los_hilos[i].arreglo = crear_arreglo(tamanio_sub_arreglos);
    datos_para_los_hilos[i].num_elementos = tamanio_sub_arreglos;
    datos_para_los_hilos[i].elemento_buscado = elemento;

    // Copiamos los datos en el subarreglo.
    copiar_arreglo_rango(arreglo, datos_para_los_hilos[i].arreglo, i * tamanio_sub_arreglos, (i + 1) * tamanio_sub_arreglos);

    // Creamos el hilo.
    pthread_create(&hilos[i], NULL, busqueda_lineal_hilo, (void *)&datos_para_los_hilos[i]);
  }

  // Esperamos a que todos los hilos terminen.
  for (int i = 0; i < NUMERO_MAXIMO_HILOS; i++)
  {
    // Esperamos a que el hilo en cuestión termine.
    pthread_join(hilos[i], (void *)&resultados_hilos[i]);

    // Limpiamos la memoria de los datos para los hilos.
    free(datos_para_los_hilos[i].arreglo);

    // Verificamos si el hilo encontró el elemento.
    if (resultados_hilos[i]->indice != -1)
    {
      // Ajustamos el índice del elemento encontrado.
      resultado_final = resultados_hilos[i]->indice + i * tamanio_sub_arreglos;
    }

    // Limpiamos la memoria de los resultados de los hilos.
    free(resultados_hilos[i]);
  }

  // El elemento no se encuentra dentro del arreglo.
  return resultado_final;
}

/**
 * @brief Función que se ejecuta en paralelo para buscar un elemento dentro de un
 *       arreglo.
 *
 * @param datos Los datos para el hilo de ejecución del algoritmo de búsqueda lineal iterativa.
 * @return void* El índice resultante del algoritmo.
 */
void *busqueda_lineal_hilo(void *datos)
{
  // Obtenemos los datos del hilo.
  datos_hilo *d = (datos_hilo *)datos;

  // Creamos la estructura para almacenar el resultado del hilo.
  resultado_hilo *resultado = (resultado_hilo *)malloc(sizeof(resultado_hilo));

  // Buscamos el elemento dentro del arreglo.
  resultado->indice = busqueda_lineal_i(d->arreglo, d->num_elementos, d->elemento_buscado);

  // Regresamos el índice del elemento encontrado.
  return (void *)resultado;
}

/**
 * @brief Busca un entero dentro de un arreglo de enteros *ordenado* y, en caso
 *        de que el elemento sea encontrado, regresa el índice de su posición
 *        dentro del arreglo. Implementación iterativa.
 *
 * @param arreglo El arreglo a realizar la búsqueda.
 * @param inicio La posicion inicial en el arreglo.
 * @param fin La posicion final en el arreglo.
 * @param elemento El elemento que estamos buscando.
 * @return int El índice del elemento encontrado, -1 si no se encontró.
 */
int busqueda_binaria_i(int *arreglo, int inicio, int fin, int elemento)
{
  // Variables locales.
  int punto_medio;

  // Iteramos mientras nuestro intervalo sea válido.
  while (inicio <= fin)
  {
    // Calculamos nuestro punto medio.
    punto_medio = inicio + (fin - inicio) / 2;

    // Verificamos si el elemento está en la posición calculada.
    if (arreglo[punto_medio] == elemento)
    {
      return punto_medio;
    }
    // Si el elemento es mayor, ignoramos la primer mitad del arreglo.
    else if (arreglo[punto_medio] < elemento)
    {
      inicio = punto_medio + 1;
    }
    // Si el elemento es menor, ignoramos la segunda mitad del arreglo.
    else
    {
      fin = punto_medio - 1;
    }
  }

  // Si salimos del ciclo y no encontramos el elemento, el elemento no existe
  // en el arreglo.
  return -1;
}

/**
 * @brief Busca un entero dentro de un arreglo de enteros y, en caso de que el
 *        elemento sea encontrado, regresa el índice de su posición dentro del
 *       arreglo. Implementación iterativa en paralelo.
 *
 *
 * @param arreglo El arreglo para realizar la búsqueda.
 * @param tamanio El tamaño del arreglo a realizar la búsqueda.
 * @param elemento El elemento que estamos buscando.
 * @return int El índice del elemento encontrado, -1 si no se encontró.
 */
int busqueda_binaria_i_p(int *arreglo, int tamanio, int elemento)
{
  // Variables locales.
  pthread_t hilos[NUMERO_MAXIMO_HILOS];                     // Arreglo de hilos.
  int tamanio_sub_arreglos = tamanio / NUMERO_MAXIMO_HILOS, // Tamaño de los subarreglos.
      resultado_final = -1;                                 // Resultado final.
  resultado_hilo *resultados_hilos[NUMERO_MAXIMO_HILOS];    // Arreglo de resultados de los hilos.
  datos_hilo datos_para_los_hilos[NUMERO_MAXIMO_HILOS];     // Datos para los hilos.

  // Iniciamos el arreglo de hilos.
  for (int i = 0; i < NUMERO_MAXIMO_HILOS; i++)
  {
    // Asignamos datos para hilos.
    datos_para_los_hilos[i].arreglo = crear_arreglo(tamanio_sub_arreglos);
    datos_para_los_hilos[i].inicio = 0;
    datos_para_los_hilos[i].fin = tamanio_sub_arreglos;
    datos_para_los_hilos[i].elemento_buscado = elemento;

    // Copiamos los datos en el subarreglo.
    copiar_arreglo_rango(arreglo, datos_para_los_hilos[i].arreglo, i * tamanio_sub_arreglos, (i + 1) * tamanio_sub_arreglos);

    // Creamos el hilo.
    pthread_create(&hilos[i], NULL, busqueda_binaria_hilo, (void *)&datos_para_los_hilos[i]);
  }

  // Esperamos a que todos los hilos terminen.
  for (int i = 0; i < NUMERO_MAXIMO_HILOS; i++)
  {
    // Esperamos a que el hilo en cuestión termine.
    pthread_join(hilos[i], (void *)&resultados_hilos[i]);

    // Limpiamos la memoria de los datos para los hilos.
    free(datos_para_los_hilos[i].arreglo);

    // Verificamos si el hilo encontró el elemento.
    if (resultados_hilos[i]->indice != -1)
    {
      // Ajustamos el índice del elemento encontrado.
      resultado_final = resultados_hilos[i]->indice + i * tamanio_sub_arreglos;
    }

    // Limpiamos la memoria de los resultados de los hilos.
    free(resultados_hilos[i]);
  }

  // El elemento no se encuentra dentro del arreglo.
  return resultado_final;
}

/**
 * @brief Función que se ejecuta en paralelo para buscar un elemento dentro de un
 *       arreglo.
 *
 * @param datos Los datos para el hilo de ejecución del algoritmo de búsqueda binaria iterativa.
 * @return void* El índice resultante del algoritmo.
 */
void *busqueda_binaria_hilo(void *datos)
{
  // Obtenemos los datos del hilo.
  datos_hilo *d = (datos_hilo *)datos;

  // Creamos la estructura para almacenar el resultado del hilo.
  resultado_hilo *resultado = (resultado_hilo *)malloc(sizeof(resultado_hilo));

  // Buscamos el elemento dentro del arreglo.
  resultado->indice = busqueda_binaria_i(d->arreglo, d->inicio, d->fin, d->elemento_buscado);

  // Regresamos el índice del elemento encontrado.
  return (void *)resultado;
}

/**
 * @brief Busca un entero dentro de un arreglo de enteros *ordenado* y, en caso
 *        de que el elemento sea encontrado, regresa el índice de su posición
 *        dentro del arreglo. Implementación recursiva.
 *
 * @param arreglo El arreglo a realizar la búsqueda.
 * @param inicio La posicion inicial en el arreglo.
 * @param fin La posicion final en el arreglo.
 * @param elemento El elemento que estamos buscando.
 * @return int El índice del elemento encontrado, -1 si no se encontró.
 */
int busqueda_binaria_r(int *arreglo, int inicio, int fin, int elemento)
{
  // Verificamos si nuestro intervalo de búsqueda es aún >1 elementos.
  if (fin >= 1)
  {
    // Calculamos el punto medio.
    int punto_medio = inicio + (fin - inicio) / 2;

    // Planteamos el caso base de nuestra recursividad.
    if (arreglo[punto_medio] == elemento)
    {
      // Encontramos el elemento.
      return punto_medio;
    }
    else if (arreglo[punto_medio] > elemento)
    {
      // Buscamos en la primer mitad de nuestro arreglo.
      return busqueda_binaria_r(arreglo, inicio, punto_medio - 1, elemento);
    }

    // Buscamos en la segunda mitad de nuestro arreglo.
    return busqueda_binaria_r(arreglo, punto_medio + 1, fin, elemento);
  }

  // El elemento no se encuentra en el arreglo.
  return -1;
}

/**
 * @brief Busca un entero dentro de un Árbol Binario de Búsqueda previamente
 *        construído, en caso de encontrar el elemento, devuelve el nodo donde
 *        se encuentra, en caso contrario NULL. Implementación iterativa.
 *
 * @param raiz El nodo raíz de nuestro árbol.
 * @param elemento El elemento que estamos buscando
 * @return nodo_arbol Un nodo del árbol de búsqueda con el resultado, si no lo
 *                    encuentra regresará NULL.
 */
nodo_arbol *busqueda_abb_i(nodo_arbol *raiz, nodo_arbol elemento)
{
  // Variables locales.
  nodo_arbol *nodo_actual = raiz;

  // Iteramos sobre el árbol.
  while (nodo_actual != NULL)
  {
    // Verificamos si el nodo actual contiene el elemento que buscamos.
    if (nodo_actual->dato == elemento.dato)
    {
      return nodo_actual;
    }
    // Si el elemento es mayor a nuestro nodo actual, iteramos por la derecha.
    else if (nodo_actual->dato < elemento.dato)
    {
      nodo_actual = nodo_actual->der;
    }
    // Si el elemento es menor a nuestro nodo actual, iteramos por la izquierda.
    else
    {
      nodo_actual = nodo_actual->izq;
    }
  }

  // Si salimos del ciclo, el elemento no existe en el árbol, regresamos NULL.
  return NULL;
}

/**
 * @brief Busca un entero dentro de un arreglo de enteros y, en caso de que el
 *        elemento sea encontrado, regresa el índice de su posición dentro del
 *       arreglo. Implementación iterativa en paralelo.
 *
 *
 * @param raiz La raíz del árbol de búsqueda.
 * @param elemento El elemento que estamos buscando.
 * @return int El índice del elemento encontrado, -1 si no se encontró.
 */
nodo_arbol *busqueda_abb_i_p(nodo_arbol *raiz, nodo_arbol elemento)
{
  // Variables locales.
  pthread_t hilo1, hilo2;
  resultado_hilo *resultado1 = NULL, *resultado2 = NULL;
  datos_hilo datos1, datos2;
  nodo_arbol *resultado_final = NULL;

  // Verificación inicial (si la raíz tiene el resultado).
  if (raiz->dato == elemento.dato)
  {
    return raiz;
  }

  // Inicializamos los datos para nuestros hilos.
  datos1.nodo_raiz = raiz->der;
  datos2.nodo_raiz = raiz->izq;
  datos1.nodo_buscado = datos2.nodo_buscado = elemento;

  // Iniciamos los hilos.
  pthread_create(&hilo1, NULL, busqueda_abb_hilo, (void *)&datos1);
  pthread_create(&hilo2, NULL, busqueda_abb_hilo, (void *)&datos2);

  // Esperamos a que los hilos terminen.
  pthread_join(hilo1, (void *)&resultado1);
  pthread_join(hilo2, (void *)&resultado2);

  // Verificamos los resultados.
  if (resultado1->nodo_resultado != NULL && resultado1->nodo_resultado->dato == elemento.dato)
  {
    // Encontramos el elemento en el primer hilo.
    resultado_final = resultado1->nodo_resultado;
  }
  else if (resultado2->nodo_resultado != NULL && resultado2->nodo_resultado->dato == elemento.dato)
  {
    // Encontramos el elemento en el segundo hilo.
    resultado_final = resultado2->nodo_resultado;
  }

  // Liberamos los resultados.
  free(resultado1);
  free(resultado2);

  // Regresamos el resultado final.
  return resultado_final;
}

/**
 * @brief Función que se ejecuta en paralelo para buscar un elemento dentro de un
 *       arreglo.
 *
 * @param datos Los datos para el hilo de ejecución del algoritmo de búsqueda abb iterativa.
 * @return void* El índice resultante del algoritmo.
 */
void *busqueda_abb_hilo(void *datos)
{
  // Obtenemos los datos del hilo.
  datos_hilo *d = (datos_hilo *)datos;

  // Creamos la estructura para almacenar el resultado del hilo.
  resultado_hilo *resultado = (resultado_hilo *)malloc(sizeof(resultado_hilo));

  // Buscamos el elemento dentro del arreglo.
  resultado->nodo_resultado = busqueda_abb_i(d->nodo_raiz, d->nodo_buscado);

  // Regresamos el índice del elemento encontrado.
  return (void *)resultado;
}

/**
 * @brief Busca un entero dentro de un Árbol Binario de Búsqueda previamente
 *        construído, en caso de encontrar el elemento, devuelve el nodo donde
 *        se encuentra, en caso contrario NULL. Implementación recursiva.
 *
 * @param raiz El nodo raíz de nuestro árbol.
 * @param elemento El elemento que estamos buscando
 * @return nodo_arbol Un nodo del árbol de búsqueda con el resultado, si no lo
 *                    encuentra regresará NULL.
 */
nodo_arbol *busqueda_abb_r(nodo_arbol *raiz, nodo_arbol elemento)
{
  // Caso base.
  if (raiz == NULL || raiz->dato == elemento.dato)
  {
    return raiz;
  }

  // Caso dónde el elemento es mayor a la raíz (nos vamos a la derecha del ABB).
  if (raiz->dato < elemento.dato)
  {
    return busqueda_abb_r(raiz->der, elemento);
  }

  // Caso dónde el elemento es menor a la raíz (nos vamos a la izquierda del ABB).
  return busqueda_abb_r(raiz->izq, elemento);
}

/**
 * @brief Busca un entero dentro de un arreglo de enteros *ordenado* y, en caso
 *        de que el elemento sea encontrado, regresa el índice de su posición
 *        dentro del arreglo. Implementación iterativa.
 *
 * @param arreglo El arreglo a realizar la búsqueda.
 * @param tamanio El tamaño del arreglo a realizar la búsqueda.
 * @param elemento El elemento que estamos buscando.
 * @return int El índice del elemento encontrado, -1 si no se encontró.
 */
int busqueda_exponencial_i(int *arreglo, int tamanio, int elemento)
{
  // Variables locales.
  int i;

  // Verificamos si el elemento existe en la primer posición del arreglo (mejor caso).
  if (arreglo[0] == elemento)
  {
    return 0;
  }

  // Iteramos para obtener el rango de búsqueda más pqeueño posible.
  for (i = 1; i < tamanio && arreglo[i] <= elemento; i *= 2)
    ; // Qué elegancia la de francia.

  // Realizamos una búsqueda binaria en el intervalo encontrado.
  //   inicio = la mitad de nuestra i máxima alcanzada.
  //   fin = el mínimo entre la i máxima alcanzada o el tamaño del arreglo en sí.
  return busqueda_binaria_i(arreglo, i / 2, min(i, tamanio - 1), elemento);
}

/**
 * @brief Busca un entero dentro de un arreglo de enteros y, en caso de que el
 *        elemento sea encontrado, regresa el índice de su posición dentro del
 *       arreglo. Implementación iterativa en paralelo.
 *
 *
 * @param arreglo El arreglo para realizar la búsqueda.
 * @param tamanio El tamaño del arreglo para realizar la búsqueda.
 * @param elemento El elemento que estamos buscando.
 * @return int El índice del elemento encontrado, -1 si no se encontró.
 */
int busqueda_exponencial_i_p(int *arreglo, int tamanio, int elemento)
{
  // Variables locales.
  pthread_t hilos[NUMERO_MAXIMO_HILOS];                     // Arreglo de hilos.
  int tamanio_sub_arreglos = tamanio / NUMERO_MAXIMO_HILOS, // Tamaño de los subarreglos.
      resultado_final = -1;
  resultado_hilo *resultados_hilos[NUMERO_MAXIMO_HILOS]; // Arreglo de resultados de los hilos.
  datos_hilo datos_para_los_hilos[NUMERO_MAXIMO_HILOS];  // Datos para los hilos.

  // Iniciamos el arreglo de hilos.
  for (int i = 0; i < NUMERO_MAXIMO_HILOS; i++)
  {
    // Asignamos datos para hilos.
    datos_para_los_hilos[i].arreglo = crear_arreglo(tamanio_sub_arreglos);
    datos_para_los_hilos[i].num_elementos = tamanio_sub_arreglos;
    datos_para_los_hilos[i].elemento_buscado = elemento;

    // Copiamos los datos en el subarreglo.
    copiar_arreglo_rango(arreglo, datos_para_los_hilos[i].arreglo, i * tamanio_sub_arreglos, (i + 1) * tamanio_sub_arreglos);

    // Creamos el hilo.
    pthread_create(&hilos[i], NULL, busqueda_exponencial_hilo, (void *)&datos_para_los_hilos[i]);
  }

  // Esperamos a que todos los hilos terminen.
  for (int i = 0; i < NUMERO_MAXIMO_HILOS; i++)
  {
    // Esperamos a que el hilo en cuestión termine.
    pthread_join(hilos[i], (void *)&resultados_hilos[i]);

    // Limpiamos la memoria de los datos para los hilos.
    free(datos_para_los_hilos[i].arreglo);

    // Verificamos si el hilo encontró el elemento.
    if (resultados_hilos[i]->indice != -1)
    {
      // Ajustamos el índice del elemento encontrado.
      resultado_final = resultados_hilos[i]->indice + i * tamanio_sub_arreglos;
    }

    // Limpiamos la memoria de los resultados de los hilos.
    free(resultados_hilos[i]);
  }

  // Regresamos el resultado final.
  return resultado_final;
}

/**
 * @brief Función que se ejecuta en paralelo para buscar un elemento dentro de un
 *       arreglo.
 *
 * @param datos Los datos para el hilo de ejecución del algoritmo de búsqueda exponencial iterativa.
 * @return void* El índice resultante del algoritmo.
 */
void *busqueda_exponencial_hilo(void *datos)
{
  // Obtenemos los datos del hilo.
  datos_hilo *d = (datos_hilo *)datos;

  // Creamos la estructura para almacenar el resultado del hilo.
  resultado_hilo *resultado = (resultado_hilo *)malloc(sizeof(resultado_hilo));

  // Buscamos el elemento dentro del arreglo.
  resultado->indice = busqueda_exponencial_i(d->arreglo, d->num_elementos, d->elemento_buscado);

  // Regresamos el índice del elemento encontrado.
  return (void *)resultado;
}

/**
 * @brief Busca un entero dentro de un arreglo de enteros *ordenado* y, en caso
 *        de que el elemento sea encontrado, regresa el índice de su posición
 *        dentro del arreglo. Implementación iterativa.
 *
 * @param arreglo El arreglo a realizar la búsqueda.
 * @param tamanio El tamaño del arreglo a realizar la búsqueda.
 * @param elemento El elemento que estamos buscando.
 * @return int El índice del elemento encontrado, -1 si no se encontró.
 */
int busqueda_fibonacci_i(int *arreglo, int tamanio, int elemento)
{
  // Variables locales.
  int fib_m_menos_2 = 0,                     // Número (m-2)-ésimo de la serie fibonacci.
      fib_m_menos_1 = 1,                     // Número (m-1)-ésimo de la serie fibonacci.
      fib_m = fib_m_menos_1 + fib_m_menos_2, // Número m-ésimo de la serie fibonacci.
      offset = -1,                           // Número de compensación de la serie para el algoritmo.
      aux;

  // fib_m almacenará el número de la serie fibonacci más cercano (por encima) a nuestro
  // tamaño del arreglo.
  while (fib_m < tamanio)
  {
    fib_m_menos_2 = fib_m_menos_1;
    fib_m_menos_1 = fib_m;
    fib_m = fib_m_menos_2 + fib_m_menos_1;
  }

  // Mientras existan elementos por inspeccionar.
  // Nota: comparamos fib_m_menos_2 con el elemento porque cuando fib_m sea 1
  //       fib_m_menos_2 será 0.
  while (fib_m_menos_1 > 1)
  {
    // Verificamos si fib_m_menos_2 es una posición válida en el arreglo.
    aux = min(offset + fib_m_menos_2, tamanio - 1);

    // Si el elemento es mayor al valor en el índice fib_m_menos_2, reducimos el
    // intervalo de búsqueda desde el offset hasta aux.
    if (arreglo[aux] < elemento)
    {
      fib_m = fib_m_menos_1;
      fib_m_menos_1 = fib_m_menos_2;
      fib_m_menos_2 = fib_m - fib_m_menos_1;
      offset = aux;
    }
    // En caso de que el elemento sea menor al valor en el índice fib_m_menos_2,
    // reducimos el intervalo de búsqueda después de (aux + 1).
    else if (arreglo[aux] > elemento)
    {
      fib_m = fib_m_menos_2;
      fib_m_menos_1 = fib_m_menos_1 - fib_m_menos_2;
      fib_m_menos_2 = fib_m - fib_m_menos_1;
    }
    // En otro caso, aux será el índice del elemento encontrado.
    else
    {
      return aux;
    }
  }

  // Si terminó la iteración, comparamos el último elemento.
  if (fib_m_menos_1 && arreglo[offset + 1] == elemento)
  {
    return offset + 1;
  }

  // En cualquier otro caso, el elemento no fue encontrado.
  return -1;
}

/**
 * @brief Busca un entero dentro de un arreglo de enteros y, en caso de que el
 *        elemento sea encontrado, regresa el índice de su posición dentro del
 *       arreglo. Implementación iterativa en paralelo.
 *
 *
 * @param arreglo El arreglo para realizar la búsqueda.
 * @param tamanio El tamaño del arreglo para realizar la búsqueda.
 * @param elemento El elemento que estamos buscando.
 * @return int El índice del elemento encontrado, -1 si no se encontró.
 */
int busqueda_fibonacci_i_p(int *arreglo, int tamanio, int elemento)
{
  // Variables locales.
  pthread_t hilos[NUMERO_MAXIMO_HILOS];                     // Arreglo de hilos.
  int tamanio_sub_arreglos = tamanio / NUMERO_MAXIMO_HILOS, // Tamaño de los subarreglos.
      resultado_final = -1;                                 // Resultado final.
  resultado_hilo *resultados_hilos[NUMERO_MAXIMO_HILOS];    // Arreglo de resultados de los hilos.
  datos_hilo datos_para_los_hilos[NUMERO_MAXIMO_HILOS];     // Datos para los hilos.

  // Iniciamos el arreglo de hilos.
  for (int i = 0; i < NUMERO_MAXIMO_HILOS; i++)
  {
    // Asignamos datos para hilos.
    datos_para_los_hilos[i].arreglo = crear_arreglo(tamanio_sub_arreglos);
    datos_para_los_hilos[i].num_elementos = tamanio_sub_arreglos;
    datos_para_los_hilos[i].elemento_buscado = elemento;

    // Copiamos los datos en el subarreglo.
    copiar_arreglo_rango(arreglo, datos_para_los_hilos[i].arreglo, i * tamanio_sub_arreglos, (i + 1) * tamanio_sub_arreglos);

    // Creamos el hilo.
    pthread_create(&hilos[i], NULL, busqueda_fibonacci_hilo, (void *)&datos_para_los_hilos[i]);
  }

  // Esperamos a que todos los hilos terminen.
  for (int i = 0; i < NUMERO_MAXIMO_HILOS; i++)
  {
    // Esperamos a que el hilo en cuestión termine.
    pthread_join(hilos[i], (void *)&resultados_hilos[i]);

    // Limpiamos la memoria de los datos para los hilos.
    free(datos_para_los_hilos[i].arreglo);

    // Verificamos si el hilo encontró el elemento.
    if (resultados_hilos[i]->indice != -1)
    {
      // Ajustamos el índice del elemento encontrado.
      resultado_final = resultados_hilos[i]->indice + i * tamanio_sub_arreglos;
    }

    // Limpiamos la memoria de los resultados de los hilos.
    free(resultados_hilos[i]);
  }

  // El elemento no se encuentra dentro del arreglo.
  return resultado_final;
}

/**
 * @brief Función que se ejecuta en paralelo para buscar un elemento dentro de un
 *       arreglo.
 *
 * @param datos Los datos para el hilo de ejecución del algoritmo de búsqueda fibonacci iterativa.
 * @return void* El índice resultante del algoritmo.
 */
void *busqueda_fibonacci_hilo(void *datos)
{
  // Obtenemos los datos del hilo.
  datos_hilo *d = (datos_hilo *)datos;

  // Creamos la estructura para almacenar el resultado del hilo.
  resultado_hilo *resultado = (resultado_hilo *)malloc(sizeof(resultado_hilo));

  // Buscamos el elemento dentro del arreglo.
  resultado->indice = busqueda_fibonacci_i(d->arreglo, d->num_elementos, d->elemento_buscado);

  // Regresamos el índice del elemento encontrado.
  return (void *)resultado;
}
