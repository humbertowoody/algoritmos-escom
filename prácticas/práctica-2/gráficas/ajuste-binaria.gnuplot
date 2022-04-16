set title 'Ajustes a la función de comportamiento temporal de Búsqueda Binaria'
set grid
set xlabel 'Tamaño del Problema (n)'
set ylabel 'Tiempo de ejecución'
set xrange [0:10000000]
set yrange [0:50903]
plot \
   + 2928.967302*x**1 + 47505.000000*x**0 title 'Polinomio grado 1', \
   + -1514.965278*x**2 + 2928.967302*x**1 + 48868.468750*x**0 title 'Polinomio grado 2', \
   + 142.762124*x**3 + -1514.965278*x**2 + 2700.807471*x**1 + 48868.468750*x**0 title 'Polinomio grado 3', \
   + 860.224650*x**6 + -1003.243159*x**5 + -3292.105767*x**4 + 2970.083755*x**3 + 1719.794981*x**2 + 1191.714186*x**1 + 48370.015137*x**0 title 'Polinomio grado 6', \
  4310.079671*log(x)+-18551.073364 title 'Logarítmico', \
  0.000000 * exp(10.651261*x) title 'Exponencial', \
  1 / (-0.000000*x + 0.000024) title 'Inverso'