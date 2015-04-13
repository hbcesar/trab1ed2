#ifndef TADINDEXADOR
#define TADINDEXADOR

int contador(void*);
void imprimeHash(Palavra**, int, Documento2*);
Palavra** recriarHash(char*, int*);
Documento2* recriarListaDocs(char*nomeArq, Documento2* listaDocs);

#endif