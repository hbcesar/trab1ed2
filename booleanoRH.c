
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
		int c  = abs(palavra->palavra[0]);
		int k = n +c;
		aux = hash[k];

		while (hash[k] != NULL ){
			k = k + c;
			if (k > tamHash)
				k = k - tamHash;
				//  int j = k - tamHash;
				//  while (hash[j] != NULL ){
				// j = j + c;	
				// }
				// hash[j] = palavra;
				// return 1;
		}
		hash[k] = palavra;
	}
	return 1;
}

void imprimeReHash(Palavra** hash, int tamHash){
	int i;
	int contador;
	Palavra* aux = hash[0];

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

Palavra* buscaRH(Palavra** hash, char* palavra, int tamHash){
	int n = 0;
	Palavra* aux;
	int flag = 0;
	

	n = chaveHash(palavra, tamHash);

	if(strcmp(hash[n]->palavra, palavra) == 0){
		return hash[n];
	} else {
		// se c receber zero, gera loop infinito!
		int c  = abs(palavra[0]);
		int k = n +c;
		aux = hash[k];

		while ((hash[k] != NULL) && (strcmp(hash[n]->palavra, palavra) != 0) && flag++){
			k = k + c;
			if (k > tamHash){
				k = k- tamHash;
				//  int j = k - tamHash;
				//  while (hash[j] != NULL ){
				// j = j + c;	
				// }
				// hash[j] = palavra;
				// return 1;
			}
		}
		if(flag)
			return hash[k];
		else return NULL;
	}



	// int chave =0;
	// int chaveaux = chaveHash(palavra);
	// chave = chaveHash(palavra);
	// int c  = abs(palavra->palavra[0]);
	// while(hash[chave] != NULL && strcmp(hash[chave]->palavra, palavra) != 0){
	// 	chave = chave + c;

	// 	if (chave > TamHash){
	// 		chave = TamHash - chave;
	// 	}

	// }
	
	// if(aux == NULL)
	// 	return NULL;
	// else
	// 	return hash[chave];
}