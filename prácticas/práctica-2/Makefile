# Makefile
# En este archivo se definen todas las tareas de compilación para la Práctica #2.
# Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)
# (C) 2022.

# Configuración del compilador.
CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic

# Configuración del linker.
#LDFLAGS=-lncurses -lpthread
LDFLAGS=

# Default números de pruebas.
NUM_PRUEBA_DEFAULT=100

# Binarios para cada código de la práctica.
ALGORITMOS_BUSQUEDA=algoritmos_busqueda.out
ALGORITMOS_BUSQUEDA_OBJS=algoritmos_busqueda.o librerias/matematicas.o librerias/tiempo.o librerias/busquedas.o librerias/ordenamientos.o librerias/nodo_arbol.o
TEST_BUSQUEDAS=test_busquedas.out
TEST_BUSQUEDAS_OBJS=test_busquedas.o librerias/matematicas.o librerias/tiempo.o librerias/busquedas.o librerias/ordenamientos.o librerias/nodo_arbol.o librerias/genera_casos.o librerias/arreglo.o

# Generar todo
all: $(ALGORITMOS_BUSQUEDA) $(TEST_BUSQUEDAS)

# Generar cada código de la práctica.
$(ALGORITMOS_BUSQUEDA): $(ALGORITMOS_BUSQUEDA_OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o$@ $^

# Generar binario de las pruebas.
$(TEST_BUSQUEDAS): $(TEST_BUSQUEDAS_OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o$@ $^

# Ejecutar los tests.
tests: $(TEST_BUSQUEDAS)
	./$(TEST_BUSQUEDAS) $(NUM_PRUEBA_DEFAULT)

# Limpiar.
clean:
	rm -f $(ALGORITMOS_BUSQUEDA) $(ALGORITMOS_BUSQUEDA_OBJS) $(TEST_BUSQUEDAS) $(TEST_BUSQUEDAS_OBJS)

# No sé.
.PHONY: all clean

