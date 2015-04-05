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
	//checa se a lista esta vazia
	if(doc == NULL){
		Documento* novo = criaSDoc(nomeDoc, posicao);
		return novo;
	} else{ //senao, ve se o primeiro ja nao é o documento
		if(strcmp (doc->nomeDoc, nomeDoc) == 0){
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
}

Palavra* insere(Palavra* lista, char* word, char* nomeDoc, int posicao){
	//checa se a lista esta vazia
	if(lista == NULL){
		return criaPalavra(word, nomeDoc, posicao);
	} 
	else{ //se nao estiver:
		//confere se o primeiro elemento nao tem a mesma palavra
		if(strcmp (lista->palavra, word)==0){ // se tiver, insere documentos apenas
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
		return NULL;
	} else{
		Palavra* p;
		for(i=0;fscanf(arq,"%s", word) == 1 ; i++){
			//if(word[0] != 10){
				if(retiraAcento(word)){
				lista = insere(lista, word, nomeArq, i);
				}	
			//}
		}
	}

	return lista;
//	fclose(arq);

}


int retiraAcento(char* word){
	int i, j;
	i = strlen(word)-1;


	if(i<4){
		return 0;
	} 
	else { 
		if (((word[0]<=47) && (word[0]>=33)) || ( (word[0]<=63) && (word[0]>=58) )){
			for(j=0;j<i; j++){
				word[j]=(unsigned char)word[j+1];
			}
			word[j]='\0';
			i--;
		}
		if (((word[i]<=47) && (word[i]>=33)) || ( (word[i]<=63) && (word[i]>=58) ) ){
				word[i] = '\0';
		}
		word[0] = tolower(word[0]);
		return 1;
	}

}


int leArquivoDocumentosAux(char* nomeArq){
	int numLinha =0;
	FILE *arq;
	char c;

	arq= fopen(nomeArq, "r");

	if(arq == NULL){
		printf("Erro na leitura de arquivo.");
		return 0;

	} else{
		while((c = fgetc(arq)) != EOF){
    		if(c == '\n')
    			numLinha++;
 		}
		fclose(arq);
		return ++numLinha;
	}
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

	numLinhas = leArquivoDocumentosAux(nomeArq);


	if(numLinhas > 0)
		arq= fopen(nomeArq, "r");
	else 
		return NULL;

	printf("Numero de palavras para o arquivo %s é %d\n", nomeArq, numLinhas);

	entradas = (char**)malloc(numLinhas*sizeof(char*));

	for(i=0;fscanf(arq,"%s", word) == 1; i++){
		entradas[i] = (char*)malloc((strlen(word)+1)*sizeof(char));
		strcpy(entradas[i], word);
	}

	for(i=0; i< numLinhas; i++){
		lista = leArquivo(lista, entradas[i]);
	}

	//fclose(arq);
	
	return lista;

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