#include "library.h"
#include "string.h"
#include <stdio.h>

// funcao para procurar uma tarefa especifica dentro da lista
int procuratarefa(ListaDetarefas lt,
                  int numTarefa) { // percorre a lista para achar o numero
  for (int index = 0; index < 100; index++) {
    if (lt.l[index].numero == numTarefa) {
      return index; // retorna o index
    }
  }
  return -1; // caso nao encotre o index
}
//---------------------------------------------------------------

// Função que adiciona tarefas
int criartarefa(ListaDetarefas *lt) {
  printf("-Crie uma tarefa\n");
  printf("\nPrioridade de 0-10: "); // recebe a prioridade da tarefa
  scanf("%d", &lt->l[lt->qtd].prioridade);
  int c;
  while ((c = getchar()) != '\n' && c != EOF) { // limpa o buffer
  }
  printf("Categoria: "); // recebe a categoria da tarefa
  fgets(lt->l[lt->qtd].categoria, 30,
        stdin); // escaneia a categoria que o usuario digitou
  lt->l[lt->qtd].categoria[strcspn(lt->l[lt->qtd].categoria, "\n")] = '\0';

  printf("Descricao: "); // recebe a descricao da tarefa
  fgets(lt->l[lt->qtd].descricao, 100,
        stdin); // escaneia a descricao que o usuario digitou
  lt->l[lt->qtd].descricao[strcspn(lt->l[lt->qtd].descricao, "\n")] = '\0';

  printf("estado(Completo/Em andamento/Não iniciado): "); // recebe o estado da
                                                          // tarefa
  fgets(lt->l[lt->qtd].estado, sizeof(lt->l[lt->qtd].estado), stdin);
  lt->l[lt->qtd].estado[strcspn(lt->l[lt->qtd].estado, "\n")] =
      '\0'; // escaneia o estado que foi digitado

  lt->l[lt->qtd].numero =
      lt->qtd + 1; //
                   // aumenta a quantidade de tarefas na lista
  lt->qtd = lt->qtd + 1;

  return 0;
}
//--------------------------------------------
// funcao para deletar uma tarefa
int deletartarefa(ListaDetarefas *lt) {
  printf("\n-Deletar tarefa\n");
  if (lt->qtd == 0) { // verifica se existe uma tarefa criada
    printf("Não há tarefas");
    return 0;
  }

  // Valida o número da tarefa
  int numerodatarefa;
  do {
    printf("\nNumero da Tarefa desejada: ");
    scanf("%d", &numerodatarefa);
  } while (numerodatarefa < 1 || numerodatarefa > lt->qtd);

  // Move as tarefas para frente
  for (int i = numerodatarefa; i < lt->qtd - 1; i++) {
    lt->l[i] = lt->l[i + 1];
  }

  // Atualiza a quantidade de tarefas
  lt->qtd--;

  // Imprime a mensagem de sucesso
  printf("\nTarefa %d deletada\n", numerodatarefa);

  return 0;
}
//--------------------------------------------
// Função que lista os tarefas
int listartarefa(ListaDetarefas lt) {
  printf("\n-Lista de tarefa\n");
  for (int i = 0; i < lt.qtd;
       i++) { // Loop que percorre os elementos da lista e imprime eles
    printf("\n%d. %s: %s (Prioridade: %d, estado: %s)\n", lt.l[i].numero,
           lt.l[i].categoria, lt.l[i].descricao, lt.l[i].prioridade,
           lt.l[i].estado); // updated printf statement
  }

  return 0;
}

