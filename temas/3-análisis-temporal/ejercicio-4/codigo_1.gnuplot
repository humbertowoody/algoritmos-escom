set title "Mejor Caso vs Caso Medio vs Peor Caso para Código 1 \"Suma de Dos Mayores\""
set grid
set xlabel "Tamaño del Problema"
set ylabel "Cantidad de Operaciones (aproximadas)"
plot [n=0:500000] \
  3*n - 2 title 'Mejor Caso (3n-2)', \
  (14*n - 8)/4 title 'Caso Medio (14n-8)/4', \
  4*n - 2 title 'Peor Caso (4n-2)'
