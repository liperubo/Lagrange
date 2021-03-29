# Lagrange
O que fazemos é aproximar uma função desconhecida por outra. No caso, criaremos uma função polinômial. É garantido que sempre é possível aproximar uma função contínua por um polinômio. Além disso, polinômios têm derivadas e integrais muito fáceis de serem calculadas.
Primeiramente, vamos definir as funções:
Para os pontos (x0, y0) e (x1, y1), utilizamos a seguinte formula

L0(x) = x − x1 / x0 − x1

L1(x) = x − x0 / x1 − x0
       
Depois, definimos o polinômio
P(x) = L0(x) * f(x0) + L1(x) * f(x1).

Para aumentar o numero de pontos, multiplicamos os valores mais vezes:
Para os pontos (x0, y0), (x1, y1) e (x2, y2), utilizamos a seguinte formula

L0(x) = x − x1 * x − x2 / x0 − x1 * x0 − x2

L1(x) = x − x0 * x − x2 / x1 − x0 * x1 − x2

L2(x) = x − x0 * x − x1 / x2 − x0 * x2 − x1
       
Depois, definimos o polinômio
P(x) = L0(x) * f(x0) + L1(x) * f(x1) + L2(x) * f(x2).
