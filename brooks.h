// cabeçalho para as estruturas e funções usadas no projeto.
#ifndef BROOKS_H
#define BROOKS_H

typedef struct Livro
{
    char isbn[5];
    char titulo[20];
    char autor[50];
    int qtdLivro;
    struct Livro  *right, *left;

} Livro;


typedef struct Filiais
{
    int id;
    char endereco[50];
    char nomeGerente[50];
    Livro *livros;
    struct Filiais *prev, *next;

} Filiais;

//as funçoes abaixo são respectivas para add, rm, filiais.
Filiais *criaFilial(int id);
void cadNovaFilial(int id, char titulo, char gere);
Filiais *removerFilial(int id, Filiais *f);

//as funçoes abaixo são respectivas para cadastro do acervo.

Livro *criaAcervo();
Livro *cadNovoLivro(Filiais *f, char isbn, char autor,int qtdLivro );
Livro *cadLivroFilial(Filiais *f, char isbn, char autor,int qtdLivros );
Livro *removeLivro(Filiais *f,int id, char isbn);

// funçoes de impressao e busca filal.
void  impressaoFiliais(int id, Filiais *f);
int   buscaFiliais(int id, Filiais *f);

// funcao de impressao do acervo;
int   buscaLivro(Filiais *f, char isbn, char autor,char titulo);
void   imprimeAcerivo (Filiais *f );



#endif
