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

Palavra* buscaPalavra(char* tipo, char* palavra, Palavra** hash, int tamHash, nomeArq){
	Palavra* busca = NULL;

	if(strcmp(tipo, "booleanoENC") == 0)
		busca = buscaENC(hash, palavra, tamHash);
	else if (strcmp(tipo, "booleanoHL") == 0)
		busca = buscaHL(hash, palavra, tamHash);
		else if(strcmp(tipo, "booleanoRH") == 0)
			busca = buscaRH(hash, palavra, tamHash);
			else if (strcmp(tipo, "vetorial") == 0)
				buscadorVetorial(hash, nomeArq, tamHa)
		 		else if (strcmp(tipo, "booleanoAB") == 0 || strcmp(tipo, "vetorialIDF") == 0)
		 			printf("Nao implementado :/");
	

	return busca;
}

void buscadorVetorial(Palavra** hash, char* nomeArq, int tamHash, ){

	inserePalavraBusca(hash, tamHash, nomeArq, tipo);

}

void buscador(char* nomeArq, char* tipo, Palavra** hash, int tamHash){
	Palavra* p;
	FILE* arq;
	char* palavra;
	Documento2* lista = NULL;
	Documento* aux = NULL;
	int i;
	int flag=0;

	arq = fopen(nomeArq, "r");

	if(arq==NULL)
		return;

	palavra = (char*)malloc(60*sizeof(char));

	for(i=0; (palavra[i] = fgetc (arq)) != EOF ; i++){
		if(palavra[i] == 32 || palavra[i] == 10){
			if (palavra[i]== 10)
				flag = 1;
			palavra[i]= 0;
			i=-1;
			printf("%s ", palavra);

			if(normaliza(palavra))
				p = buscaPalavra(tipo, palavra, hash, tamHash, nomeArq);
			else 
				continue;

			if(p==NULL){
				continue;
			} else { 
			Documento* aux = p->doc;
				while(aux!=NULL){
					lista = insereListaDocs(lista, aux->nomeDoc);
					aux=aux->proximo;
				}
			}
		}
		if (flag == 1){
			printf("\n");
			while(lista!=NULL){
				printf("%s\n", lista->nomeDoc);
				lista=lista->proximo;
			}
			flag=0;
		}
	}
}