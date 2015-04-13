#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADLeDoc.h"
#include "TADHashControle.h"
#include "TADHashEnc.h"
#include "booleanoHL.h"
#include "booleanoRH.h"
#include "TADIndexador.h"
#include "vetorial.h"
#include "TADBuscador.h"


void gerarIndice(char* tipo, char* entrada){
	Palavra* lista;
	Palavra** hash;
	int tamHash = 0;
	lista=NULL;
	Documento2* listaDocs = NULL;

	lista = leArquivoDocumentos(lista, entrada);
	listaDocs = leArquivoDocumentosBusca(listaDocs, entrada);
	tamHash = tamanho_hash(nmrPalavras(lista));
	hash = alocaHash(tamHash);

	if(strcmp(tipo, "booleanoENC") == 0)
		populaHashENC(lista, hash, tamHash);
	else if (strcmp(tipo, "booleanoHL") == 0)
		populaHashLinear(lista, hash, tamHash);
		else if(strcmp(tipo, "booleanoRH") == 0)
			populaReHash(lista, hash, tamHash);
			else if (strcmp(tipo, "booleanoAB") == 0)
				printf("Nao implementado.");

	
	imprimeHash(hash, tamHash, listaDocs);
	//imprimeReHash(hash,tamHash);
		// Palavra* busca = buscaENC(hash, "principezinho", tamHash);
		// if(busca != NULL)
		// 	printf("Busca: %s\n", busca->palavra);
		// else 
		// 	printf("Nao encontrado!");
 }

void lerIndice(char* tipo, char* entrada, char* arqBuscas){
	Palavra** hash;
	Documento2* listaDocs = NULL;
	int tamHash = 0;

	listaDocs = recriarListaDocs(entrada, listaDocs);

	//RECRIA O INDICE E TESTA ISSO
	// while(listaDocs!=NULL){
	// 	printf("%s\n", listaDocs->nomeDoc);
	// 	listaDocs = listaDocs->proximo;	
	// }

	hash = recriarHash(entrada, &tamHash);

	buscador(arqBuscas, tipo, hash, tamHash);
}

int main(int argc, char *argv[]){

	int i;
	

	if(strcmp(argv[1], "-i") == 0){
		gerarIndice(argv[2], argv[3]);
	} else if(strcmp(argv[1], "-b") == 0){
		lerIndice(argv[2], argv[3], argv[4]);
	}


	
	 return 0;
}
