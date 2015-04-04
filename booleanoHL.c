#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADLeDoc.h"
#include "TADHashControle.h"

Palavra** insereHashLinear(Palavra** hash, Palavra* palavra, int tamHash){
	int n = 0;
	Palavra* aux;

	n = chaveHash(palavra->palavra, tamHash);

	/*
	verifica se existe colisao, caso exista,
	procura pela proxima posicao vazia do vetor
	*/
	if(hash[n] == NULL){
		hash[n] = palavra;
	} else {
		while (hash[n] != NULL){
			n++;
			if(n>tamHash)
				n = 0;
		}
	}

	return hash;
}

Palavra* buscaHashLinear(Palavra** hash, char* palavra, int tamHash){
	int chave =0;

	chave = chaveHash(palavra, tamHash);
	
	while(hash[chave] != NULL && strcmp(hash[chave]->palavra, palavra) != 0){
		chave++;
		if(chave > tamHash)
			chave = 0;
	}
	
	if(hash[chave] == NULL)
		return NULL;
	else
		return hash[chave];
}

void populaHashLinear(Palavra* lista, Palavra** hash, int tamHash){

	Palavra* aux = lista;
	Palavra* aux2 = NULL;

	if(aux == NULL){
		printf("ERRO: Nenhuma palavra foi indexada, queridinha!");
	} else{
		while(aux != NULL){
			aux2 = aux->proximo;
			aux->proximo = NULL;
			hash = insereHashLinear(hash, aux, tamHash);
			aux = aux2;
		}
	}
}

