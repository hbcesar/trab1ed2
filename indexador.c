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

int contaNmrDocs2(Documento2* d2){
	Documento2* aux = d2;
	int i=0;

	while (aux!=NULL){
		aux=aux->proximo;
		i++;
	}

	return i;
}

void imprimeHash(Palavra** hash, int tamHash, Documento2* listaDocs){
	FILE* arq;
	int i;
	int contador;
	Palavra* aux = hash[0];

	arq = fopen("indice.txt", "w");

	if (arq == NULL)
		return;



	Documento2* auxDocs = listaDocs;

	fprintf(arq, "%d;", contaNmrDocs2(listaDocs));

	while(auxDocs != NULL){
		fprintf(arq, "%s ", auxDocs->nomeDoc);
		auxDocs=auxDocs->proximo;
	}

	fprintf(arq, "\n%d\n", tamHash);

	fprintf(arq, "\n");

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

Documento2* recriarListaDocs(char*nomeArq, Documento2* listaDocs){
	FILE* arq;
	int nmrDocs=0, i;
	char *nomeDoc = (char*)malloc(30*sizeof(char));

	arq = fopen(nomeArq, "r");

	if (arq == NULL)
		return NULL;

	fscanf(arq, "\n%d;", &nmrDocs);
	
	for(i=0; i<nmrDocs; i++){
		fscanf(arq, "%s", nomeDoc);
		listaDocs = insereListaDocs(listaDocs, nomeDoc);
	}

	fclose(arq);

	return listaDocs;
}

Palavra** recriarHash(char* nomeArq, int* tamHash, Documento2* listaDocs){
	Palavra** hash=NULL;
	Palavra* aux=NULL;
	FILE* arq;
	//int tamHash;
	int i=0;
	int nmrPalavras=0;
	int nmrDocs=0;
	int nmrPosicoes=0;
	char *palavra = (char*)malloc(60*sizeof(char));
	char *nomeDoc = (char*)malloc(30*sizeof(char));
	int posicao;
	int nmrDocs2=0;


	arq = fopen(nomeArq, "r");

	if (arq == NULL)
		return NULL;

	fscanf(arq, "\n%d;", &nmrDocs2);
	
	for(i=0; i<nmrDocs2; i++){
		fscanf(arq, "%s", nomeDoc);
//		insereListaDocs(listaDocs, nomeDoc);
	}

	fscanf(arq, "%d", tamHash);

	hash = alocaHash((*tamHash));

	while(i<((*tamHash)-1)){
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