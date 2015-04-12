#ifndef TADHASHCONTROLE
#define TADHASHCONTROLE

struct documento2 {
char* nomeDoc;
int* vetor;
struct documento2* proximo;
};

typedef struct documento2 Documento2;

struct palavraBusca {
char* nome;
struct palavraBusca* proximo;
};

typedef struct palavraBusca PalavraBusca;
#endif