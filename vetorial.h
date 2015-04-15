#ifndef TADHASHCONTROLE
#define TADHASHCONTROLE

// struct documento2 {
// 	char* nomeDoc;
// 	int* vetor;
// 	struct documento2* proximo;
// 	};

// typedef struct documento2 Documento2;


// Funcao que aloca os vetores das estrtuuras documento e seta todas as frequencias para 0 
// Input: A lista de documentos e o numero das palavras da busca
// Output: Nenhum
// Pré-condição: Tamanho da busca é maior que 0
// Pós condição: Vetores são alocados e estão com valor de 0 para as frequências
void alocaVetores(Documento2* listaDocumentos, int tamanho);

// Funcao que insere na lista de documentos todos as palavras da busca e seta os valores dos vetores 
// Input: A lista de Palavras da busca, a lista de documentos, A tabela hash e o tamanho da tabela Hash
// Output: Nenhum
// Pré-condição: Nenhum dos parametros de entrada é nulo
// Pós condição: Vetores são alocados e possuem suas frequencias atualizadas
void preencheBusca(PalavraBusca* listaPalavras, Documento2* listaDocumentos, Palavra** hash, int tamHash);

// Funcao que ranqueia os documentos para mostrar qual documento possui mais frequencias das buscas
// Input: A lista de documentos e o numero de palavras da busca
// Output: Nenhum
// Pré-condição: Lista de documentos já tem os vetores alocados e não é nula
// Pós condição: Documentos são corretamente ranqueados
void rankeiaAux(Documento2* listaDocumentos, int tamanho);

#endif
