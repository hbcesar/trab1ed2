#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "TADLeDoc.h"
#include "TADHashControle.h"
#include "TADHashEnc.h"
#include "booleanoRH.h"


Posicao* criaPosix (int posicao){
	Posicao* novo = (Posicao*)malloc(sizeof(Posicao));
	novo->posicao = posicao;
	novo->proximo = NULL;
	
	return novo;
}

Documento* criaSDoc (char* nomeDoc, int posicao){
	Documento* novo = (Documento*)malloc(sizeof(Documento));
	novo->nomeDoc = (char*)malloc((strlen(nomeDoc)+1)*sizeof(char));
	strcpy(novo->nomeDoc, nomeDoc);
	novo->posicao = criaPosix(posicao);
	novo->proximo = NULL;
	
	return novo;
}

Palavra* criaPalavra(char* word, char* nomeDoc, int posicao){
	Palavra* novo = (Palavra*)malloc(sizeof(Palavra));
	novo->palavra = (char*)malloc((strlen(word)+1)*sizeof(char));
	strcpy(novo->palavra, word);
		
	novo->doc = criaSDoc(nomeDoc, posicao);

	novo->proximo = NULL;

	return novo;
}


void inserePosicao(Documento* doc, int posicao){
	//confere se a lista esta vazia
	if(doc->posicao == NULL)
		doc->posicao = criaPosix(posicao);
	else { //caso nao esteja, navega até o final e insere
		Posicao* aux = doc->posicao;
		while(aux->proximo != NULL)
			aux = aux->proximo;
		aux->proximo = criaPosix(posicao);
	}
}

Documento* insereDoc(Documento* doc, char* nomeDoc, int posicao){

	//checa se o primeiro ja nao é o documento
	if(strcmp(doc->nomeDoc, nomeDoc) == 0){
		//se for, insere a posicao
		inserePosicao(doc, posicao);
		return doc;
	} else { //senao, percorre o resto da lista fazendo o mesmo tipo de verificacao
		Documento* aux = doc;
		while (aux->proximo!=NULL && (strcmp(aux->nomeDoc, nomeDoc) != 0)){
			aux = aux->proximo;
		}
		if(strcmp(aux->nomeDoc, nomeDoc) == 0){
			inserePosicao(aux, posicao);
			return doc;
		} else{
			aux->proximo = criaSDoc(nomeDoc, posicao);
			return doc;
		}
	}
}

Palavra* insere(Palavra* lista, char* word, char* nomeDoc, int posicao){
	//checa se a lista esta vazia
	if(lista == NULL){
		return criaPalavra(word, nomeDoc, posicao);
	} 
	else{ //se nao estiver:
		//confere se o primeiro elemento nao tem a mesma palavra
		if(strcmp(lista->palavra, word)==0){ // se tiver, insere documentos apenas
			lista->doc = insereDoc(lista->doc, nomeDoc, posicao);
		} else { //senao, percorre o resto da lista fazendo o mesmo tipo de verificacao
			Palavra* aux = lista;
			while (aux->proximo!=NULL && (strcmp(aux->palavra, word) != 0)){
				aux = aux->proximo;
			}
			if(strcmp(aux->palavra, word) == 0){
				insereDoc(aux->doc, nomeDoc, posicao);
			} else {
				aux->proximo = criaPalavra(word, nomeDoc, posicao);
			}
		}
		return lista;
	}
}

Palavra* leArquivo(Palavra* lista, char* nomeArq){
	FILE *arq;
	char ch;
	char *word;
	int i;

	word = (char*)malloc(60*sizeof(char));

	arq = fopen(nomeArq, "r");
	if(arq == NULL){
		printf("Erro na leitura de arquivo.");
	} else{
		printf("Lendo arquivo %s...\n", nomeArq);
		Palavra* p;
		for(i=0;fscanf(arq,"%s", word) == 1 ; i++){
				if(normaliza(word)){
				lista = insere(lista, word, nomeArq, i);
				}	
		}
		fclose(arq);
	}


	return lista;


}

int normaliza(char* word){
	int i, j, k;
	i = strlen(word)-1;


	if(i<2){
		return 0;
	} 

	for (j=0; j<=i; j++){
		if (((word[j]<=47) && (word[j]>=33)) || ( (word[j]<=63) && (word[j]>=58) )){
			for(k=j;k<i; k++){
				word[k]=word[k+1];
			}
			word[k]='\0';
			i--;
		}
		word[j]=tolower(word[j]);
	}
	return 1;
}

Palavra* leArquivoDocumentos(Palavra* lista, char* nomeArq){
	char word[30];
	char** entradas;
	FILE* arq;
	int i, numLinhas=0;

	if(nomeArq == NULL){
		printf("Arquivo de entrada nao especificado\n");
		return NULL;
	}

	arq= fopen(nomeArq, "r");
	if(arq==NULL)
		return NULL;

	for(i=0;fscanf(arq,"%s", word) == 1; i++){
		lista = leArquivo(lista, word);
	}

	fclose(arq);
	
	return lista;

}

Documento2* leArquivoDocumentosBusca(Documento2* listaDocsBusca, char* nomeArq){
	char word[30];
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
		listaDocsBusca = insereListaDocs(listaDocsBusca,word);
	}

	fclose(arq);
	
	return listaDocsBusca;

}

int nmrPalavras(Palavra* lista){
	int i;
	Palavra* aux = lista;

	for(i=0;aux != NULL; i++){
		aux=aux->proximo;
	}

	printf("Numero de palavras %d\n", i);
	return i;
}

int contaPalavrasBusca(char* nomeArq){
	char word[30];
	char** entradas;
	FILE* arq;
	int i, numLinhas=0;

	if(nomeArq == NULL){
		printf("Arquivo de entrada nao especificado \n");
		return 0;
	}

	arq= fopen(nomeArq, "r");
	if(arq==NULL){
		return 0;
	}
		
	for(i=0;fscanf(arq,"%s", word) == 1; i++){
		numLinhas++;
	}

	fclose(arq);
	
	return numLinhas;
}

void imprimeLista(Palavra* lista){
	Palavra* aux = lista;
	Documento* aux2;
	Posicao* aux3;

	if(aux == NULL)
		printf("Nenhuma palavra foi indexada, queridinha!");
	else { 
		while(aux!=NULL){
			printf("%s: \n", aux->palavra);
			aux2 = aux->doc;

			while (aux2 != NULL){
				printf("\t%s, posicoes: ", aux2->nomeDoc);
				aux3=aux2->posicao;

				while(aux3 != NULL){
					printf("%d ", aux3->posicao);
					aux3 = aux3->proximo;
				}
				printf("\n");
				aux2 = aux2->proximo;
			}
			aux=aux->proximo;
		}
	}
}