#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADLeDoc.h"
#include "TADHashControle.h"
#include "TADHashEnc.h"
#include "vetorial.h"


Documento2* criaSDocBusca (char* nomeDoc, char* nomeArq){
	Documento2* novo = (Documento2*)malloc(sizeof(Documento2));
	novo->nomeDoc = (char*)malloc((strlen(nomeDoc)+1)*sizeof(char));
	strcpy(novo->nomeDoc, nomeDoc);
	int tamanho = contaPalavrasBusca(nomeArq);
	novo->vetor = (int*)malloc((tamanho)*sizeof(int));

	int i,j;
	for (j=novo->vetor[i];j<sizeof(novo->vetor);j++,i++){
		novo->vetor[i] = 0;
	}

	novo->proximo = NULL;
	
	return novo;
}

PalavraBusca* criaPalavraBusca (char* Palavra){
	PalavraBusca* novo = (PalavraBusca*)malloc(sizeof(PalavraBusca));
	novo->nome= (char*)malloc((strlen(Palavra)+1)*sizeof(char));
	strcpy(novo->nome, Palavra);
	novo->proximo = NULL;
	
	return novo;

}

void inserePalavraBusca(PalavraBusca* lista, char* nomeArq){
	int i;
	char word[30];
	FILE* arq;

	if(nomeArq == NULL){
		printf("Arquivo de entrada nao especificado\n");
		exit(1);
	}

arq= fopen(nomeArq, "r");
	if(arq==NULL)
		exit(1);

	for(i=0;fscanf(arq,"%s", word) == 1; i++){
	if(lista == NULL)
		lista = criaPalavraBusca(word);
	else { 
		PalavraBusca* aux = lista;
		while(aux->proximo != NULL)
			aux = aux->proximo;
		aux->proximo = criaPalavraBusca(word);
	}
}
}

Documento2* leArquivoDocumentosBusca(Documento2* listaDocsBusca, char* nomeArq){
	char word[30];
	char** entradas;
	FILE* arq;
	int i;

	if(nomeArq == NULL){
		printf("Arquivo de entrada nao especificado\n");
		return NULL;
	}

	arq= fopen(nomeArq, "r");
	if(arq==NULL)
		return NULL;

	for(i=0;fscanf(arq,"%s", word) == 1; i++){
		listaDocsBusca = criaSDocBusca(word,nomeArq);
	}

	fclose(arq);
	
	return listaDocsBusca;

}

int contaOcorrecincas(Palavra** hash, char* palavra, int tamHash, char* nomeArq, Documento2* lista){
	int chave =0;

	chave = chaveHash(palavra, tamHash);

	Palavra* aux = hash[chave];
	
	while(aux != NULL && strcmp(aux->palavra, palavra) != 0){
		aux=aux->proximo;
	}
	if(aux == NULL)
		exit(1);
	else{
		Documento* aux2 = aux->doc;
		while(aux2 != NULL){


		aux2=aux2->proximo;
		}

}

		
}
