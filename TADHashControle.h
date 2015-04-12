#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "TADLeDoc.h"


// Função que aloca a tabela hash de acordo com o tamanho do número de palavras e seta os ponteiros da hash para NULL
// Input: o número de palavras que existe no texto.
// Output: Nenhum.
// Pré-condição: Número de palavras é um inteiro válido.
// Pós condição: Hash é alocada e tem seus ponteiros direcionados para NULL.
Palavra** alocaHash(int nmrPalavras);

// Função que calcula se determinado número é um número primo
// Input: Um número inteiro.
// Output: Booleano. 1 Se primo, 0 se não-primo.
// Pré-condição:  Entrada é um número inteiro válido.
// Pós condição: Saída booleana é válida.
int EhPrimo(int numero);

// Função que calcula o tamanho da hash de acordo com o pŕoximo primo maior que a entrada.
// Input: Inteiro número de palavras do texto.
// Output: Inteiro que representa o tamanho da hash.
// Pré-condição: Número inteiro é válido.
// Pós condição: Tamanho da hash é gerado e é o primo maior mais próximo da entrada.
int tamanho_hash(int numero_de_palavras);

// Função auxiliar para calcular a posição na hash com melhor distribuição. Soma os asciis das letras de uma string
// Input:Ponteiro para char
// Output: Inteiro que representa a soma dos valores da tabela ASCII.
// Pré-condição: String é válida
// Pós condição: Soma é um número inteiro positivo
int chaveAuxiliar(char* s);

// Função que calcula a posição da Hash em que uma palavra vai ficar.
// Input: Uma string que é a palavra a ser inserida
// Output: Número da posição em que a palavra irá se localizaar na Hash.
// Pré-condição: Palavra é uma string válida
// Pós condição: Posição é retornada e existe no intervalo da Hash
int chaveHash(char* palavra, int tamHash);

// Função que percorre a lista de palavras e as insere na tabela Hash
// Input: Lista de palavras
// Output: Nenhum.
// Pré-condição: Lista de palavras é válida e não nula.
// Pós condição: Lista está vazia e palavras estão inseridas na tabeela Hash.
Palavra** populaHash(Palavra** hash, Palavra* lista);


//void imprimeHash(Palavra** hash, int tamHash);
