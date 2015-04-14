void imprimeReHash();

// Funcao que insere na Hash utilizando o método de colisão por ReHash  
// Input: A tabela hash e a palavra a ser isnerida
// Output: 1 se a palavra foi inserida corretamente
// Pré-condição: Palavra já esta alocada na lista de palavras
// Pós condição: Palavra é inserida na posição correta da lista
int insereReHash (Palavra** hash, Palavra* palavra);

// Funcao que percorre a lista de palavras pra inserir todas elas na tabela Hash
// Input: A lista de palavras, a tabela hash e o tamanho máximo da tabela hash
// Output: Nenhum
// Pré-condição:  Lista nao é vazia e todas as palavras são diferentes de nulo
// Pós condição: Hash está populada com as palavras e a lista esta vazia
void populaReHash(Palavra* lista, Palavra** hash, int tamHash);

// Funcao que busca na tabela a palavra de entrada utilizado o método de Re-Hashing
// Input: A palavra a ser pesquisada, o tamanho da Hash e a propria tabela Hash
// Output: A palavra a ser buscada
// Pré-condição: Palavra nao é nula e  hash também nao está vazia
// Pós condição: Palavra é retoranda corretamente caso esteja presente na hash
Palavra* buscaRH(Palavra** hash, char* palavra, int tamHash);
