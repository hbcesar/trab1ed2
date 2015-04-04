#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADLeDoc.h"
#include "TADHashControle.h"
#include "TADHashEnc.h"
#include "booleanoHL.h"
#include "booleanoRH.h"

void gerarIndice(char* tipo, char* entrada){
	Palavra* lista;
	Palavra** hash;
	int tamHash =0;
	lista=NULL;

	printf("Entrada %s\n", entrada);

	lista = leArquivoDocumentos(lista, entrada);
	//imprimeLista(lista);
	tamHash = tamanho_hash(nmrPalavras(lista));
	printf("Tamanho da hash é : %d \n",tamHash);
	hash = alocaHash(tamHash);

	// if(strcmp(tipo, "booleanoENC") == 0)
	// 	 populaHashENC(lista, hash, tamHash);
	// else if (strcmp(tipo, "booleanoHL") == 0)
	 	//populaHashLinear(lista, hash, tamHash);
	// 	else if(strcmp(tipo, "booleanoRH") == 0)
			populaReHash(lista, hash, tamHash);
	// 		else if (strcmp(tipo, "booleanoAB") == 0)
	// 			printf("Je ne suis tuas nega");

	//imprimeHash(hash, tamHash);
	//imprimeReHash(hash,tamHash);
			Palavra* busca = buscaHashLinear(hash, "principezinho", tamHash);
			printf("Busca: %s\n", busca->palavra);
}

void lerIndice(){

}

int main(int argc, char *argv[]){
	int i;
	

	if(strcmp(argv[1], "-i") == 0){
		gerarIndice(argv[2], argv[3]);
	}


	
	 return 0;
}
