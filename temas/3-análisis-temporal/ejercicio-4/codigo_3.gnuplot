set title "Mejor Caso vs Caso Medio vs Peor Caso para Código 1 \"Suma de Dos Mayores\""
set grid
set xlabel "Tamaño del Problema"
set ylabel "Cantidad de Operaciones (aproximadas)"
plot [n=0:500000] \
  3*n - 6 title 'Mejor Caso (3n-6)', \
  (15*n - 30)/2 title 'Caso Medio (15n-30)/2', \
  12*n - 24 title 'Peor Caso (12n-24)'
