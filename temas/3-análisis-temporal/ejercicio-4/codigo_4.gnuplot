set title "Mejor Caso vs Caso Medio vs Peor Caso para Código 1 \"Suma de Dos Mayores\""
set grid
set xlabel "Tamaño del Problema"
set ylabel "Cantidad de Operaciones (aproximadas)"
plot [n=0:500000] \
  n**2 + n title 'Mejor Caso (n^2 + n)', \
  (3*n**2 + 4*n)/2 title 'Caso Medio (3n^2 + 4n)/2', \
  2*n**2 + 3*n title 'Peor Caso (2n^2 + 3n)' 
