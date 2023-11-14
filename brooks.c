#include <stdio.h>
#include <stdlib.h>
#include "brooks.h"

extern Filiais *ultimaFilial;
Filiais *criaFilial(int id)
{
    Filiais *f = (Filiais *) malloc (sizeof(Filiais)); 
    f->id = id;
    f->livros = NULL;
    f->next = f->prev = NULL; 
    
    ultimaFilial = f;
    return f;
}

void cadNovaFilial(int id, char titulo, char gere)
{
    if (!ultimaFilial)
    {
        criaFilial(id);
    }
    else
    {
        
        Filiais *tmp = ultimaFilial;
        for (;tmp;tmp = tmp->prev)
        {
            if (id == tmp->id)
            {
                printf ("ERRO! Filial com id já cadastrado\n");
                return;
            }
            
        }
        tmp = criaFilial(id);
        ultimaFilial->next = tmp;
        tmp->prev = ultimaFilial;
        ultimaFilial = tmp;
     }   
}

Filiais *removerFilial(int id, Filiais *f)
{

    return NULL;
}

Livro *cadLivroFilial(Filiais *f, char isbn, char autor,int qtdLivros )
{
    Livro *tmp;

    if (!f->livros)
    {
        f->livros  = (Livro *) malloc (sizeof(Livro)); 
        f->livros->right = f->livros->left = NULL;
    }
    else
    {
       // *tmp = 
    }
    return NULL;
}


Livro *cadNovoLivro(Filiais *f, char isbn, char autor,int qtdLivros )
{
    return NULL;
}

Livro *removeLivros(Filiais *f,int id, char isbn)
{

    return NULL;
}

void impressaoFiliais(int id, Filiais *f)
{
    Filiais *tmp = f;

    for(; tmp; tmp=tmp->prev)
    {
        printf("filial: %d\n", tmp->id);
    }
 }

int buscaFiliais(int id, Filiais *f)
{
    return 0;
}

    // funcao de impressao do acervo;
int buscaLivro(Filiais *f, char isbn, char autor,char titulo)
{

    return 0; 
}

void   imprimeAcerivo (Filiais *f )
{

}


