//bloco do programa que controla a busca

/* PRECISA:
*  Funcao que 'rankeia' documentos
*/

Palavra* buscaPalavra(char* tipo, char* palavra, Palavra** hash, int tamHash){
	Palavra* busca = NULL;

	if(strcmp(tipo, "booleanoENC") == 0)
		busca = buscaENC(lista, hash, tamHash);
	else if (strcmp(tipo, "booleanoHL") == 0)
		busca = buscaHashLinear(Palavra** hash, char* palavra, int tamHash);
		else if(strcmp(tipo, "booleanoRH") == 0)
			busca = buscaRH(Palavra** hash, char* palavra, int tamHash);
	 		else if (strcmp(tipo, "booleanoAB") == 0)
	 			printf("Je ne suis tuas nega");
	
	if(busca != NULL)
		printf("Busca: %s\n", busca->palavra);
	else 
		printf("Nao encontrado!");

	return busca;
}

void buscador(char* nomeArq, char tipo){
	Palavra* p;
	FILE* arq;
	char* word;

	word = (char*)malloc(60*sizeof(char));
	arq = fopen(nomeArq, "r");

	while(fscanf(arq,"%s", word) != 1){
		//if(word[0]= "\"")

	}
}
