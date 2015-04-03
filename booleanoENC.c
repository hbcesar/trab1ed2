#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADLeDoc.h"
#include "TADHashControle.h"
#include "TADHashEnc.h"


// int tamHash;

// Palavra** hash;

// void alocaHash(int nmrPalavras){
// 	int i;

// 	tamHash = tamanho_hash(nmrPalavras);

// 	hash = (Palavra**)malloc(tamHash*sizeof(Palavra*));

// 	for(i=0;i<tamHash;i++){
// 		hash[i]=NULL;
// 	}
// }


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

Palavra* busca(Palavra** hash, char* palavra, int tamHash){
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


void imprimeHash(Palavra** hash, int tamHash){
	int i;
	int contador;
	Palavra* aux = hash[0];

	printf("O tamanho da hash é %d\n", tamHash);

	for(i=0; i<tamHash; i++){

		if(hash[i] != NULL){
			aux = hash[i];
			while (aux!= NULL){
			//	printf("\nPosicao no HASH: %d \t Palavra: %s\n", i, aux->palavra);
			//	printf("\tDocumento: %s\t", aux->doc->nomeDoc);
				printf("X");
				aux=aux->proximo;
			}
				printf("\n");
		} else{
			printf("-\n");
		}
			
	}
}

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
}

// void removeHash (char* palavra){
// 	short int flag=0;
// 	Palavra *aux, *aux2;
// 	int n;

// 	//novamente acha o N

// 	aux=hash[n];

// 	if (aux == NULL){
// 		printf("Palavra a ser removido não existe, queridinha!");
// 		return;
// 	}

// 	//para o caso de ser o primeiro
// 	if(strcmp(aux->palavra, palavra)==0){
// 		hash[n] = aux->proximo;
// 		flag = 1;
// 	} else {
// 		//caso nao for o primeiro, percorre o resto da lista
// 		while(aux->proximo != NULL){
// 			aux2=aux;
// 			aux=aux->proximo;

// 			if(strcmp(aux->palavra, palavra)==0){
// 				aux2->proximo=aux->proximo;
// 				flag = 1;
// 			}
// 		}	
// 	} 
		
// 	//aviso, caso Palavra a ser removido nao tenha sido encontrado
// 	if(!flag){
// 		printf("Palavra a ser removido não existe, queridinha!");
// 	} 
// }
