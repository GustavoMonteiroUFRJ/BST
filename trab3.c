#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <math.h>

#define MALLOC(variavel,tipo,tamanho)\
	variavel = (tipo*) malloc(sizeof(tipo)*tamanho);\
	if(variavel == NULL){printf("Erro no malloc\n"); exit(0);}

struct node
{
	int n;
	struct node *direita;
	struct node *esquerda;
};

typedef struct node Node;

void init_three(Node **T){
	MALLOC((*T),Node,1);
	(*T)->n = 0;
	(*T)->direita = NULL;
	(*T)->esquerda = NULL;
}

void add(int x,Node* no){
	if(x > no->n){
		if(no->direita == NULL){
			init_three(&(no->direita));
		 	no->direita->n = x;
		 	return;
		}
		add(x,no->direita);
		return;
	}
	else{
		if(no->esquerda == NULL){
			init_three(&(no->esquerda));
		 	no->esquerda->n = x;
		 	return;
		}
		add(x,no->esquerda);
		return;
	}
}

void print_three(Node *T){
	if(T == NULL) return;
	printf("%d\n", T->n);
	print_three(T->esquerda);
	print_three(T->direita);
}

void busca(int x){
	return;
}

void inverte(Node** a, Node** b){
	Node* aux = *a;
	*a = *b;
	*b = aux;
}

void menor_maior(int x, Node* pai){
	
}

void retira(int x){

}


int main(int argc, char const *argv[]){

	Node *t;
	init_three(&t);
	add(3,t);	
	add(10,t);	
	add(7,t);	
	add(1,t);
	print_three(t);


	return 0;
}


