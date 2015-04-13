#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADLeDoc.h"
#include "TADHashControle.h"
#include "TADHashEnc.h"
#include "vetorial.h"

PalavraBusca* listaPalavras;
Documento2* listaDocumentos;


void alocaVetores(int tamanho){
	Documento2* aux = listaDocumentos;
	int i=0;

	while(aux!=NULL){
		aux->vetor = (int*)malloc((tamanho)*sizeof(int));

		for (i=0; i<tamanho;i++){
			aux->vetor[i] = 0;
		}
	}
}

PalavraBusca* criaPalavraBusca (char* Palavra){

	PalavraBusca* novo = (PalavraBusca*)malloc(sizeof(PalavraBusca));
	novo->nome= (char*)malloc((strlen(Palavra)+1)*sizeof(char));
	strcpy(novo->nome, Palavra);
	novo->proximo = NULL;
	
	return novo;
}

void inserePalavraBusca(Palavra** hash, int tamHash, char* nomeArq, char* tipo){
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
			preencheBusca(listaPalavras, listaDocumentos, hash, tamHash);
			i=0;
		}
	}
}

int contaOcorrecincas(Palavra** hash, int tamHash, char* palavra, char* documento){
	int chave = 0;
	int i = 0;

	chave = chaveHash(palavra, tamHash);

	Palavra* aux = hash[chave];
	
	while(aux != NULL && strcmp(aux->palavra, palavra) != 0){
		aux=aux->proximo;
	}
	if(aux == NULL)
		return 0;
	else{
		Documento* aux2 = aux->doc;
		while(aux2 != NULL && strcmp(aux2->nomeDoc, documento) != 0)
			aux2=aux2->proximo;
		if(aux2 == NULL)
			return 0;
		else{
			Posicao* aux3 = aux2->posicao;
			while(aux3 != NULL){
				aux3 = aux3 ->proximo;
				i++;
			}
		}	
		return i;
	}

}

void preencheBusca(PalavraBusca* listaPalavras, Documento2* listaDocumentos, Palavra** hash, int tamHash){
	int i=0;
	PalavraBusca* aux = listaPalavras;
	Documento2* aux2 = listaDocumentos;

	for(i=0; aux == NULL; aux=aux->proximo, i++){
		while(aux2!=NULL){
			aux2->vetor[i] = contaOcorrecincas(hash, tamHash, aux->nome, aux2->nomeDoc);
			aux2=aux2->proximo;
		}
		aux2=listaDocumentos;
	}
}

void rankear(Documento2* listaDocumentos){
	Documento2* aux = listaDocumentos;
	int i=0;

	while(aux!=NULL){
		i++;
		aux=aux->proximo;
	}

	rankeiaAux(listaDocumentos, i);
}

int soma(int* vetor){
	int i, k=0;
	int n = sizeof(vetor)/sizeof(int);

	for(i=0; i<n; i++){
		k = k + vetor[i];
	}

	return k;

}


void rankeiaAux(Documento2* listaDocumentos, int tamanho){
	int rank[tamanho][2];
	int i, j, k=0, x=0, aux2;

	Documento2* aux = listaDocumentos;

	for(i=0; i<tamanho; i++){
		rank[i][0]=i;
		rank[i][1]=soma(aux->vetor);
		aux=aux->proximo;
	}

	for(i=0; i<tamanho; i++){
		for(j=i+1; j<tamanho; j++){
			if(rank[i][1] > x){
			x = rank[i][1];
			k=i;
			}
		}
		aux2=rank[i][1];
		rank[i][0] = rank[k][0];
		rank[i][1] = x;
		rank[k][0] = i;
		rank[k][1] = aux2;
	}

}

void imprime(Documento2* listaDocumentos, int tamanho, int rank[tamanho][2]){
	Documento2* aux = listaDocumentos;
	int i, j;

	for(i=0; i<tamanho; i++){
		for(j=0; j<rank[i][0]; j++){
			aux=aux->proximo;
		}
		printf("%s\n", aux->nomeDoc);
	}
}

void buscar()
