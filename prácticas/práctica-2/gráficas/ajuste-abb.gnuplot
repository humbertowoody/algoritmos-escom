set title 'Ajustes a la función de comportamiento temporal de ABB'
set grid
set xlabel 'Tamaño del Problema (n)'
set ylabel 'Tiempo de ejecución'
set xrange [0:]
set yrange [0:]
plot \
   + 2358.062542*x**1 + 41794.700000*x**0 title 'Polinomio grado 1', \
   + -840.312500*x**2 + 2358.062542*x**1 + 42550.981250*x**0 title 'Polinomio grado 2', \
   + -1189.781410*x**3 + -840.312500*x**2 + 4259.549558*x**1 + 42550.981250*x**0 title 'Polinomio grado 3', \
   + -4004.842665*x**6 + -1411.402882*x**5 + 11885.619755*x**4 + 2787.808530*x**3 + -8204.586079*x**2 + 2136.496347*x**1 + 42895.165771*x**0 title 'Polinomio grado 6', \
  3256.481714*log(x)+-8113.981836 title 'Logarítmico', \
  0.000000 * exp(10.535643*x) title 'Exponencial', \
  1 / (-0.000000*x + 0.000027) title 'Inverso'