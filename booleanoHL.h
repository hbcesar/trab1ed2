#ifndef TADHASHCONTROLE
#define TADHASHCONTROLE

// Função que insere uma palavra na Hash utilizando do método de colisao por Hashing Linear
// Input: A palavra a ser inserida, a tabela Hash e o tamanho da tabela
// Output: A tabela Hash
// Pré-condição: Parametros nao sao nulos
// Pós condição: Palavra é inserida na Hash e Hash é retornada
Palavra** insereHashLinear(Palavra** hash, Palavra* palavra, int tamHash);

// Função que busca uma determinada palavra na tabela Hash pelo método do Hashing Linear
// Input: A palavra a ser inserida, a tabela Hash e o tamanho da tabela
// Output: A tabela Hash
// Pré-condição: Palavra não é nula e Hash já está inicializada
// Pós condição: Caso a palavara seja encontrada é retornada
Palavra* buscaHL(Palavra** hash, char* palavra, int tamHash);

// Função percorre a lista de palavras chamando a funcao que insere as palavras na Hash
// Input: Lista de palavras, a tabela Hash e o tamanho da tabela
// Output: Nenhum.
// Pré-condição: Parametros nao sao nulos.
// Pós condição: Lista está vazia e todas as palavras estão inseridas na tabela Hash
void populaHashLinear(Palavra* lista, Palavra** hash, int tamHash);

#endif
