/*
	Estmaos experimentando o git \o/ finalmente !! 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <math.h>

#define MALLOC(variavel,tipo,tamanho)\
	variavel = (tipo*) malloc(sizeof(tipo)*tamanho);\
	if(variavel == NULL){printf("Erro no malloc\n"); exit(0);}


struct node {
	int n;
	struct node *direita;
	struct node *esquerda;
};
struct three {
	struct node *raiz;
};

typedef struct node Node;
typedef struct three Three;

void init_three(Three *T){
	T->raiz = NULL;
}
void init_node(Node *folha, int x){
	MALLOC(folha,Node,1);
	folha->n = x;
	folha->esquerda = NULL;
	folha->direita = NULL;
}
void add(int x,Three* t){
	
	if(t->raiz == NULL){
		init_node(t->raiz,x);
		return;
	}

	Node raiz = *(t->raiz);
	
	while(1){
		if( x > raiz.n ){
			if( raiz.direita == NULL ){
				init_node(raiz.direita,x);
			 	return;
			}
			raiz = *(raiz.direita);
		}
		else{
			if( raiz.esquerda == NULL ){
				init_node(raiz.esquerda,x);
			 	return;
			}
			raiz = *(raiz.esquerda);
		}
	}
	return;
}

void print_three(Node *T){
	if(T == NULL) return;
	printf("%d\n", T->n);
	print_three(T->esquerda);
	print_three(T->direita);
}

Node* busca_pai(int x){
	Node* pai;
	if (raiz == NULL){
		return NULL;
	}
	while(raiz->n != x){
		pai = raiz;
		if(raiz->n > x){
			raiz = raiz->esquerda;
		}
		else {
			raiz = raiz->direita;
		}
		if (raiz == NULL){
			return NULL;
		}	
	}
	return pai;
}

void inverte(Node** a, Node** b){
	Node* aux = *a;
	*a = *b;
	*b = aux;
}

Node* menor_dos_maiores(int x, Node* raiz){

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


