#include "push_swap.h"

//helper functions for lists, already written in my libfc

list	create_node(int supply) {
    list    new;
    new = malloc(sizeof(list));
    if (!new)
        return;
    new.data = supply;
    new.next = NULL;
	return (new);
}

void	add_front(list *begin, list new) {
	new.next = begin;
}

void	ad_front(list *begin, int supply) {
	list	new;
	new = create_node(supply);
	new.next = begin;
}

void	add_back(list *begin, list new) {
	ez;
}

void	ad_back(list) {
	ez;
}

/*
desde o porque de usar malloc, ate pointers como parametros de funções etc, ainda há certas coisas que
eu não percebo do funcionamento e compilação da linguagem C que só irei perceber quando estudar low level
como assembly (e o seu assembler) e machine code, é o "abstract data" da linguagem C 
*/