//---------------------------------------------
// funcao para alterar os elementos de uma tarefa
int alterartarefa(ListaDetarefas *lt) {
  printf("\n-Alterar tarefa\n");
  int numerodatarefa; // variavel que recebe o numero da tarefa que o usuario
                      // deseja alter
  printf("\nNumero da tarefa: "); // recebe o numero da tarefa que o usuario
                                  // deseja alterar
  scanf("%d", &numerodatarefa);
  int Ntarefa = procuratarefa(
      *lt, numerodatarefa); // chama a funcao procura tarefa e recebe o retorno
  if (Ntarefa == -1) {      // verifica se a tarefa existe
    printf("\nEssa tarefa não existe\n");
    return 0;
  } else {
    int alteração; // variavel que recebe a opcao de alteracao da tarefa
    printf("\nSelecione a alteracao que deseja realizar\n1. Prioridade\n2. "
           "Categoria\n3. Descrição "
           "\n4. Estado\nopcao: "); // opcoes de alteracao
    scanf("%d", &alteração);        // recebe a opcao escolhida
    int c;                          // variavel que auxilia a limpeza do buffer
    switch (alteração) {            // switch case para escolher a alteracao
    case 1:                         // alteracao da prioridade
      printf("\nPrioridade: ");
      scanf("%d", &lt->l[Ntarefa].prioridade); // recebe a nova prioridade
      printf("\nPrioridade alterada\n");
      break;
    case 2: // alteracao da categoria
      printf("\nCategoria: ");
      while ((c = getchar()) != '\n' && c != EOF) {
      }                                           // limpa o buffer
      fgets(lt->l[Ntarefa].categoria, 30, stdin); // recebe a nova categoria
      lt->l[Ntarefa].categoria[strcspn(lt->l[Ntarefa].categoria, "\n")] = '\0';
      printf("\nCategoria alterada\n");
      break;

    case 3: // alteracao da descricao
      printf("\nDescrição: ");
      while ((c = getchar()) != '\n' && c != EOF) {
      }                                            // limpa o buffer
      fgets(lt->l[Ntarefa].descricao, 100, stdin); // recebe a nova descricao
      lt->l[Ntarefa].descricao[strcspn(lt->l[Ntarefa].descricao, "\n")] = '\0';
      printf("\nDescrição alterada\n");
      break;
    case 4: // alteracao do estado
      printf("\nEstado: ");
      while ((c = getchar()) != '\n' && c != EOF) {
      }                                        // limpa o buffer
      fgets(lt->l[Ntarefa].estado, 30, stdin); // recebe o novo estado
      lt->l[Ntarefa].estado[strcspn(lt->l[Ntarefa].estado, "\n")] = '\0';
      printf("\nEstado alterado\n");
      break;

    default: // caso o usuario digite um numero invalido
      printf("\nOpção inválida\n");
      break;
    }
  }
  return 0;
}
//--------------------------------------------------------------
// funcao para filtrar tarefas por categoria, prioridade ou estado
int filtrodetarefasI(ListaDetarefas *lt) {
  if (lt->qtd == 0) { // verifica se a lista esta vazia
    printf("\nNão existe nenhuma tarefa, crie um\n");
    return 0;
  }
  printf("Qual tipo de filtro deseja usar ?\n1. Prioridade\n2. Categoria\n3. "
         "Estado");

  // Solicita o tipo do filtro
  int tipo;
  printf("\nEscolha o Filtro desejado: ");
  scanf("%d", &tipo);

  // Verifica a opção do usuário
  int c;
  switch (tipo) { // switch case para escolher o tipo de filtro
  case 1:         // filtro por prioridade
    printf("Filtro de prioridade\n");
    int prioridade;
    printf("\nPrioridade desejada: "); // receptor da prioridade
    scanf("%d", &prioridade);
    for (int i = 0; i < lt->qtd; i++) { // Percorre a lista de tarefas
      if (lt->l[i].prioridade ==
          prioridade) { // Verifica se a prioridade da tarefa é igual à
                        // prioridade especificada
        // Imprime o tarefa encontrado
        printf("\n%d. %s: %s (Prioridade: %d, estado: %s)\n", i + 1,
               lt->l[i].categoria, lt->l[i].descricao, lt->l[i].prioridade,
               lt->l[i].estado);
      }
    }
    break;

  case 2: // filtro por categoria

    printf("Filtro por categoria\n");
    char categoria[30]; // declara uma string para armazenar a categoria
    while ((c = getchar()) != '\n' && c != EOF) {
    } // limpa o buffer
    printf("\nCategoria desejada: ");
    fgets(categoria, 30, stdin); // recebe a categoria
    categoria[strcspn(categoria, "\n")] = '\0';

    for (int t = 10; t > -1; t--) { // Percorre a lista de tarefas
      for (int i = 0; i < lt->qtd; i++) {
        int Vcat = strcmp(lt->l[i].categoria,
                          categoria); // verifica se a categoria é igual a
                                      // categoria especificada
        if (lt->l[i].prioridade == t) {
          if (Vcat == 0) {
            // Imprime o tarefa encontrado
            printf("\n%d. %s: %s (Prioridade: %d, estado: %s)\n", i + 1,
                   lt->l[i].categoria, lt->l[i].descricao, lt->l[i].prioridade,
                   lt->l[i].estado);
          }
        }
      }
    }
    break;

  case 3: // filtro por estado
    printf("\n-Opção Filtrar Estado\n");
    char estado[30];

    // Limpa o buffer do teclado
    while ((c = getchar()) != '\n' && c != EOF) {
    }

    // Lê o estado desejado
    printf("\nEstado desejada: ");
    fgets(estado, sizeof(estado), stdin);
    estado[strcspn(estado, "\n")] = '\0';

    // Percorre a lista de tarefas
    for (int i = 0; i < lt->qtd; i++) {
      // Verifica se o estado da tarefa é igual ao estado desejado
      if (strcmp(lt->l[i].estado, estado) == 0) {
        // Imprime a tarefa
        printf("\n%d. %s: %s (Prioridade: %d, Estado:%s)\n", i + 1,
               lt->l[i].categoria, lt->l[i].descricao, lt->l[i].prioridade,
               lt->l[i].estado);
      }
    }
    break;

  default:
    printf("Opção não existe\n");
  }
  return 0;
}
//--------------------------------------------------------------
int filtrodetarefasS(ListaDetarefas *lt) {
  printf("-Filtrar por categoria e prioridade.\n");
  // Filtra por prioridade e categoria
  int prioridadedesejada;
  char categoriadesejada[30];
  printf("\nPrioridade desejada: ");
  scanf("%d", &prioridadedesejada); // receptor da prioridade
  printf("\nCategoria desejada: ");
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }                                    // limpa o buffer
  fgets(categoriadesejada, 30, stdin); // recebe a categoria
  categoriadesejada[strcspn(categoriadesejada, "\n")] = '\0';
  // Percorre a lista de tarefas
  for (int i = 0; i < lt->qtd; i++) {
    // Verifica se a prioridade e a categoria da tarefa são iguais
    // às especificadas
    if (lt->l[i].prioridade == prioridadedesejada &&
        strcmp(lt->l[i].categoria, categoriadesejada) == 0) {
      // Imprime a tarefa
      printf("\n%d. %s: %s (Prioridade: %d, Estado:%s)\n", i + 1,
             lt->l[i].categoria, lt->l[i].descricao, lt->l[i].prioridade,
             lt->l[i].estado);
    }
  }
  return 0;
}
//-------------------------------
// funcao que exporta a tarefa com base na prioridade dela
int exportaprioridade(ListaDetarefas *lt) {
  printf("-Exportar por prioridade.\n");
  FILE *f = fopen("exportar.txt", "w"); // abre o arquivo
  int prioridade;                       // declara variavel da prioridade
  printf("\nPrioridade desejada: ");    // recebe e le a prioridade desejada
  scanf("%d", &prioridade);
  for (int i = 0; i < lt->qtd; i++) { // Percorre a lista de tarefas
    if (lt->l[i].prioridade ==
        prioridade) { // Verifica se a prioridade da tarefa é igual à prioridade
                      // especificada
      // Imprime a Tarefa no arquivo
      fprintf(
          f,
          "Tarefa %d, Prioridade:%d, Categoria:%s, Estado:%s, Descricao:%s\n",
          i + 1, lt->l[i].prioridade, lt->l[i].categoria, lt->l[i].estado,
          lt->l[i].descricao);
    }
  }
  return 0;
}
//-------------------------------
// funcao que exporta a tarefa com base na categoria
int exportacategoria(ListaDetarefas *lt) {

  printf("-Exportar por categoria e prioridade.\n");
  FILE *f = fopen("exportar.txt", "w"); // abre o arquivo
  char categoria[30]; // variavel que recebe a categoria desejada
  int c;              // limpa o buffer
  while ((c = getchar()) != '\n' && c != EOF) {
  }
  printf("\nCategoria desejada: ");
  fgets(categoria, 30, stdin); // recebe e le a categoria
  categoria[strcspn(categoria, "\n")] = '\0';

  for (int t = 10; t > -1; t--) {       // percorre a lista de tarefas
    for (int i = 0; i < lt->qtd; i++) { // percorre a lista de tarefas
      int Vcat =
          strcmp(lt->l[i].categoria,
                 categoria); // compara a categoria com a categoria desejada
      if (lt->l[i].prioridade == t) { // verifica se a prioridade da tarefa é
                                      // igual à prioridade desejada
        if (Vcat == 0) { // verifica se a categoria da tarefa é igual à
                         // categoria desejada
          // Imprime a tarefa no tarefa
          fprintf(f,
                  "Tarefa %d, Prioridade:%d, Categoria:%s, Estado:%s, "
                  "Descricao:%s\n",
                  i + 1, lt->l[i].prioridade, lt->l[i].categoria,
                  lt->l[i].estado, lt->l[i].descricao);
        }
      }
    }
  }
  return 0;
}

