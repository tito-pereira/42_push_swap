/*
este ficheiro é uma copia exata do teste 4 mas aqui vou experimentar usar as listas como **list, para permitir
uma melhor mudança do pointer para o primeiro elemento
however, ainda não vejo como é que isso é suposto ajudar me na função push que leva dois argumentos e quero retornar os dois
tenho que criar uma struct pair na mesma
para ligar uns pointers aos outros tenho que trazer comigo ambas as heads ou listas

int *p; -> define logo um tipo de iteração aritmética por tamanho, necessita de uma morada;
a = 5;
p = &a;
*p = 5; *(p + 0) = 5
int **t;
t = &a;
*t = &p;
**t = 5;

tou a usar (int *) num calculo mas é um valor não fixo
              ||
function->retorno, ambos (int *) para preencher ali
Parametros: definidos antes, para poder trazer outras moradas/valores definidos externamente e não fixos
Definidos dentro da função
parametros é o mesmo que definir dados, mas apenas são dados que variam e tu trazes para dentro do cálculo
logo, um int * = & algo (&a)
logo, um int ** = & *algo (&p) p(int *)
logo, um int *** = & **algo (%h) h(int **), *(int **) = (int *); *h = &p; **h = a = 5
logo, um int **** = & ***algo

pointer é tipo uma funcao que chama uma morada e realiza iterações aritméticas para segurar
logo, se chamas multiplos pointers, a funçao torna-se recursiva e a funçao vai chamar uma morada que por sua vez exige outro pointer
que exige outra morada. mas é atraves de pointers que se mantém a integridade estrutural
pointers não são propriamente o que agrupa blocos grandes de memória, mas são uma referencia, um ponto de ligação entre varios grupos de
dados e de manipular mais facilmente entre eles
Simple pointer arithmetic only works for contiguous data structures. A linked list is non-contiguous.
Pointers nao definem os blocos de data contigues, arrays, estruturas. Os pointers são é essenciais na criação, manutencao e
funcionamento das grandes estruturas ligadas como listas, arvores, stacks, etc
E mesmo dentro de arrays para navegar mais rapidamente entre eles com uma referencia direta ao index

quando passas um argumento para uma função como parametro exterior, a funcao realiza uma copia exata dessa unidade de memoria
que passaste como memoria. Isto é, se passas um int, aloca nova memoria e copia a data desse int, se passas um point, aloca 
memoria nova e copia a data desse pointer (a morada)
ATENCAO, isto significa que o pointer em si é uma copia para o primeiro elemento, MAS OS ELEMENTOS SAO OS ORIGINAIS, ou seja, tu alocas nova
memoria e copias a data (morada para o qual aponta). Isto significa que se alteras/manipulas a data para a qual esse pointer aponta
(atraves de dereferenciaçao, incluindo manipular strings que é uma forma de dereferenciacao)

fazer uma espécie de tutorial de pointers associado a isto também para demonstrar o meu conhecimento aqui
*/