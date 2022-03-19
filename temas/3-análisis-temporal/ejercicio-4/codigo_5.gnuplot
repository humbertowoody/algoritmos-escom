set title "Mejor Caso vs Caso Medio vs Peor Caso para Código 5 \"Solución de un Polinomio\""
set grid
set xlabel "Tamaño del Problema"
set ylabel "Cantidad de Operaciones (aproximadas)"
plot [n=0:500000] \
  n title 'Mejor Caso (n)', \
  n title 'Caso Medio (n)', \
  n title 'Peor Caso (n)'
