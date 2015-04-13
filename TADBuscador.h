//Função que aloca uma palavra que foi buscada 
// Input: Uma string
// Output: Estrutura palava
// Pré-condição: String  não é nula
// Pós condição: Palavra é criada e alocada
PalavraBusca* criaPalavraBusca (char* Palavra);

// Atualiza os campos dos vetores com a frequencia das palavras
// Input: A hash da palavras, o tamanho da hash, a lisa de palavras que foram buscadas, a lista de documentos, o nome do arquivo e o tipo de indexação
// Output: Nenhum
// Pré-condição: Nenhum dos parametros é nulo
// Pós condição: Vetores são atualizados para cada palavra
void inserePalavraBusca(Palavra** hash, int tamHash, PalavraBusca* listaPalavras, Documento2* listaDocumentos, char* nomeArq, char* tipo);

// Funcao que busca uma palavra a ser na Hash 
// Input: Tipo de indexação, a palavra, a hash e o amanho da Hash
// Output: Estrutura palavra
// Pré-condição: Nenhum dos parametros ´nulo 
// Pós condição: Palavra é retornada se existe na hash
Palavra* buscaPalavra(char* tipo, char* palavra, Palavra** hash, int tamHash);

// Funcao que percorre a lista de palavras que foram buscadas e procura-as na hash
// Input: Arquivo de entrada com as palavras da busca, tipo de indexacao, a hash de palavras e o tamanho da hash
// Output: Nenhum
// Pré-condição: Arquivo existe, hash está alocada e tipo existe
// Pós condição: Todas as palavras da lista de palavras foram buscadas na hash
void buscador(char* nomeArq, char* tipo, Palavra** hash, int tamHash);
