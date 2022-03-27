# Makefile
# En este archivo se definen todas las tareas de compilación para la Práctica #1.
# Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)
# (C) 2022.

# Configuración del compilador
CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic

# Configuración del linker
#LDFLAGS=-lncurses -lpthread
LDFLAGS=

# Binarios para cada código de la práctica.
ALGORITMOS_ORDENAMIENTO=algoritmos_ordenamiento.out
ALGORITMOS_ORDENAMIENTO_OBJS=algoritmos_ordenamiento.o librerias/tiempo.o librerias/ordenamientos.o librerias/nodo_arbol.o

# Generar todo
all: $(ALGORITMOS_ORDENAMIENTO) 

# Generar cada código de la práctica
$(ALGORITMOS_ORDENAMIENTO): $(ALGORITMOS_ORDENAMIENTO_OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o$@ $^

# Limpiar
clean:
	rm -f $(ALGORITMOS_ORDENAMIENTO) $(ALGORITMOS_ORDENAMIENTO_OBJS)

# No sé.
.PHONY: all clean

