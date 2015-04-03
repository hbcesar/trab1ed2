#ifndef TADHASHCONTROLE
#define TADHASHCONTROLE

Palavra** insereHashLinear(Palavra** hash, Palavra* palavra, int tamHash);
Palavra* buscaHashLinear(Palavra** hash, char* palavra, int tamHash);
void populaHashLinear(Palavra* lista, Palavra** hash, int tamHash);

#endif