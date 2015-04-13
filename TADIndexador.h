#ifndef TADINDEXADOR
#define TADINDEXADOR

// Funcao que imprime a hash
// Input: Hash de Palavras, o tamanho da hash e a lista de documentos que foram criados na busca
// Output: Nenhum
// Pré-condição: Hash está alocada
// Pós condição: Lista é impressa
void imprimeHash(Palavra**, int, Documento2*);

// Funcao que recia a hash a partir de um indice
// Input: Nome do arquivo, a o tamanho da hash e a llista de documentos
// Output: Ponteiro para a hash
// Pré-condição: Nenhuma das varias está desalocada
// Pós condição: Hash é recriada corretamente
Palavra** recriarHash(char*, int*);

// Cria a lista de documentos 
// Input: Nome do arquivo com o nome dos documentos e ponteiro para a lista de documentos
// Output: Lista de documentos
// Pré-condição: Arquivo não nulo
// Pós condição: Lista de documenos está alocada e não é nula
Documento2* recriarListaDocs(char*nomeArq, Documento2* listaDocs);

#endif
