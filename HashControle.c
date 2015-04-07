#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADLeDoc.h"
#include "TADHashControle.h"

Palavra** alocaHash(int tamHash){
	Palavra** novo;
	int i;


	novo = (Palavra**)malloc(tamHash*sizeof(Palavra*));

	for(i=0;i<tamHash;i++){
		novo[i]=NULL;
	}

	return novo;
}

int EhPrimo(int numero){
	int i;

    if (numero <= 1) return 0; 

    for (i=2; i*i<=numero; i++) {
        if (numero % i == 0) 
        	return 0;
    }
    return 1;
}

int tamanho_hash(int numero_de_palavras){
	int i = (numero_de_palavras*2)+1;

	while (EhPrimo(i) !=1){
		i=i+2;
	}

	return i;
}

int chaveAuxiliar(char* s) {
    int i;
    int total=0;
    
    for (i=0; i <= strlen(s) ;i++){
      total = total + abs(s[i]);
    }

    return total;
}     

int chaveHash(char* palavra, int tamHash){
	int i,j, chave;
	int contaDigitos = 0;

	long int tamanho = chaveAuxiliar(palavra);
	long int valor =0;

	tamanho = tamanho * tamanho * tamanho;
	valor = tamanho;
	int ascii = abs(palavra[0]);
	//verifica o numero de digitos de "tamanho"
	while (valor != 0)
        {
            contaDigitos = contaDigitos + 1;
            valor = valor / 10;
        }
	
	char* str;
	str = (char*)malloc((contaDigitos+1)*sizeof(char));

	char* str2;
	str2 = (char*)malloc(((contaDigitos+1)/2)*sizeof(char));

	sprintf(str, "%ld", tamanho);

	for (i=contaDigitos/2, j=0; i<contaDigitos; i++, j++){
		str2[j]=str[i];
	}
	
	chave = atoi(str2);
	chave = chave * ascii;
	return (chave % tamHash);
}

void imprimeHash(Palavra** hash, int tamHash){
	FILE* arq;
	int i;
	int contador;
	Palavra* aux = hash[0];

	arq = fopen("indice.txt", "w");

	for(i=0; i<tamHash; i++){

		if(hash[i] != NULL){
			aux = hash[i];
			while (aux!= NULL){
				fprintf(arq, "%d; %s; ", i, aux->palavra);
				Documento* doc = aux ->doc;
				while(doc != NULL){
					fprintf(arq, "%s; ", doc->nomeDoc);
					Posicao* pos = doc->posicao;
					while(pos!=NULL){
						fprintf(arq, "%d; ", pos->posicao);
						pos = pos->proximo;
					}
					doc=doc->proximo;
				}
				aux=aux->proximo;
			}
				fprintf(arq, "\n");
		} else{
			fprintf(arq,"%d;-\n", i);
		}		
	}
}

// Palavra** populaHash(Palavra** hash, Palavra* lista){

// 	Palavra* aux = lista;
// 	Palavra* aux2 = NULL;

// 	if(aux == NULL){
// 		printf("ERRO: Nenhuma palavra foi indexada, queridinha!");
// 	} else{
// 		while(aux != NULL){
// 			aux2 = aux->proximo;
// 			aux->proximo = NULL;
// 			insereHash(aux);
// 			aux = aux2;
// 		}
// 	}

// 	return hash;
// }
