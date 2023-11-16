// cabeçalho para as estruturas e funções usadas no projeto.
#ifndef BROOKS_H
#define BROOKS_H

typedef struct Livro
{
    char isbn[5];
    char titulo[20];
    char autor[50];
    int qtdLivros;
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
Filiais *criaFilial( int id, const char endereco[], const char nomeGerente[]);
void cadNovaFilial(int id,const char endereco[],const char nomeGerente[]);
Filiais *removerFilial(const int id, Filiais *f);

//as funçoes abaixo são respectivas para cadastro do acervo.

Livro *criaLivro(const char isbn[], const char autor[], const char titulo[],int qtdLivros);
Livro *cadLivroFilial(Filiais *f,const char isbn[], const char autor[],const char titulo[],int qtdLivros);
Livro *removeLivro(Filiais *f,const int id, const char isbn[]);

// funçoes de impressao e busca filal.
void  impressaoFiliais( Filiais *f);
int   buscaFiliais(int id, Filiais *f);

// funcao de impressao do acervo;
int   buscaLivro(Filiais *f, const char isbn[], const char autor[],const char titulo[]);
void   imprimeAcerivo (Filiais *f );



#endif
