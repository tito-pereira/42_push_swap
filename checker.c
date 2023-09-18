/*
se de facto fizer bonus, compensa? Perco tempo?

nao parece muito dificil, a parte que estou curioso para ver como se faz e a leitura do stdin
provavelmente usar a get_next_line e a funcao read no file 0 (stdin)
acho que sim, read/get_next_line

1 - o mesmo tratamento de erros da push_swap
2 - as mesmas funções
acho que temos que colocar os argumentos na mesma a correr o checker, por isso a primeira parte, erros e criar array,
vai ser igual
3 - read para um buffer, aplicar a get_next_line, ja nao me lembro bem dela
- ou read do file 1 para o file atual, eu e q defino o size por isso (3 ou 4? o num caracteres das regras)
ou read 1 em 1, ate preencher as condicoes das regras ou ate ler 0
4 - aplicar as regras lidas nas minhas stacks
5 - o actual checker (percorrer e ver se esta sempre em ordem crescente)
*/

char    **chest;
char    *shovel;
r = 1;
while (r != 0) {
    while (chest != rules) {
        read(1, 1, chest);
    }
}

/*
se colocarmos uma regra mal tambem da mensagem de erro acho eu
get_next_line(); e colocar as regras num char**
*/

char    **orders;
int rule = -1;
for (int i = 0; orders[i] != NULL; i++) {
    rule = check_rule(orders[i]); //adicionar ordem zero para erro;
    if (order == 0) {
        printf(error message, KO);
        return NULL;
    }
    else
        apply_rule(order, sta, stb);
}
checker(sta, stb); //stb tem que ser NULL

int check_rule(char *text) {
    int order = 0;
    if (text = "sa")
        order = 1;
    else if (text = "sb")
        order = 2;
    else if (text = "ss")
        order = 3;
    else if (text = "pa")
        order = 4;
    else if (text = "pb")
        order = 5;
    else if (text = "ra")
        order = 6;
    else if (text = "rb")
        order = 7;
    else if (text = "rr")
        order = 8;
    else if (text = "rva")
        order = 9;
    else if (text = "rvb")
        order = 10;
    else if (text = "rvr")
        order = 11;
    return (order);
}

void apply_rule(int order, list **sa, list **sb) {
    if (text = "sa")
        order = 1;
    else if (text = "sb")
        order = 2;
    else if (text = "ss")
        order = 3;
    else if (text = "pa")
        order = 4;
    else if (text = "pb")
        order = 5;
    else if (text = "ra")
        order = 6;
    else if (text = "rb")
        order = 7;
    else if (text = "rr")
        order = 8;
    else if (text = "rva")
        order = 9;
    else if (text = "rvb")
        lst_rvb();
    else if (text = "rvr")
        lst_rvr(sa, sb);
}