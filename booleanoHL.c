#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADLeDoc.h"
#include "TADHashControle.h"

// Palavra** alocaHash(int tamHash){
// 	int i=0;
// 	Palavra** hash;

// 	hash = (Palavra**)malloc(tamHash*sizeof(Palavra));

// 	for(i=0;i<tamHash;i++){
// 		hash[i]=NULL;
// 	}

// 	return vetor;
// }

Palavra** insereHashLinear(Palavra** hash, Palavra* palavra, int tamHash){
	int n = 0;
	Palavra* aux;

	n = chaveHash(palavra->palavra, tamHash);

	/*
	verifica se existe colisao, caso exista,
	procura pela proxima posicao vazia do vetor
	*/
	if(hash[n] == NULL){
		hash[n] = palavra;
	} else {
		while (hash[n] != NULL){
			n++;
			if(n>tamHash)
				n = 0;
		}
	}

	return hash;
}

Palavra* buscaHashLinear(Palavra** hash, char* palavra, int tamHash){
	int chave =0;

	chave = chaveHash(palavra, tamHash);
	
	while(hash[chave] != NULL && strcmp(hash[chave]->palavra, palavra) != 0){
		chave++;
		if(chave > tamHash)
			chave = 0;
	}
	
	if(hash[chave] == NULL)
		return NULL;
	else
		return hash[chave];
}

void populaHashLinear(Palavra* lista, Palavra** hash, int tamHash){

	Palavra* aux = lista;
	Palavra* aux2 = NULL;

	if(aux == NULL){
		printf("ERRO: Nenhuma palavra foi indexada, queridinha!");
	} else{
		while(aux != NULL){
			aux2 = aux->proximo;
			aux->proximo = NULL;
			hash = insereHashLinear(hash, aux, tamHash);
			aux = aux2;
		}
	}
}

// int chaveAuxiliar(char* s) {
//     int i;
//     int total=0;
    
//     for (i=0; i <= strlen(s) ;i++){
//       total = total + abs(s[i]);
//     }

//     return total;
// }     

// int chaveHash(char* palavra, int tamHash){
// 	int i,j, chave;
// 	int contaDigitos = 0;

// 	long int tamanho = chaveAuxiliar(palavra);
// 	long int valor =0;

// 	tamanho = tamanho * tamanho* tamanho;
// 	valor = tamanho;
// 	int ascii = abs(palavra[0]);
// 	//verifica o numero de digitos de "tamanho"
// 	while (valor != 0)
//         {
//             contaDigitos = contaDigitos + 1;
//             valor = valor / 10;
//         }
	
// 	char* str;
// 	str = (char*)malloc((contaDigitos+1)*sizeof(char));

// 	char* str2;
// 	str2 = (char*)malloc(((contaDigitos+1)/2)*sizeof(char));

// 	sprintf(str, "%ld", tamanho);

// 	for (i=contaDigitos/2, j=0; i<contaDigitos; i++, j++){
// 		str2[j]=str[i];
// 	}
	
// 	chave = atoi(str2);
// 	chave = chave * ascii;
// 	return (chave % tamHash);
// }