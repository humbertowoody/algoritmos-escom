set title 'Ajustes a la función de comportamiento temporal de Búsqueda Lineal'
set grid
set xlabel 'Tamaño del Problema (n)'
set ylabel 'Tiempo de ejecución'
set xrange [0:10000000]
set yrange [0:]
plot \
   + 91462261.674198*x**1 + 181664300.100000*x**0 title 'Polinomio grado 1', \
   + -7681263.055556*x**2 + 91462261.674199*x**1 + 188577436.850000*x**0 title 'Polinomio grado 2', \
   + -2848550.074779*x**3 + -7681263.055556*x**2 + 96014762.611891*x**1 + 188577436.850000*x**0 title 'Polinomio grado 3', \
   + 1201905.217094*x**6 + 2162551.410438*x**5 + -4535727.396547*x**4 + -8943013.140558*x**3 + -3304786.332308*x**2 + 99267704.613657*x**1 + 187917757.258301*x**0 title 'Polinomio grado 6', \
  120984885.704068*log(x)+-1672544228.576720 title 'Logarítmico', \
  0.000000 * exp(17.698167*x) title 'Exponencial', \
  1 / (-0.000000*x + 0.000000) title 'Inverso'