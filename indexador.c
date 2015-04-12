#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADLeDoc.h"
#include "TADHashControle.h"

int contaNmrPalavras(Palavra* p){
	Palavra* aux = p;
	int i=0;

	while (aux!=NULL){
		aux=aux->proximo;
		i++;
	}

	return i;
}

int contaNmrDocs(Documento* p){
	Documento* aux = p;
	int i=0;

	while (aux!=NULL){
		aux=aux->proximo;
		i++;
	}

	return i;
}

int contaNmrPosicoes(Posicao* p){
	Posicao* aux = p;
	int i=0;

	while (aux!=NULL){
		aux=aux->proximo;
		i++;
	}

	return i;
}

void imprimeHash(Palavra** hash, int tamHash){
	FILE* arq;
	int i;
	int contador;
	Palavra* aux = hash[0];

	arq = fopen("indice.txt", "w");

	if (arq == NULL)
		return;

	fprintf(arq, "%d\n", tamHash);

	for(i=0; i<tamHash; i++){
		if(hash[i] != NULL){
			fprintf(arq, "%d;", i);
			aux = hash[i];
			fprintf(arq, "%d;", contaNmrPalavras(aux));
			while (aux!= NULL){
				fprintf(arq, "%s ;", aux->palavra);
				Documento* doc = aux ->doc;
				fprintf(arq, "%d;", contaNmrDocs(doc));
				while(doc != NULL){
					fprintf(arq, "%s ;", doc->nomeDoc);
					Posicao* pos = doc->posicao;
					fprintf(arq, "%d;", contaNmrPosicoes(pos));
					while(pos!=NULL){
						fprintf(arq, "%d;", pos->posicao);
						pos = pos->proximo;
					}
					doc=doc->proximo;
				}
				aux=aux->proximo;
			}
				fprintf(arq, "\n");
		} else{
			fprintf(arq,"%d;0\n", i);
		}		
	}
}

Palavra** recriarHash(char* nomeArq){
	Palavra** hash=NULL;
	Palavra* aux=NULL;
	FILE* arq;
	int tamHash;
	int i=0;
	int nmrPalavras=0;
	int nmrDocs=0;
	int nmrPosicoes=0;
	char *palavra = (char*)malloc(60*sizeof(char));
	char *nomeDoc = (char*)malloc(30*sizeof(char));
	int posicao;


	arq = fopen("indice.txt", "r");

	if (arq == NULL)
		return NULL;

	fscanf(arq, "%d", &tamHash);
	printf("%d\n", tamHash);

	hash = alocaHash(tamHash);

	while(i<(tamHash-1)){
		fscanf(arq, "\n%d;", &i);
		fscanf(arq, "%d;", &nmrPalavras);
		while(nmrPalavras > 0){
			fscanf(arq, "%s", palavra);
			fscanf(arq, " ;%d;", &nmrDocs);
			while(nmrDocs >0){
				fscanf(arq, "%s", nomeDoc);
				fscanf(arq, " ;%d;", &nmrPosicoes);
				while(nmrPosicoes > 0){
					fscanf(arq, "%d;", &posicao);
					aux=insere(aux, palavra, nomeDoc, posicao);
					nmrPosicoes--;
				}				
				nmrDocs--;
			}
			nmrPalavras--;
		}
		hash[i]=aux;
		aux = NULL;
	}
	return hash;
}










