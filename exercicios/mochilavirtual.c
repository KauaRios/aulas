#include <stdio.h>
#include <stdlib.h>
#include<string.h>


	#define ITEM_MAX 10
	
	typedef struct {
		char name[20];
		char tipo[20];
		int quantidade;
}Item;

	
	void cadastrarItem(Item* itens) {
		printf("Digite o nome do item: ");
		scanf("%s", itens->name);
		printf("Digite o tipo do item: ");
		scanf("%s", itens->tipo);
		printf("Digite a quantidade do item: ");
		scanf("%d", &itens->quantidade);
	}

	void removerItem(Item* itens) {
		itens->name[0] = '\0';
		itens->tipo[0] = '\0';
		itens->quantidade = 0;
	}

	void listarItens(Item* itens, int count) {
		
		for (int i = 0; i < count; i++) {
			if (itens[i].quantidade > 0) {
				printf("Item %d: Nome: %s, Tipo: %s, Quantidade: %d\n", i + 1, itens[i].name, itens[i].tipo, itens[i].quantidade);
				
			
			}
			
		}
	
	}

	void buscasequencial(Item* itens, int count, const char* nome) {
		for (int i = 0; i < count; i++) {
			if (strcmp(itens[i].name, nome) == 0) {
				printf("Item encontrado: Nome: %s, Tipo: %s, Quantidade: %d\n", itens[i].name, itens[i].tipo, itens[i].quantidade);
				return;
			}
		}
		printf("Item nao encontrado.\n");
	}


int contarItens(Item* itens, int total) {
    int usados = 0;
    for (int i = 0; i < total; i++) {
        if (itens[i].quantidade > 0) {
            usados++;
        }
    }
    return usados;
}





	int main() {
		Item itens[ITEM_MAX]={0};
		int count = 0;
		int opcao;
		printf("\n===============================\n");
        printf("MOCHILA DE SOBREVIVENCIA\n");
        printf("===============================\n");
		
		
		
		do {
		int usados=contarItens(itens,ITEM_MAX);
		 printf("Itens na mochila: %d/%d\n", usados, ITEM_MAX);

			printf("\n Mochila Virtual \n");
			printf("1. Cadastrar item\n");
			printf("2. Remover item\n");
			printf("3. Listar itens\n");
			printf("4. Buscar item por nome\n");
			printf("5. Sair\n");
			printf("Escolha uma opcao: ");
			scanf("%d", &opcao);
			switch (opcao) {
			case 1:
				if (count < ITEM_MAX) {
					cadastrarItem(&itens[count]);
					count++;
				}
				else {
					printf("Limite de itens atingido.\n");
				}
				break;
			case 2: {
				char nome[20];
				printf("Digite o nome do item a ser removido: ");
				scanf("%s", nome);
				for (int i = 0; i < count; i++) {
					if (strcmp(itens[i].name, nome) == 0) {
						removerItem(&itens[i]);
						printf("Item removido.\n");
						break;
					}
				}
				break;
			}
			case 3:
				listarItens(itens, count);
				break;
			case 4: {
				char nome[20];
				printf("Digite o nome do item a ser buscado: ");
				scanf("%s", nome);
				buscasequencial(itens, count, nome);
				break;
			}
			case 5:
				printf("Saindo...\n");
				break;
			default:
				printf("Opcao invalida.\n");
			}
		} while (opcao != 5);
		return 0;

		





	}
