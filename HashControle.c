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

Documento2* criaSDocBusca (char* nomeDoc){
	Documento2* novo = (Documento2*)malloc(sizeof(Documento2));
	novo->nomeDoc = (char*)malloc((strlen(nomeDoc)+1)*sizeof(char));
	strcpy(novo->nomeDoc, nomeDoc);
	novo->vetor=NULL;
	novo->proximo = NULL;
	
	return novo;
}

Documento2* insereListaDocs(Documento2* lista, char* nomeDoc){
	Documento2* aux=lista;

	if(lista == NULL)
		lista = criaSDocBusca(nomeDoc);
	else{
		while(aux->proximo != NULL && strcmp(aux->nomeDoc, nomeDoc) != 0)
			aux=aux->proximo;

		if(strcmp(aux->nomeDoc, nomeDoc) == 0)
			return lista;
		else
			aux->proximo = criaSDocBusca(nomeDoc);
		}
		
	return lista;
}
