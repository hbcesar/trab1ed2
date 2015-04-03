
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADLeDoc.h"
#include "TADHashControle.h"
#include "TADHashEnc.h"


Palavra** insereReHash (Palavra** hash, Palavra* palavra, int tamHash){
	int n = 0;
	
	Palavra* aux;

	n = chaveHash(palavra->palavra, tamHash);

	/*
	verifica se existe colisao, caso exista,
	aplica uma nova função de hash
	*/

	if(hash[n] == NULL){
		hash[n] = palavra;
	} else {
		int c = (n % tamHash);
		int k = n +c;
		aux = hash[k];
		while (hash[k] != NULL){
		k = k + c;
		}
		aux = palavra;
	}
	return hash;
}

void imprimeReHash(Palavra** hash, int tamHash){
	int i;
	int contador;
	Palavra* aux = hash[0];

	printf("O tamanho da hash é %d\n", tamHash);

	for(i=0; i<tamHash; i++){

		if(hash[i] != NULL){
			aux = hash[i];
			//while (aux!= NULL){
			//	printf("\nPosicao no HASH: %d \t Palavra: %s\n", i, aux->palavra);
			//	printf("\tDocumento: %s\t", aux->doc->nomeDoc);
				printf("X");
			//	aux=aux->proximo;
			//}
				printf("\n");
		} else{
			printf("-\n");
		}
			
	}
}

void populaReHash(Palavra** hash, Palavra* lista, int tamHash ){

	Palavra* aux = lista;
	Palavra* aux2 = NULL;

	if(aux == NULL){
		printf("ERRO: Nenhuma palavra foi indexada, queridinha!");
	 } else{
	 	while(aux != NULL){
	 		aux2 = aux->proximo;
	 		aux->proximo = NULL;
	 		hash = insereReHash(hash, aux, tamHash);
	 		aux = aux2;
	 	}
	 	free(lista);	
	 }
}