#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "brooks.h"

Filiais *ultimaFilial = NULL;

int main ()
{
    char op;
    
    menuFilial();
    /*******
    while(op != 'q')
    {
        scanf("%c",&op);
        if( op == 'h' )
        {

        }
       if(op == 'j')
        {
            int qtdLivros;
            char isbn[5],titulo[20],autor[50];
            printf("Quantidade de Livros: ");
            scanf("%d",&qtdLivros);
                if(qtdLivros == -1)
                    break;
            printf("ISBN: ");
            scanf("%s",isbn);
            printf("Titulo do Livro: ");
            scanf("%s", titulo);
            printf("Autor: ");
            scanf("%s",autor);
            cadLivroFilial(ultimaFilial,isbn,autor,titulo,qtdLivros);
                printf("-----------------//------------------------//---------------------");

        }
        if(op == 'k')
        {
            // system("clear");
            impressaoFiliais(ultimaFilial);
            imprimeAcervo(ultimaFilial->livros);
        }
        if(op == 'c')
        {
            int id;
            char endereco[50],nomeGerente[50];
            for(;;)
            {
                printf("------------//-----------------------//------------------------\n");
                printf("id nova filial: ");
                scanf("%d",&id);
                if(id == -1)
                    break;
                printf("Nome do Gerente: ");
                scanf("%s", nomeGerente);
                printf("Endereço: ");
                scanf("%s", endereco);
                printf("-----------------//------------------------//---------------------");
                cadNovaFilial(id, endereco, nomeGerente);
        }
    }
}
******/
        return 0;
}


