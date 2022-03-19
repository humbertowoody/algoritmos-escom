# Makefile
# Con este archivo puedes utilizar el comando `make` para compilar, ejecutar
# y actualizar disintos módulos del proyecto de forma fácil y eficaz.
# Sistemas Operativos ESCOM 2021.

# Configuración del compilador
CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic

# Configuración del linker
#LDFLAGS=-lncurses -lpthread
LDFLAGS=

# Binarios para cada código de la práctica.
CODIGO_1=codigo_1.out
CODIGO_1_OBJS=codigo_1.o librerias/cont_operaciones.o librerias/genera_casos.o
CODIGO_2=codigo_2.out 
CODIGO_2_OBJS=codigo_2.o librerias/cont_operaciones.o librerias/genera_casos.o
CODIGO_3=codigo_3.out
CODIGO_3_OBJS=codigo_3.o librerias/cont_operaciones.o librerias/genera_casos.o
CODIGO_4=codigo_4.out
CODIGO_4_OBJS=codigo_4.o librerias/cont_operaciones.o librerias/genera_casos.o
CODIGO_5=codigo_5.out
CODIGO_5_OBJS=codigo_5.o librerias/cont_operaciones.o librerias/genera_casos.o

# Generar todo
all: $(CODIGO_1) $(CODIGO_2) $(CODIGO_3) $(CODIGO_4) $(CODIGO_5)

# Generar cada código de la práctica
$(CODIGO_1): $(CODIGO_1_OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o$@ $^

$(CODIGO_2): $(CODIGO_2_OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o$@ $^

$(CODIGO_3): $(CODIGO_3_OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o$@ $^
	
$(CODIGO_4): $(CODIGO_4_OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o$@ $^

$(CODIGO_5): $(CODIGO_5_OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o$@ $^
	
# Compilar archivos objeto
%.o: %.c ./librerias/*.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c -o$@ $<

# Limpiar
clean:
	rm -f *.o
	rm -f librerias/*.o
	rm -f $(CODIGO_1) $(CODIGO_2) $(CODIGO_3) $(CODIGO_4) $(CODIGO_5)

# No sé.
.PHONY: all clean

