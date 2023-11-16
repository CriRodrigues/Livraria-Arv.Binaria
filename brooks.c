#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "brooks.h"

extern Filiais *ultimaFilial;
Filiais *criaFilial(int id, const char endereco[], const char nomeGerente[])
{
    Filiais *f = (Filiais *) malloc (sizeof(Filiais));
    f->id = id;
    f->livros = NULL;
    strcpy(f->endereco, endereco);
    strcpy(f->nomeGerente, nomeGerente);
    f->next = f->prev = NULL;
    return f;
}

void cadNovaFilial(int id,const char endereco[],const char nomeGerente[])
{
    if (!ultimaFilial)
    {
        ultimaFilial = criaFilial(id, endereco, nomeGerente);
    }
    else
    {

        Filiais *tmp = ultimaFilial;
        for (;tmp; tmp = tmp->prev)
        {
            if (id == tmp->id)
            {
                printf ("ERRO! Filial com id já cadastrado\n");
                return;
            }

        }
        tmp = criaFilial(id,endereco,nomeGerente);
        tmp->prev = ultimaFilial;
        tmp->next = NULL;
        ultimaFilial->next = tmp;
        ultimaFilial = tmp;
     }
}

Filiais *removerFilial(int id, Filiais *f)
{

    return NULL;
}
Livro *criaLivro(const char isbn[], const char autor[],const char titulo[],int qtdLivros)
{
    Livro *novoLivro = (Livro*) malloc (sizeof(Livro));
    strcpy (novoLivro->isbn, isbn);
    strcpy (novoLivro->autor, autor);
    strcpy (novoLivro->titulo, titulo);
    novoLivro->qtdLivros = qtdLivros;
    novoLivro->right = novoLivro->left = NULL;
    return novoLivro;

}
Livro *cadLivroFilial(Filiais *f, const char isbn[], const char autor[],const char titulo[],int qtdLivros)
{

if (!f)
{
    return NULL;    
}
    
 Livro *novoLivro = criaLivro(isbn, autor, titulo, qtdLivros);

if(!f -> livros)
{
     f->livros = novoLivro;   
}
else
{

}
    return f->livros;
}

Livro *removeLivros(Filiais *f,int id, char isbn)
{

    return NULL;
}

void impressaoFiliais( Filiais *f)
{
    Filiais *tmp = f;

    for(; tmp; tmp=tmp->prev)
    {   
        printf("------------//------------//---------//--------//\n");
        printf("id Filial: %d\nEndereço: %c\nNome do Gerente: %s\n", tmp->id,tmp->endereco,tmp->nomeGerente);
        printf("------------//------------//---------//--------//\n");
    }
 }

int buscaFiliais(int id, Filiais *f)
{
    return 0;
}

    // funcao de impressao do acervo;
int buscaLivro(Filiais *f, char const isbn[], const char autor[],const char titulo[])
{

    return 0;
}

void imprimeAcerivo (Filiais *f )
{

}

