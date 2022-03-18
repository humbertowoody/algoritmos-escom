/**
 * @file mejor_caso.c
 * @author Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)
 * @brief Análisis para el mejor caso de algoritmo "Producto de Dos Mayores"
 * @version 0.1
 * @date 2022-03-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "producto_dos_mayores.h"
#include "librerias/cont_operaciones.h"
#include "librerias/genera_casos.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definimos el número de pruebas a realizar.
#ifndef NUMERO_PRUEBAS
#define NUMERO_PRUEBAS 1000
#endif // NUMERO_PRUEBAS

// Prototipos de funciones.
int modelo_matematico(int);

// Función principal.
int main(int argc, char *argv[])
{
  // Declaración de variables.
  int n,                                        // Tamaño del problema.
      *arreglo;                                 // Arreglo de enteros.
  cont_operaciones operaciones[NUMERO_PRUEBAS]; // Contador de operaciones.

  // Validación de argumentos de programa.
  if (argc != 2)
  {
    // Mostramos mensaje de error y salimos.
    printf("Uso: %s <tamaño del problema>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Convertimos argumento a entero.
  n = atoi(argv[1]);

  // Iteramos 1000 veces.
  for (int i = 0; i < NUMERO_PRUEBAS; i++)
  {
    // Generamos el arreglo.
    arreglo = genera_arreglo_enteros_ordenados(n);

    // Intercambiamos los últimos dos valores por los primeros dos para tener
    // el mejor caso para nuestro algoritmo.
    arreglo[0] = arreglo[n - 1];
    arreglo[1] = arreglo[n - 2];
    arreglo[n - 1] = n + 1;
    arreglo[n - 2] = n + 2;

    // Iniciamos contador de operaciones.
    inicializa_cont_operaciones(&operaciones[i]);

    // Llamamos al algoritmo.
    producto_dos_mayores_cont(arreglo, n, &operaciones[i]);

    // Limpiamos el arreglo.
    free(arreglo);
  }

  // Imprimimos resultados en formato CSV.
  printf("iteración,n,modelo,op_asignaciones,op_comparaciones,op_aritmeticas,op_totales\n");
  for (int i = 0; i < NUMERO_PRUEBAS; i++)
  {
    printf("%i,%i,%i,%i,%i,%i,%i\n", i, n, modelo_matematico(n),
           operaciones[i].asignaciones, operaciones[i].comparaciones,
           operaciones[i].aritmeticas, total_operaciones(operaciones[i]));
  }

  return 0;
}

/**
 * @brief Modelo matemático para el mejor caso del algoritmo.
 *
 * @param n La n de nuestro prpoblema.
 * @return int El resultado del modelo.
 */
int modelo_matematico(int n)
{
  // Modelado matemático para el mejor caso.
  return floor((2 * n) - 1);
}