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
        
        }
       if(op == 'j')
        {

        }
        if(op == 'k')
        {
            system("clear");
            impressaoFiliais(ultimaFilial);
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
                fgets(nomeGerente,50,stdin);                           
                strcpy(nomeGerente,nomeGerente);
                printf("Endereço: ");
                fgets(endereco,50,stdin);
                strcpy (endereco,endereco);
                printf("-----------------//------------------------//---------------------");
                cadNovaFilial(id,endereco,nomeGerente);
                
                 
        } 
    }
}
        return 0;
}

