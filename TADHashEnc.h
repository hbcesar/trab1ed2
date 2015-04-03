
// Função que remove uma determinada palavra da Hash
// Input: Palavra a ser removida.
// Output: Nenhum.
// Pré-condição: Palavrá é uma string válida.
// Pós condição: Palavra é removida do hash se ela existe. Caso contrário, um aviso é mostrado de que a palavra não existe na hash.
//void removeHash (char* palavra);

// Função que imprime os elementos da tabela Hash para se ter uma ideia do espalhamento.
// Input: Nenhum
// Output: Nenhum.
// Pré-condição: Hash não e nula.
// Pós condição: Hash é impressa. X significa que a posição está ocupada; - significa que a posição está vazia.
void imprimeHash(Palavra** hash, int tamHash);

// Função que busca uma palavra na tabela Hash.
// Input: Palavra a ser buscada.
// Output: Palavra encontrada.
// Pré-condição: Palavra é uma string válida.
// Pós condição:  Palavra está presente no Hash e é retornada.
Palavra* busca(Palavra** hash, char* palavra);

// Função que insere uma palavra na Hash
// Input: Ponteiro para uma estrutura palavra.
// Output: Nenhum.
// Pré-condição: Palavra é válida.
// Pós condição: Palavra é inserida na Hash. No caso de colisão, é inserida na última posição da lista daquela posição.
void insereHash (Palavra** hash, Palavra* palavra);

void populaHashENC(Palavra* lista, Palavra** hash);
