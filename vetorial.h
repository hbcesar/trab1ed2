#ifndef TADHASHCONTROLE
#define TADHASHCONTROLE

// struct documento2 {
// 	char* nomeDoc;
// 	int* vetor;
// 	struct documento2* proximo;
// 	};

// typedef struct documento2 Documento2;



void alocaVetores(Documento2* listaDocumentos, int tamanho);
void preencheBusca(PalavraBusca* listaPalavras, Documento2* listaDocumentos, Palavra** hash, int tamHash);
void rankeiaAux(Documento2* listaDocumentos, int tamanho);

#endif