//-------------------------------
// funcao que exporta as tarefas com base na sua prioridade e categoria
int exportacatpri(ListaDetarefas *lt) {
  printf("-Exportar por categoria.\n");
  FILE *f = fopen("exportar.txt",
                  "w");   // abre o arquivo que armazenara as tarefas exportadas
  int prioridadedesejada; // declara variavel que recebe a prioridade
  char categoriadesejada[30]; // declara a variavel que recebe a categoria
  printf("\nPrioridade desejada: "); // recebe e le a prioridade desejada
  scanf("%d", &prioridadedesejada);
  printf("\nCategoria desejada: "); // recebe a catedoria desejada
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }                                    // limpa o buffer
  fgets(categoriadesejada, 30, stdin); // Lê a categoria desejada
  categoriadesejada[strcspn(categoriadesejada, "\n")] =
      '\0';                           // remove o \n do final da string
  for (int i = 0; i < lt->qtd; i++) { // Percorre a lista de tarefas
    if (lt->l[i].prioridade ==
            prioridadedesejada && // Verifica se a prioridade e a categoria da
                                  // tarefa são iguais à prioridade e categoria
                                  // desejadas
        strcmp(lt->l[i].categoria, categoriadesejada) == 0) { //
      // Imprime a tarefa dentro do arquivo na ordem requisitada
      fprintf(
          f,
          "Tarefa %d, Prioridade:%d, Categoria:%s, Estado:%s, Descricao:%s\n",
          i + 1, lt->l[i].prioridade, lt->l[i].categoria, lt->l[i].estado,
          lt->l[i].descricao);
    }
  }
  return 0;
}
// Função que imprime o menu
void printMenu() {
  printf("\n================== Menu ========================\n1. Criar "
         "tarefa\n2. Deletar tarefa\n3. "
         "Listar tarefas. \n4. Alterar tarefas"
         ". \n5. Filtrar tarefas de maneira singular. \n6. Filtrar tarefas a "
         "partir de Prioridade e Categoria\n7. Exportar tarefa por "
         "prioridade\n8. Exportar tarefa por categoria \n9. Exportar tarefa "
         "por categoria e prioridade"
         "\n0. Sair\n================================================\n");
}
// Função que salva a lista em um arquivo
int salvarLista(ListaDetarefas lt, char nome[]) {
  // Abre o arquivo
  FILE *f = fopen(nome, "wb");
  // Verifica se o arquivo foi aberto
  if (f == NULL) {
    return 1;
  }
  // Escreve a lista no arquivo
  fwrite(&lt, sizeof(ListaDetarefas), 1, f);
  // Fecha o arquivo
  fclose(f);
  return 0;
}
int carregarLista(ListaDetarefas *lt, char nome[]) {
  // Abre o arquivo
  FILE *f = fopen(nome, "rb");
  // Verifica se o arquivo foi aberto
  if (f == NULL) {
    return 1;
  }
  // Lê o que está escrito no arquivo
  fread(lt, sizeof(ListaDetarefas), 1, f);
  // Fecha o arquivo
  fclose(f);
  return 0;
}
