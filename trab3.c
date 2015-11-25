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
	if(variavel == NULL){printf("---Erro no malloc\n"); exit(0);}

struct Node {
	int chave;
	struct Node *direita;
	struct Node *esquerda;
};

typedef struct Node Node;

void init(Node **raiz) {
	*raiz = NULL;
}

void set_folha(Node **folha, int x) {
	MALLOC((*folha), Node, 1);
	(*folha)->chave = x;
	(*folha)->esquerda = NULL;
	(*folha)->direita = NULL;
}

void insere(Node **raiz, int x) {
	if (*raiz == NULL) {
		set_folha(raiz, x);
		return;
	}
	if ((*raiz)->chave < x) {
		insere(&((*raiz)->direita), x);
		return;
	}
	if ((*raiz)->chave > x) {
		insere(&((*raiz)->esquerda), x);
		return;
	}
	return;// caso a chave já seja o x. Estou simplesmente ignorando
}

void print_three(Node *raiz) {
	if (raiz == NULL) return;
	printf("%d ", raiz->chave);
	print_three(raiz->esquerda);
	print_three(raiz->direita);
}

Node* menor_dos_maiores(Node *raiz, Node ***pai) {
	if (raiz->direita == NULL) { **pai = NULL; return raiz;}
	*pai = &(raiz->direita);
	raiz = raiz->direita;
	while (raiz->esquerda != NULL) {
		*pai = &(raiz->esquerda);
		raiz = raiz->esquerda;
	}
	return raiz;
}

void remover(Node **three, int x) {

	Node* raiz = *three;
	Node** pai_raiz = NULL;

	while (1) {

		if (raiz == NULL) {
			printf("O valor %d não existe na árvore\n", x);
			return;
		}
		else if (raiz->chave > x) {
			pai_raiz = &(raiz->esquerda);
			raiz = raiz->esquerda;
		}
		else if (raiz->chave < x) {
			pai_raiz = &(raiz->direita);
			raiz = raiz->direita;
		}
		else {
			break;// caso de já ter achado
		}
	}

	if (pai_raiz == NULL) {// se entrar, é pq ñ houve interação no while, pro isso x é o unico elemento da arvore
		free(*three);
		*three = NULL;
		return;
	}

	Node *menor;
	Node **pai_menor;
	menor = menor_dos_maiores(raiz, &pai_menor);

	if (menor == raiz) {
		*pai_raiz = raiz->esquerda;
		free(raiz);
		return;
	}

	raiz->chave = menor->chave;
	*pai_menor = menor->direita;
	free(menor);
}


int main(int argc, char const *argv[]) {

	Node *raiz;
	int in;
	char comand;

	init(&raiz);
	while (1) {
		scanf("%c", &comand);		
		switch (comand) {
		
			case 'e':
				return 0;
			break;
			case'p':
				print_three(raiz);
				printf("\n");
			break;
			case 'i':
				scanf("_%d", &in);
				insere(&raiz, in);
			break;
			case 'r':
				scanf("_%d", &in);
				remover(&raiz, in);
			break;
		}
	
	}

	return 0;
}











