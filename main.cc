#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "brooks.h"

Filiais *ultimaFilial = NULL;

int main ()
{
    char op;
    while(op != 'q')
    {
        scanf("%c",&op);
        if( op == 'h' )
        {
            int qtdLivros;
            char isbn[5],autor[50],titulo[20];
            for(;;)
            {
                printf("---------//-----------------------//------------------------\n");
                printf("id nova filial: ");                              
                scanf("%d",&qtdLivros);
                if(qtdLivros == -1)
                    break;
                getchar();
                printf("ISBN: ");
                fgets(isbn,5,stdin);  
                getchar();
                printf("Autor: ");
                fgets(autor,50,stdin);                           
                autor[strlen(autor)-1]='\0';
                getchar();
                printf("Titulo: ");
                fgets(titulo,20,stdin);
                titulo[strlen(titulo)-1]='\0';
                getchar();
                printf("\n--------------//------------------------//---------------------\n");
 
               cadLivroFilial(ultimaFilial,isbn,autor,titulo,qtdLivros); 
             }

    }
       if(op == 'j')
        {
            printf("Remover Filial");
            removerFilial(4,ultimaFilial);
        }
        if(op == 'k')
        {
            system("clear");
            impressaoFiliais(ultimaFilial);
            imprimeAcervo(ultimaFilial->livros);
        }
        if(op == 'c')
        {
            int id;
            char endereco[50],nomeGerente[50];
            for(;;)
            {
                printf("---------//-----------------------//------------------------\n");
                printf("id nova filial: ");                              
                scanf("%d",&id);
                if(id == -1)
                    break;
                getchar();
                printf("Nome do Gerente: ");
                fgets(nomeGerente,50,stdin);                           
                nomeGerente[strlen(nomeGerente)-1]='\0';
                getchar();
                printf("Endereço: ");
                fgets(endereco,50,stdin);
                endereco[strlen(endereco)-1]='\0';
                getchar();
                printf("\n--------------//------------------------//---------------------\n");
                cadNovaFilial(id,endereco,nomeGerente);
                
                 
        } 
    }
}
        return 0;
}

