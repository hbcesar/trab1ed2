#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADLeDoc.h"
#include "TADHashControle.h"
#include "TADHashEnc.h"
// #include "booleanoRH.h"

int main(int argc, char *argv[]){
	int i;
	Palavra* lista;
	Palavra** hash;
	int tamHash =0;

	lista = leArquivoDocumentos(lista, argv[1]);
	tamHash = tamanho_hash(nmrPalavras(lista));
	hash = alocaHash(tamHash);

	populaHashENC(lista, hash);

	imprimeHash(hash, tamHash);

	//leArquivo(lista, "Leti.txt");
	//lista = leArquivo(lista, "pequenoprincipe.txt");

	// for(i=0; i<argc; i++){
	// 	printf("%s\n", argv[i]);
	// }

	// free(lista);
	// lista = NULL;
	// imprimeLista(lista);
	//imprimeReHash();

	// Palavra* p = busca("digestão");
	// if (p != NULL)
	// 	printf("%s, %s, %d\n", p->palavra, p->doc->nomeDoc, p->doc->posicao->posicao);
	// else printf("Palavra nao encontrada");

	 return 0;
}
