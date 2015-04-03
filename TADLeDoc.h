//Estrutra de dados"chave" do programa. Contém um campo string para armazenar a palavra, um ponteiro para a lista de
//documentos em que essa palavra ocorre e um ponteiro para a pŕoxima palavra da lista.
struct palavra{
	char* palavra;
	struct documento* doc;
	struct palavra* proximo;
};

typedef struct palavra Palavra;

//Estrutura de dados do programar que serve para guardar uma lista de documentos nos quais a palavra existe. Contém o nome do 
//documento, um ponteiro para a lista de posições daquela palavra no documento e um ponteiro para o próximo documento.
struct documento {
	char* nomeDoc;
	struct posicao* posicao;
	struct documento* proximo;
};

typedef struct documento Documento;

//Estrura de dados do programa que serve para guardar as posições em que uma palavra ocorre no documento. Contém um campo inteiro
//para guardar a posição e um ponteiro para a próxima posição.
struct posicao {
	int posicao;
	struct posicao* proximo;
};

typedef struct posicao Posicao;



//Estrutura de dados que contmém a lista de palavras. Contém um ponteiro para a primeira e a última palavra da lista.
// typedef struct listap ListaP;

// Função que inicializa a lista de palavras
// Input: Nenhum.
// Output: Lista criada.
// Pré-condição: Nenhuma.
// Pós condição: Lista está inicializada e tem ponteiros para o último e primeiro setadas para NULL.
void initLista();

// Função que insere uma palavra na lista de palavras.
// Input: A palavra, o documento em que se encontra e a posição no documento.
// Output: Nenhum.
// Pré-condição: A palavra, um documento associado à ela, e uma posição associada ao documento existem.
// Pós condição: Palavra é inserida na lista e seus campos documentos e posição são atualizados.
Palavra* insere(Palavra* lista, char* word, char* nomeDoc, int posicao);

// Função para leitura das palavras no arquivo.
// Input: Ponteiro para o nome do arquivo.
// Output: Nenhum.
// Pré-condição: Nenhum.
// Pós condição: Arquivo é lido com sucesso.
Palavra* leArquivo(Palavra* lista, char *nomeArq);

// Função que aloca a lista de posições de uma determinada palavra, (é chadmada pela função que associa 
// uma palavra ao documento).
// Input: Posição da palavra no documento.
// Output: Estrutura da lista de posições criada e inserida.
// Pré-condição: Número da posição é um número válido.
// Pós condição: Nó posição é alocado.
Posicao* criaPosix (int posicao);

// Função que aloca documentos de uma determinada palavra e também a lista de posições naquele documento.
// Input: Nome do documento e posição associada à palavra no mesmo.
// Output: Estrutura da lista de documentos criada e inserida.
// Pré-condição: Nome de documento e número de posição são válidos.
// Pós condição: Nó documento e nó posição são alocados e estão presentes nas suas respectitvas listas.
Documento* criaSDoc (char* nomeDoc, int posicao);

// Função que aloca uma palavra e a insere na lista de palavras do documento, utilizando também as funções de 
// alocação de documentos e de posições
// Input: Uma palavra, um documento e uma posição
// Output: Nenhum
// Pré-condição: Nome da palavra, nome do documento e número de posição são válidos.
// Pós condição: Estrutura palavra criada e inserida na lista de palavras.
Palavra* criaPalavra(char* word, char* nomeDoc, int posicao);

// Função que calcula o número de palavras distintas da lista de palavras.
// Input: Lista de palavras
// Output: Nenhum
// Pré-condição: Lista não é nula
// Pós condição: Função define do hash é setada com o número de palavras presentes no texto.
int nmrPalavras(Palavra* lista);


// Função que imprime toda a lista de palavras, com seus respectivos documentos e posições nos documentos.
// Input: Nenhum.
// Output:  Nenhum.
// Pré-condição:  Lista é válida e não nula.
// Pós condição: 
void imprimeLista(Palavra* lista);

// Função que cria vetor de ponteiros para os nomes dos documentos de entrada.
// Input: Arquivo a ser lido.
// Output:  Nenhum.
// Pré-condição: Arquivo é válido.
// Pós condição: Vetor de strings com nomes dos documentos é inicializado e contém os nomes.
Palavra* leArquivoDocumentos(Palavra* lista, char* nomeArq);

// Função que calcula o número de linhas de um arquivo.
// Input: O arquivo a ser lido.
// Output: Inteiro contendo o número de linhas.
// Pré-condição: Arquivo é válido.
// Pós condição: Número de linhas é um número natural.
int leArquivoDocumentosAux(char* nomeArq);

void retiraAcento(char* word);