#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "brooks.h"

Filiais *ultimaFilial = NULL;


int main ()
{
    int id;
    Filiais *filial_1 = criaFilial(0);

    printf("id nova filial ");
    scanf("%d", &id);
    cadNovaFilial(id,'c','c');
    impressaoFiliais(id, ultimaFilial);


    return 0;
}

