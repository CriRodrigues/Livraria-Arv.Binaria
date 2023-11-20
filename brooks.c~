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
   		printf("Deletar Filial: %d\n",id);

      		if (tmp->prev)
		{
		    // Se não é o primeiro elemento da lista
		    tmp->prev->next = tmp->next;
		}
	       else if (tmp->next)
		{
		    // Se não é o último elemento da lista
		    tmp->next->prev = tmp->prev;
		}

		else
		{
		    // Se não é o último elemento da lista
		    ultimaFilial = tmp->next;
		}

	   }
	   else
	   {
	   	printf("Filial deletada com Sucesso!!");
	    	return 0;
	   }
     }
   return 1;
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
		if (strcmp (isbn, raiz->isbn)< 0)
		{
		     //= criaLivro(isbn, autor, titulo, qtdLivros);
			tmp = tmp->left;
		}
		else
		{
		 	tmp = tmp->right;
		}
	}


		if (strcmp (isbn, raiz->isbn)< 0)
	{
	    last->left = criaLivro(isbn, autor, titulo, qtdLivros);
	}
	else
	{
	    last->right = criaLivro(isbn, autor, titulo, qtdLivros);
	}
    }

}

Livro *buscaLivroNaArvore(Livro *raiz, const char isbn[], const char autor[], const char titulo[], int qtdLivros)
{

    if (strcmp(isbn, raiz->isbn))
    {
        printf("Livro encontrado:\n");
        printf("ISBN: %s\nTítulo: %s\nAutor: %s\nQuantidade de exemplares: %d\n", raiz->isbn, raiz->titulo, raiz->autor, raiz->qtdLivros);
        return raiz;
    }
    else
    {
    	return buscaLivroNaArvore(raiz->left, isbn, autor, titulo, qtdLivros);
    	return buscaLivroNaArvore(raiz->right, isbn, autor, titulo, qtdLivros);
    }
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
int imprimeUmaFilial(Filiais *f, int id)
{
    Filiais *tmp = buscaFilial(id);
  if(tmp->id == id)
  {
	    for(; tmp; tmp=tmp->prev)
	    {
		printf("------------//------------//---------//--------//\n");
		printf("id Filial: %d\nEndereço: %s\nNome do Gerente: %s\n", tmp->id,tmp->endereco,tmp->nomeGerente);
		printf("------------//------------//---------//--------//\n");
	    }
   	
   }else
   return 0;	 
 }

Filiais *buscaFilial(int id)
{
    Filiais *tmp = ultimaFilial;
    for (; tmp; tmp=tmp->prev)
    {
        if (tmp->id == id)
            return tmp;
    }
    return NULL;
}
    // funcao de impressao do acervo;
Livro *buscaLivro(Filiais *f, Livro *raiz, int id, char const isbn[], const char autor[],const char titulo[], int qtdLivros)
{

 Filiais *tmp = buscaFilial(id);

 if (!tmp)
    {
        printf("Filial não encontrada.\n");
        return 0;
    }


    return buscaLivroNaArvore(raiz->left, isbn, autor, titulo, qtdLivros);
    return buscaLivroNaArvore(raiz->right, isbn, autor, titulo, qtdLivros);
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

void imprimeArvore(Livro *t, int s)
{
    const int dist = 5;
    if (!t)
        return;

    s += dist;

    imprimeArvore(t->right, s);

    printf("%*c", s - dist, ' ');
    printf("\033[44m\033[37m%s\033[0m\n", t->isbn);

    imprimeArvore(t->left, s);
}

Livro *removerLivroNaArvore(Livro *raiz, const char isbn[])
{
    if (!raiz)
        return raiz;

    // Se o ISBN a ser removido é menor que o ISBN da raiz,
    // então ele está na subárvore esquerda.
    if (strcmp(isbn, raiz->isbn) < 0)
        raiz->left = removerLivroNaArvore(raiz->left, isbn);

    // Se o ISBN a ser removido é maior que o ISBN da raiz,
    // então ele está na subárvore direita.
    else if (strcmp(isbn, raiz->isbn) > 0)
        raiz->right = removerLivroNaArvore(raiz->right, isbn);

    // Se o ISBN é igual ao ISBN da raiz, então este é o nó a ser removido.
    else
    {
        // Caso com um ou nenhum filho.
        if (raiz->left == NULL)
        {
            Livro *tmp = raiz->right;
            free(raiz);
            return tmp;
        }
        else if (raiz->right == NULL)
        {
            Livro *tmp = raiz->left;
            free(raiz);
            return tmp;
        }

        // Caso com dois filhos: obtenha o sucessor (menor nó na subárvore direita).
        Livro *tmp2 = menorLivro(raiz->right);

        // Copie os dados do sucessor para este nó.
        strcpy(raiz->isbn, tmp2->isbn);
        strcpy(raiz->autor, tmp2->autor);
        strcpy(raiz->titulo, tmp2->titulo);
        raiz->qtdLivros = tmp2->qtdLivros;

        // Remova o sucessor.
        raiz->right = removerLivroNaArvore(raiz->right, tmp2->isbn);
    }

    return raiz;
}

Livro *removerLivro(Filiais *f, int id, const char isbn[])
{


    Filiais *tmp = buscaFilial(id);
    if (!tmp)
    {
        printf("Filial com ID %d não encontrada.\n", id);
        return NULL;
    }

    tmp->livros = removerLivroNaArvore(tmp->livros, isbn);

    return tmp->livros;
}

Livro *menorLivro(Livro *raiz)
{
    Livro *tmp = raiz;

    while (tmp->left != NULL)
        tmp = tmp->left;

    return tmp;
}

 Livro *inserirLivrosDeOutraArvore(Livro *arvoreReceptora, Livro *arvoreDoadora, int idArvoreReceptora, int idArvoreDoadora)
{
    // Verifica se os IDs são diferentes para evitar a remoção da primeira árvore
    Filiais *filialReceptora = buscaFilial(idArvoreReceptora);
    
    Filiais *filialDoadora = buscaFilial(idArvoreDoadora);

    if (filialReceptora == NULL || filialDoadora == NULL)
    {
        printf("Erro: Filial não encontrada.\n");
        return arvoreReceptora;
    }

    if (idArvoreDoadora == idArvoreReceptora)
    {
        printf("Erro: IDs das árvores devem ser diferentes.\n");
        return arvoreReceptora;
    }

    if (arvoreDoadora == NULL)
        return arvoreReceptora;

    // Realiza uma busca pelo livro na árvore receptora usando o ISBN do livro na árvore doadora
    Livro *livroExistente = buscaLivroNaArvore(arvoreReceptora->left, isbn, autor, titulo, qtdLivros);
Livro *livroExistente = buscaLivroNaArvore(arvoreReceptora->right, isbn, autor, titulo, qtdLivros);
    Livro *livroExistente1= buscaLivroNaArvore(arvoreDoadora->left, isbn, autor, titulo, qtdLivros);
Livro *livroExistente1 = buscaLivroNaArvore(arvoreDoadora->right, isbn, autor, titulo, qtdLivros);

    if (strcmp(livroExistente->isbn,livroExistente1->isbn) == 0 )
    {
        // O livro já existe na árvore receptora, então podemos atualizar a quantidade, por exemplo
        livroExistente->qtdLivros += livroExistente->qtdLivros;
    }
    else
    {
        // O livro não existe na árvore receptora, então o inserimos
        arvoreReceptora = insereLivro(arvoreReceptora, arvoreDoadora->isbn, arvoreDoadora->autor, arvoreDoadora->titulo, arvoreDoadora->qtdLivros);
    }

    // Repete o processo para os filhos da árvore doadora
    arvoreReceptora->left = inserirLivrosDeOutraArvore(arvoreReceptora->left, arvoreDoadora->left, idArvoreReceptora, idArvoreDoadora);
    arvoreReceptora->right = inserirLivrosDeOutraArvore(arvoreReceptora->right, arvoreDoadora->right, idArvoreReceptora, idArvoreDoadora);

    // Remove a filial da segunda árvore após a inserção, se necessário
    removerFilial(idArvoreDoadora);


    return arvoreReceptora;
}
