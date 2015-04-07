#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADLeDoc.h"
#include "TADHashControle.h"
#include "TADHashEnc.h"


void insereHash (Palavra** hash, Palavra* palavra, int tamHash){
	int n = 0;
	Palavra* aux;

	n = chaveHash(palavra->palavra, tamHash);

	/*
	verifica se existe colisao, caso exista,
	vai até o fim da lista encadeada para inserir o Palavra
	*/
	if(hash[n] == NULL){
		hash[n] = palavra;
	} else {
		aux = hash[n];
		while (aux->proximo != NULL){
			aux = aux->proximo;
		}
		aux->proximo = palavra;
	}
}

Palavra* buscaENC(Palavra** hash, char* palavra, int tamHash){
	int chave =0;

	chave = chaveHash(palavra, tamHash);

	Palavra* aux = hash[chave];
	
	while(aux != NULL && strcmp(aux->palavra, palavra) != 0){
		aux=aux->proximo;
	}
	if(aux == NULL)
		return NULL;
	else
		return aux;
}


// void imprimeHash(Palavra** hash, int tamHash){
// 	FILE* arq;
// 	int i;
// 	int contador;
// 	Palavra* aux = hash[0];

// 	arq = fopen("indice.txt", "w");

// 	for(i=0; i<tamHash; i++){

// 		if(hash[i] != NULL){
// 			aux = hash[i];
// 			while (aux!= NULL){
// 				fprintf(arq, "%d; %s; ", i, aux->palavra);
// 				Documento* doc = aux ->doc;
// 				while(doc != NULL){
// 					fprintf(arq, "%s; ", doc->nomeDoc);
// 					Posicao* pos = doc->posicao;
// 					while(pos!=NULL){
// 						fprintf(arq, "%d; ", pos->posicao);
// 						pos = pos->proximo;
// 					}
// 					doc=doc->proximo;
// 				}
// 				aux=aux->proximo;
// 			}
// 				fprintf(arq, "\n");
// 		} else{
// 			fprintf(arq,"%d;-\n", i);
// 		}		
// 	}
// }

void populaHashENC(Palavra* lista, Palavra** hash, int tamHash){
	Palavra* aux;
	Palavra* aux2;

	aux=lista;

	while(aux!=NULL){
		aux2 = aux->proximo;
		aux->proximo = NULL;
		insereHash(hash, aux, tamHash);
		aux=aux2;
	}

	free(lista);
}