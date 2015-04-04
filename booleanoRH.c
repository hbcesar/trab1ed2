
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADLeDoc.h"
#include "TADHashControle.h"
#include "TADHashEnc.h"

//FALTA IMPLEMENTAR FUNCAO DE BUSCA

int insereReHash (Palavra** hash, Palavra* palavra, int tamHash){
	int n = 0;
	
	Palavra* aux;

	n = chaveHash(palavra->palavra, tamHash);

	/*
	verifica se existe colisao, caso exista,
	aplica uma nova função de hash
	*/

	if(hash[n] == NULL){
		hash[n] = palavra;
		return 1;
	} else {
		// se c receber zero, gera loop infinito!
		int c = (n % tamHash);
		printf("quenda o valor de C: %d\n", c);
		int k = n +c;
		aux = hash[k];

		while (hash[k] != NULL ){
			k = k + c;
			if (k > tamHash){
				printf("ReHash estourou, mulher");
				return 0;
			}
		}
		hash[k] = palavra;
	}
	return 1;
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

void populaReHash(Palavra* lista, Palavra** hash, int tamHash ){

	Palavra* aux = lista;
	Palavra* aux2 = NULL;

	if(aux == NULL){
		printf("ERRO: Nenhuma palavra foi indexada, queridinha!");
	 } else{
	 	while(aux != NULL){
	 		aux2 = aux->proximo;
	 		aux->proximo = NULL;
	 		if(!insereReHash(hash, aux, tamHash))
	 			printf("Palavra nao foi inserida!\n");
	 		aux = aux2;
	 	}
	 	//free(lista);	
	 }
}