%% Aproximaciones de la función de complejidad.
% Este programa genera una serie de aproximaciones para distintas funciones
% de complejidad para varios escenarios. La salida está en formato .gnuplot
% para que pueda utilizarse como script.
%
%% Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)

%% Variables del programa.
% Las siguientes son las variables que requiere el programa para su
% ejecución.

% Valores de x.
x=[100 1000 5000 10000 50000 100000 200000 400000 600000 800000 1000000 2000000 3000000 4000000 5000000 6000000 7000000 8000000 9000000 10000000]; 

% Valores de y.
y = [0.00019598 0.000200033 0.000213862 0.000285149 0.000658989 0.001036882 0.001904011 0.003672838 0.005422115 0.007018089 0.009650946 0.017385006 0.025998831 0.034788847 0.043009043 0.052939892 0.060312033 0.068772078 0.078185082 0.085973978];

% Título del Algoritmo.
titulo = "heap-sort";

%% Imprimimos la configuración estándar de GNUPlot.
%fprintf('set terminal png size 1024,1024\n');
%fprintf('set output "complejidad-%s.png"\n', titulo);
fprintf("set title 'Ajustes a la función de comportamiento temporal de %s'\n", titulo);
fprintf("set grid\n");
fprintf("set xlabel 'Tamaño del Problema (n)'\n");
fprintf("set ylabel 'Tiempo de ejecución'\n");
fprintf("set xrange [0:%i]\n",max(x));
fprintf("set yrange [0:%i]\n",max(y));
fprintf("plot \\\n");

%% Ajuste polinomial con grados 1, 2, 3 y 6.
for grado = [1,2,3,6]
    fprintf("  ");
    [p,~,mu] = polyfit(x,y,grado);	%%FUNCION QUE REALIZA EL AJUSTE POLINOMIAL
    for i = 1:grado+1
        fprintf(" + %f*x**%i", p(i), grado-i+1);
        %for j = 1:grado-i+1
        %    fprintf("*x");
        %end
    end
    fprintf(", \\\n");
end

%% Ajuste logarítmico.
p = polyfit(log(x),y,1);
fprintf('  %f*log(x)+%f, \\\n',p(1),p(2));

%% Ajuste exponencial.
p = polyfit(x, log(y), 1);
fprintf("  %f * exp(%f*x), \\\n",p(1), p(2));

%% Ajuste inverso.
p = polyfit(x,1./y,1);
fprintf("  1 / (%f*x + %f)\n", p(1), p(2));
