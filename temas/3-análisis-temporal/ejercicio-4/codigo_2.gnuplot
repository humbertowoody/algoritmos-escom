set title "Mejor Caso vs Caso Medio vs Peor Caso para Código 1 \"Suma de Dos Mayores\""
set grid
set xlabel "Tamaño del Problema"
set ylabel "Cantidad de Operaciones (aproximadas)"
plot [n=0:500000] \
  1 title 'Mejor Caso (1)', \
  ((12/pi**2) * log(2) * log(n)) + 0.6 title 'Caso Medio [((12/pi^2) * ln(2) * ln(n)) + 0.6]', \
  log(n) title 'Peor Caso (log(n))'