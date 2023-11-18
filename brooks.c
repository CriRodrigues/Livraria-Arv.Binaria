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
                printf("erro id ja cadastrado!!\n");
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

int removerFilial(int id)
{
    Filiais *tmp = ultimaFilial;

    for(; tmp; tmp = tmp->prev)
   {
        if(tmp->id == id)
   	{
   		printf("Deleta Filial %d\n",id);     
        	return 1;
        }
   }
   return 0; 
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

void cadLivroFilial(Filiais *f, const char isbn[], const char autor[],const char titulo[],int qtdLivros)
{

    if (!f)
    {
        return;
    }

    if(!f->livros)
    {
        f->livros = criaLivro(isbn, autor, titulo, qtdLivros);
        printf("%s Meu primeiro libro: %s\n", __FUNCTION__, f->livros->titulo);
    }
    else
    {
        insereLivro(f->livros, isbn, autor, titulo, qtdLivros);
    }
}

void insereLivro(Livro *raiz, const char isbn[], const char autor[], const char titulo[],int qtdLivros)
{
     Livro *tmp = NULL;	
     Livro *last = NULL;
    if(raiz)
    {
    	tmp = raiz;
    	for (;tmp;)
        {
        	last = tmp;
		if (atoi(isbn) < atoi(raiz->isbn))
		{
		     //= criaLivro(isbn, autor, titulo, qtdLivros);
			tmp = tmp->left;
		}
		else
		{
		 	tmp = tmp->right;  
		}
	}    
   	
   	
        if (atoi(isbn) < atoi(raiz->isbn))
	{
	    last->left = criaLivro(isbn, autor, titulo, qtdLivros);
	}
	else
	{
	    last->right = criaLivro(isbn, autor, titulo, qtdLivros);
	}
    }
    
}

Livro *removeLivros(Filiais *f,int id, char isbn)
{

    return NULL;
}

void impressaoFiliais(Filiais *f)
{
    Filiais *tmp = f;

    for(; tmp; tmp=tmp->prev)
    {
        printf("------------//------------//---------//--------//\n");
        printf("id Filial: %d\nEndereço: %s\nNome do Gerente: %s\n", tmp->id,tmp->endereco,tmp->nomeGerente);
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

void imprimeAcervo (Livro *raiz)
{
    if (raiz)
    {
        printf("raiz N TA NU\n");
        imprimeAcervo(raiz->left);
        printf("ISBN: %s\n Titulo:%s Autor: %s\n Quanidade de exemplares: %d\n", raiz->isbn, raiz->titulo, raiz->autor, raiz->qtdLivros);
        imprimeAcervo(raiz->right);
    }
    else
        printf("raiz TA NU\n");
}


void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
