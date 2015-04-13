#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADLeDoc.h"
#include "TADHashControle.h"
#include "vetorial.h"
#include "TADBuscador.h"
#include "TADHashEnc.h"
#include "booleanoHL.h"
#include "booleanoRH.h"

PalavraBusca* criaPalavraBusca (char* Palavra){

	PalavraBusca* novo = (PalavraBusca*)malloc(sizeof(PalavraBusca));
	novo->nome= (char*)malloc((strlen(Palavra)+1)*sizeof(char));
	strcpy(novo->nome, Palavra);
	novo->proximo = NULL;
	
	return novo;
}

void inserePalavraBusca(Palavra** hash, int tamHash, PalavraBusca* listaPalavras, Documento2* listaDocumentos, char* nomeArq, char* tipo){
	int i, j;
	char* palavra = (char*)malloc(30*sizeof(char));
	FILE* arq;

	if(nomeArq == NULL){
		printf("Arquivo de entrada nao especificado\n");
		return;
	}

	arq= fopen(nomeArq, "r");

	if(arq==NULL)
		return;

	for(i=0, j=0; (palavra[i] = fgetc(arq) != EOF); i++){
		if(palavra[i] == 32 || palavra[i] == 10){
			j++;
			if(listaPalavras == NULL){
				if(normaliza(palavra))
					listaPalavras = criaPalavraBusca(palavra);
			} else { 
				PalavraBusca* aux = listaPalavras;
				while(aux->proximo != NULL)
					aux = aux->proximo;
				aux->proximo = criaPalavraBusca(palavra);
			}
		}
		if (palavra[i]== 10){
			alocaVetores(listaDocumentos, j);
			//aqui entao seria a funcao que efetua a busca pra cada tipo de hash
			//preencheBusca(listaPalavras, listaDocumentos, hash, tamHash);
			i=0;
		}
	}
}

Palavra* buscaPalavra(char* tipo, char* palavra, Palavra** hash, int tamHash){
	Palavra* busca = NULL;

	if(strcmp(tipo, "booleanoENC") == 0)
		busca = buscaENC(hash, palavra, tamHash);
	//else if (strcmp(tipo, "booleanoHL") == 0)
		//busca = buscaHashLinear(hash, palavra, tamHash);
		else if(strcmp(tipo, "booleanoRH") == 0)
			busca = buscaRH(hash, palavra, tamHash);
	 		else if (strcmp(tipo, "booleanoAB") == 0)
	 			printf("Je ne suis tuas nega");
	
	// if(busca != NULL)
	// 	printf("Busca: %s\n", busca->palavra);
	// else 
	// 	printf("Nao encontrado!");

	return busca;
}

void buscador(char* nomeArq, char* tipo, Palavra** hash, int tamHash){
	Palavra* p;
	FILE* arq;
	char* word;
	Documento2* lista = NULL;
	Documento* aux = NULL;

	arq = fopen(nomeArq, "r");

	if(arq==NULL)
		return;

	word = (char*)malloc(60*sizeof(char));

	while(fscanf(arq,"%s", word) == 1){
		printf("%s ", word);
		p = buscaPalavra(tipo, word, hash, tamHash);
		if(p==NULL){
			continue;
		}
		else { 
			Documento* aux = p->doc;
			while(aux!=NULL){
				lista = insereListaDocs(lista, aux->nomeDoc);
				aux=aux->proximo;
			}
		}
	}

	printf("\n");

	while(lista!=NULL){
		printf("%s\n", lista->nomeDoc);
		lista=lista->proximo;
	}
}