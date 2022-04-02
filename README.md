# RotatitingCube3D



Escola do Mar, Ciências e Tecnologias

Curso de [Ciência da Computação]

Disciplina Computacao Grafica 






Matrizes de rotação





 Matriz em 3 dimensões, decomposição nos diferentes ângulos e como é calculada.




Acadêmico(s):

Matheus Henrique Reimer - matheusreimer1@gmail.com







Itajaí, 03, 2022


Para melhor entender como funciona a rotação em 3d é importante que se entenda como funciona uma rotação em duas dimensões.Supondo que 2 pontos partam da mesma origem em um plano e que P’ seja o ponto de destino e P, o ponto inicial:

Consegue-se observar um triângulo formado pelo ângulo entre os pontos e os próprios (P,P’). Com isso, pode-se calcular o raio a partir do teorema de pitágoras 

E então, calcular o trajeto para que P chegue até P’.


Com isso explicado, a matriz de rotação é uma matriz quadrada usada para fazer rotações no espaço euclidiano, girando um elemento sobre seus eixos.Então se há 3 eixos de rotação, há 3 matrizes de rotação que permitem o giro em torno de cada um desses eixos.
Dessa forma, uma rotação em um plano x-y por um ângulo theta mensurado no sentido anti-horário a partir do eixo x é representado por uma 2x2 ortogonal.

Logo, se considerarmos esta rotação ocorrendo em um espaço com 3 dimensões, será considerada uma rotação anti horário no eixo de “z” e sua representação na matriz será a seguinte:


Onde o z e o theta são argumentos de R e nˆ o eixo de rotação. Normalmente, um ângulo positivo leva a um sentido anti horário. Esta é a convenção chamada de regra da mão direita, e ela tem este nome pois sua regra é exatamente essa:
Curva-se os dedos da mão direita em volta do eixo onde os dedos apontam na direção de theta. Então, o dedão aponta perpendicularmente ao plano de rotação de nˆ.
De fato, para qualquer escolha de nˆ, as R(nˆ, π) são as únicas matrizes de rotação não triviais cujo quadrado é igual ao operador identidade. Finalmente, se θ = 0 então R(nˆ, 0) = I portanto, o operador identidade(às vezes chamado de rotação trivial), independentemente da direção de nˆ.
Para aprender mais sobre as propriedades de uma rotação tridimensional geral, considera-se a representação matricial R(nˆ, θ) em relação à base padrão Bs ={xˆyˆ,zˆ}.
Podemos definir um novo sistema de coordenadas no qual o vetor unitário nˆ aponta no
direção do novo eixo z, a nova base correspondente será indicada por B′. A representação matricial da rotação em relação a B′ é então dado por R(zˆ, θ). Portanto,
existe uma matriz ortogonal especial 3 × 3 real P tal que 
R(nˆ, θ) = P R(zˆ, θ)P −1 , onde nˆ = Pzˆ,
e R(zˆ, θ) é dado pela equação. A existência da matriz P na equação. [mesmo sem
conhecer sua forma explícita] é suficiente para fornecer um algoritmo simples para determinar o eixo de rotação nˆ.
Agora, para determinar a rotação do angulo theta, nota-se que as propriedades do traço implicam que Tr(P RP -1) = Tr(P−1P R) = Tr R. Portanto, segue imediatamente da equação:
Tr R(nˆ, θ) = Tr R(zˆ, θ) = 2 cos θ + 1
após tomar o traço da equação. Por convenção, 0 ≤ θ ≤ π, o que implica que sen θ ≥ 0.
Assim, o ângulo de rotação é determinado exclusivamente pela equação. Para identificar nˆ, observamos que qualquer vetor paralelo ao eixo de rotação não é afetado pela rotação em si. Esta última afirmação pode ser expressa como uma equação de autovalor,
R(nˆ, θ)nˆ = nˆ .

Apesar de serem interessantes para um conhecimento do processo geral. Para o programa feito, não foi preciso saber todos estes conceitos mencionados. Foi preciso apenas do seguinte entendimento:
Supondo que se queira rotacionar o elemento da primeira imagem de forma que o ponto 1 chegue até o ponto 2, pode se afirmar que a rotação será em torno do eixo Z e sendo assim:
X1 = d*cos(θ) e Y1 = d*sen(θ) 
Y2 = d*cos(θ + β) e Y2 = d*cos(θ + β)
Com isto, pode-se substituir as identidades trigonométricas ao ponto de que se chegue nisso:
X2 = X1*cos(β) - Y1*sin(β)
Y2 = X1*sin(β) +Y1*cos(β)
Partindo disso, e colocando esta fórmula em um sistema de equações, obtém-se a seguinte matriz.

E a partir dela, é possível calcular também as matrizes em outros eixos:

PARA VISUALIZAÇÃO DAS IMAGENS COMENTADAS VISITE:<a href="https://docs.google.com/document/d/1X0nYB5ijfxa-HXJip-Id5m50b74ft55w8A2FCcVuVCI/edit?usp=sharing"> link </a>
