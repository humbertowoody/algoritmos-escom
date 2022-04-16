set title 'Ajustes a la función de comportamiento temporal de Búsqueda Exponencial'
set grid
set xlabel 'Tamaño del Problema (n)'
set ylabel 'Tiempo de ejecución'
set xrange [0:10000000]
set yrange [0:58889]
plot \
   + 3206.758809*x**1 + 54526.100000*x**0 title 'Polinomio grado 1', \
   + -1088.854167*x**2 + 3206.758809*x**1 + 55506.068750*x**0 title 'Polinomio grado 2', \
   + 1319.437733*x**3 + -1088.854167*x**2 + 1098.057415*x**1 + 55506.068750*x**0 title 'Polinomio grado 3', \
   + -2072.466363*x**6 + -229.455302*x**5 + 6906.950357*x**4 + 1966.084492*x**3 + -6591.065083*x**2 + 752.907337*x**1 + 56118.549072*x**0 title 'Polinomio grado 6', \
  4647.497155*log(x)+-16701.217462 title 'Logarítmico', \
  0.000000 * exp(10.795367*x) title 'Exponencial', \
  1 / (-0.000000*x + 0.000020) title 'Inverso'