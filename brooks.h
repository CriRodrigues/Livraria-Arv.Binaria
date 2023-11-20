// cabeçalho para as estruturas e funções usadas no projeto.
#ifndef BROOKS_H
#define BROOKS_H

typedef struct Livro
{
    char isbn[40];
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
int removerFilial( int id);

//as funçoes abaixo são respectivas para cadastro do acervo.

Livro *criaLivro(const char isbn[], const char autor[], const char titulo[],int qtdLivros);
void cadLivroFilial(Filiais *f,const char isbn[], const char autor[],const char titulo[],int qtdLivros);
void insereLivro(Livro *raiz, const char isbn[], const char autor[], const char titulo[],int qtdLivros);
Livro *removeLivro(Livro *raiz, const char isbn[]);

// funçoes de impressao e busca filal.
void impressaoFiliais( Filiais *f);
Filiais *buscaFilial(int id);
int imprimeUmaFilial(Filiais *f, int id);

// funcao de busca e  impressao do acervo;
Livro *buscaLivro(Filiais *f, Livro * raiz, int id, char const isbn[], const char autor[],const char titulo[], int qtdLivros);
Livro *buscaLivroNaArvore(Livro *raiz, const char isbn[], const char autor[], const char titulo[], int qtdLivro);
void imprimeAcervo(Livro *raiz);
void imprimeArvore(Livro *t, int s);

// funçao de remoçao do exemplares;
Livro *removerLivroNaArvore(Livro *raiz, const char isbn[]);
Livro *removerLivro(Filiais *f, int id, const char isbn[]);
Livro *menorLivro(Livro *raiz);

// funçao migrar estoque;
// Livro *inserirLivrosDeOutraArvore(Livro *arvoreReceptora, Livro *arvoreDoadora, int idArvoreReceptora, int idArvoreDoadora);

//Limpar buffer

void limparBuffer();



#endif
