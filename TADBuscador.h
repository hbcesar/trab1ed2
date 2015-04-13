PalavraBusca* criaPalavraBusca (char* Palavra);
void inserePalavraBusca(Palavra** hash, int tamHash, PalavraBusca* listaPalavras, Documento2* listaDocumentos, char* nomeArq, char* tipo);
Palavra* buscaPalavra(char* tipo, char* palavra, Palavra** hash, int tamHash);
void buscador(char* nomeArq, char* tipo, Palavra** hash, int tamHash);
