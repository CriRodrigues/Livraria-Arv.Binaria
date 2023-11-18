#include <stdio.h>
#include <stdlib.h>

#include "brooks.h" 

extern Filiais *ultimaFilial;
void menuLivro()
{
	int op1;
	
		
	printf("**** Menu Livro ****\n");
	printf ("(1) Imprimir a lista de livros\n");
	printf ("(2) Inserir um novo livro\n"); 
	printf ("(3) Buscar um livro\n");
	printf ("(4) Imprimir a estrutura da árvore binária de busca\n");
	printf ("(5) Excluir um livro\n");
	printf ("(6) Voltar ao menu incial\n");
	for(;;)
	{
		op1 = getchar();
		switch ((char)op1)
		{
			default: printf("Opeção Invália");
			break;
			case '1':
				if(ultimaFilial)
				 imprimeAcervo(ultimaFilial->livros);
			break;
			case '2':
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
			break;
			
			case '6':
				
				return;
			break; 
		
		
		}
	
	}	
}

void menuFilial()
{
	int op;
	
	for(;;)
	{	
		printf("*** Menu Principal ***\n"); 
		printf("(1) Listar os dados de todas as filiais\n");
		printf("(2) Listar os dados de uma filial\n"); 
		printf("(3) Criar nova filial\n");
		printf("(4) Encerrar atividades de uma filial\n");
		printf("(5) Realizar operações no estoque de uma filial\n"); 
		printf ("(6) Sair\n");
		op = getchar();
		
		switch((char)op)
		{
			default:printf("Opção Inválida\n");
			break;
			case '1':
			 // system("clear");
			    impressaoFiliais(ultimaFilial);
			    imprimeAcervo(ultimaFilial->livros);
			break;	
			case '2':
			break;
			case '3': 
			    int id;
			    char endereco[50],nomeGerente[50];
			    for(;;)
			    {
			      	printf("-----//----------//-------------\n");
				printf("id nova filial: ");
				scanf("%d",&id);
				if(id == -1)
				    break;
				printf("Nome do Gerente: ");
				scanf("%s", nomeGerente);
				printf("Endereço: ");
				scanf("%s", endereco);
				printf("-----//----------//-------------\n");
				cadNovaFilial(id, endereco, nomeGerente);	
			    }
			break;
			case'5':
			
				menuLivro();
			break;		
			case '6':
				exit(0);
			break;
		}
	}		 

}


