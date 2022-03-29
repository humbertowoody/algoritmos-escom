#include "librerias/ordenamientos.h"
#include "librerias/genera_casos.h"
#include <stdio.h>
#include <stdlib.h>

#define NUM_ELEMENTOS 10

int arreglos_iguales(int*,int*,int);
int imprimir_arreglo(int*,int);
void copiar_arreglo(int*,int*,int);
int *iniciar_arreglo(int);

int main(int argc, char *argv[])
{

  int *desordenados = genera_arreglo_enteros_aleatorios(NUM_ELEMENTOS, 0, NUM_ELEMENTOS + 1),
      *ordenados_ref = iniciar_arreglo(NUM_ELEMENTOS),
      *ordenados = iniciar_arreglo(NUM_ELEMENTOS);

  copiar_arreglo(desordenados,ordenados,NUM_ELEMENTOS);
  copiar_arreglo(desordenados,ordenados_ref,NUM_ELEMENTOS);
  ordenar_quick(ordenados_ref,NUM_ELEMENTOS);


  //ordenar_burbuja_simple(ordenados,NUM_ELEMENTOS);
  //ordenar_burbuja_optimizada_1(ordenados,NUM_ELEMENTOS);
  //ordenar_burbuja_optimizada_2(ordenados,NUM_ELEMENTOS);
  //ordenar_insercion(ordenados,NUM_ELEMENTOS);
  //ordenar_seleccion(ordenados,NUM_ELEMENTOS);
  //ordenar_shell(ordenados,NUM_ELEMENTOS);

  //ordenar_heap(ordenados,NUM_ELEMENTOS); // ERROR
  //ordenar_merge(ordenados,0,NUM_ELEMENTOS); // ERROR
  ordenar_tree(ordenados,NUM_ELEMENTOS); // ERROR

  // Resultados
  printf("   Desordenados: ");
  imprimir_arreglo(desordenados,NUM_ELEMENTOS);
  printf("\n");
  printf("      Ordenados: ");
  imprimir_arreglo(ordenados,NUM_ELEMENTOS);
  printf("\n");
  printf("Ordenados (ref): ");
  imprimir_arreglo(ordenados_ref, NUM_ELEMENTOS);
  printf("\n");
  printf("Veredicto: %s\n", arreglos_iguales(ordenados,ordenados_ref,NUM_ELEMENTOS) == 1 ? "Funciona" : "No Funciona");

  return 0;
}

int imprimir_arreglo(int *arreglo, int tamanio)
{
  printf("[ ");
  for(int i = 0; i < tamanio; i++)
  {
    printf("%i%c", arreglo[i], (i+1) < tamanio ? ',' : ' ');
  }
  printf("]");
}

int arreglos_iguales(int *arreglo_a,int *arreglo_b,int tamanio)
{
  for (int i = 0; i < tamanio; i++)
  {
    if (arreglo_a[i] != arreglo_b[i])
    {
      return 0;
    }
  }

  return 1;
}

void copiar_arreglo(int *origen,int *destino,int tamanio)
{
  for (int i = 0; i < tamanio; i++)
  {
    destino[i] = origen[i];
  }
}

int *iniciar_arreglo(int tamanio)
{
  return (int*)malloc(sizeof(int) * tamanio);
}
