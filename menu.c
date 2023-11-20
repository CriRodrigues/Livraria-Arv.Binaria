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
	printf ("(6) Excluir um livro\n");
	printf ("(7) Voltar ao menu incial\n");
	for(;;)
	{
		op1 = getchar();
		switch ((char)op1)
		{
			default: printf("Opeção Invália");
			break;
			case '1':
					system("clear");
				   if(ultimaFilial && ultimaFilial->livros)
				    imprimeAcervo(ultimaFilial->livros);
			break;
			case '2':
			{
				    int qtdLivros;
				    char isbn[40],titulo[20],autor[50];
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
			
			case '3':
			   
			   int qtdLivros, id;
			   char isbn[40],titulo[20],autor[50];
			   
			   printf("Informe o id: ");
			   scanf("%d",&id);
			    printf("Informe o ISBN: ");
		            scanf("%s",isbn);
			    printf("Titulo do Livro: ");
			    scanf("%s", titulo);
			    printf("Autor: ");
			    scanf("%s",autor);
			    
			buscaLivro(ultimaFilial,ultimaFilial->livros, id, isbn, autor, titulo, qtdLivros);
				break;
			case '4':
				int s = 0;
				system ("clear");				
				imprimeArvore(ultimaFilial->livros, s);
				break;

			case '6':
				int id1;
				char isbn1[40];
				
				printf("informe o id da filial: ");
				scanf("%d", &id1);
				printf("digite o isbn: ");
				scanf("%s", &isbn1);
				removerLivro(ultimaFilial, id1, isbn1);
			
				break;
			
			case '7':

				return;
			break;


		}

	}
}

void menuFilial()
{
	int op, id;

	for(;;)
	{
		printf("\n*** Menu Principal ***\n");
		printf("(1) Listar os dados de todas as filiais\n");
		printf("(2) Listar os dados de uma filial\n");
		printf("(3) Criar nova filial\n");
		printf("(4) Encerrar atividades de uma filial\n");
		printf("(5) Realizar operações no estoque de uma filial\n");
		printf("(6) Imprime Arvore de Livro [ISBN]\n");
		printf("(7) Sair\n");
		op = getchar();

		switch((char)op)
		{
			default:printf("* Opção Inválida\n");
			break;
			case '1':
				system("clear");
		            if(ultimaFilial) 
		                impressaoFiliais(ultimaFilial);
		            else
		                printf("* Não existem filiais cadastradas\n");

		            if (ultimaFilial && ultimaFilial->livros) 
		            {
		                imprimeAcervo(ultimaFilial->livros);
		            }
		            else
                
                        	printf("* Filial sem livros cadastrados\n");
				break;
			
			case '2':
				int id2;
				
				printf("id nova filial: ");
			      	scanf("%d",&id2);
				imprimeUmaFilial(ultimaFilial, id2);
			break;
			case '3':
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
			case'4':
				printf("Digete o id para a remoçao da Filial\n");
				scanf("%d",&id);
				removerFilial(id);
			break;

			case'5':

				menuLivro();
			break;
			case '6':
          printf("De qual filial ?");
				  scanf("%d",&id);
          Filiais *tmp;
          if ((tmp = buscaFilial(id)))
          {
              if (tmp->livros)
                  imprimeArvore(tmp->livros, 0);
              else
                  printf("Filial N contem livros\n");
          }
          else
              printf("Filial N cadastrada\n");
      break;
			case '7':
				exit(0);
		}
	}

}


