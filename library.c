#include "library.h"
#include "string.h"
#include <stdio.h>


int procuratarefa(ListaDetarefas lt,int numTarefa) { 
  for (int index = 0; index < 100; index++) {
    if (lt.l[index].numero == numTarefa) {
      return index; 
    }
  }
  return -1;
}
//---------------------------------------------------------------

// Função que adiciona tarefas
int criartarefa(ListaDetarefas *lt) {
  printf("-Crie uma tarefa\n");

  printf("\nPrioridade de 0-10: ");
  scanf("%d", &lt->l[lt->qtd].prioridade);
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
  printf("Categoria: ");
  fgets(lt->l[lt->qtd].categoria, 30, stdin); // escanea a categoria que o usuario digitou
  lt->l[lt->qtd].categoria[strcspn(lt->l[lt->qtd].categoria, "\n")] = '\0';

  printf("Descricao: ");
  fgets(lt->l[lt->qtd].descricao, 30,
        stdin); // escanea a descricao que o usuario digitou
  lt->l[lt->qtd].descricao[strcspn(lt->l[lt->qtd].descricao, "\n")] = '\0';

  printf("estado(Completo/Em andamento/Não iniciado): ");
  fgets(lt->l[lt->qtd].estado, sizeof(lt->l[lt->qtd].estado), stdin);
  lt->l[lt->qtd].estado[strcspn(lt->l[lt->qtd].estado, "\n")] = '\0';
  
  lt->l[lt->qtd].numero = lt->qtd + 1;
  
  lt->qtd = lt->qtd + 1;

  return 0;
}
//--------------------------------------------
int deletartarefa(ListaDetarefas *lt) {
  printf("\n-Deletar tarefa\n");
  if (lt->qtd == 0) {
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
  // Loop que percorre os elementos da lista e imprime eles
  for (int i = 0; i < lt.qtd; i++) {
    printf("\n%d. %s: %s (Prioridade: %d, estado: %s)\n", lt.l[i].numero,
           lt.l[i].categoria, lt.l[i].descricao, lt.l[i].prioridade,
           lt.l[i].estado); // updated printf statement
  }

  return 0;
}
//--------------------------------------------

//---------------------------------------------
int alterartarefa(ListaDetarefas *lt) {
  printf("\n-Alterar tarefa\n");

  int numerodatarefa;
  printf("\nNumero da tarefa: ");
  scanf("%d", &numerodatarefa);
  int Ntarefa = procuratarefa(*lt, numerodatarefa);
  if (Ntarefa == -1) {
    printf("\nEssa tarefa não existe\n");
    return 0;
  }
  else{
    int alteração;
    printf("\nSelecione a alteracao que deseja realizar\n1. Prioridade\n2. Categoria\n3. Descrição "
       "\n4. Estado\nopcao: ");
    scanf("%d", &alteração);
    int c;
    switch (alteração) {
    case 1:
      printf("\nPrioridade: ");
      scanf("%d", &lt->l[Ntarefa].prioridade);
      printf("\nPrioridade alterada\n");
      break;
    case 2:
      printf("\nCategoria: ");
      while ((c = getchar()) != '\n' && c != EOF) {}
      fgets(lt->l[Ntarefa].categoria, 30, stdin);
      lt->l[Ntarefa].categoria[strcspn(lt->l[Ntarefa].categoria, "\n")] = '\0';
      printf("\nCategoria alterada\n");
      break;

    case 3:
      printf("\nDescrição: ");
      while ((c = getchar()) != '\n' && c != EOF) {}
      fgets(lt->l[Ntarefa].descricao, 30, stdin);
      lt->l[Ntarefa].descricao[strcspn(lt->l[Ntarefa].descricao, "\n")] = '\0';
      printf("\nDescrição alterada\n");
      break;
    case 4:
      printf("\nEstado: ");
      while ((c = getchar()) != '\n' && c != EOF) {}
      fgets(lt->l[Ntarefa].estado, 30, stdin);
      lt->l[Ntarefa].estado[strcspn(lt->l[Ntarefa].estado, "\n")] = '\0';
      printf("\nEstado alterado\n");
      break;
    
      default:
      printf("\nOpção inválida\n");
      break;
    }
  }
  return 0;
}
//--------------------------------------------------------------
int filtrodetarefasI(ListaDetarefas *lt) {
  if (lt->qtd == 0) {
    printf("\nNão existe nenhum lembrete, crie um\n");
    return 0;
  }
  printf("Qual tipo de filtro deseja usar ?\n1. Prioridade\n2. Categoria\n3. Estado");

  // Solicita o tipo do filtro
  int tipo;
  printf("\nEscolha o Filtro desejado: ");
  scanf("%d", &tipo);

  // Verifica a opção do usuário
  int c;
  switch (tipo) {
  case 1:
    printf("Filtro de prioridade\n");
    int prioridade;
    // Filtra por prioridade
    printf("\nPrioridade desejada: ");
    scanf("%d",&prioridade);
    // Percorre a lista de tarefas
    for (int i = 0; i < lt->qtd; i++) {
      // Verifica se a prioridade da tarefa é igual à prioridade especificada
      if (lt->l[i].prioridade == prioridade) {
        // Imprime o lembrete
        printf("\n%d. %s: %s (Prioridade: %d, estado: %s)\n", i + 1,
         lt->l[i].categoria, lt->l[i].descricao, lt->l[i].prioridade,
         lt->l[i].estado);
      }
      
    }
    break;

  case 2:

    printf("Filtro por categoria\n");
    // Filtra por categoria
    char categoria[30];
    while ((c = getchar()) != '\n' && c != EOF) {}
    printf("\nCategoria desejada: ");
    fgets(categoria, 30, stdin);
    categoria[strcspn(categoria, "\n")] = '\0';
    
    // Percorre a lista de lembretes
    for (int t = 10; t > -1; t--){
      for (int i = 0; i < lt->qtd; i++) {
        int Vcat = strcmp(lt->l[i].categoria, categoria);
        if (lt->l[i].prioridade == t) {
          if (Vcat == 0){
            // Imprime o lembrete
            printf("\n%d. %s: %s (Prioridade: %d, estado: %s)\n", i + 1,
             lt->l[i].categoria, lt->l[i].descricao, lt->l[i].prioridade,
             lt->l[i].estado);
            }
         
          }
        }
      }
    break;

  case 3:
    printf("\n-Opção Filtrar Estado\n");
    char estado[30];

    // Limpa o buffer do teclado
    while ((c = getchar()) != '\n' && c != EOF) {}

    // Lê o estado desejado
    printf("\nEstado desejada: ");
    fgets(estado, sizeof(estado), stdin);
    estado[strcspn(estado, "\n")] = '\0';

    // Percorre a lista de lembretes
    for (int i = 0; i < lt->qtd; i++) {
      // Verifica se o estado da tarefa é igual ao estado desejado
      if (strcmp(lt->l[i].estado, estado) == 0) {
        // Imprime a tarefa
        printf("\n%d. %s: %s (Prioridade: %d, Estado:%s)\n", i + 1, lt->l[i].categoria,
               lt->l[i].descricao, lt->l[i].prioridade,lt->l[i].estado);
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
  // Filtra por prioridade e categoria
  int prioridadedesejada;
  char categoriadesejada[30];
  printf("\nPrioridade desejada: ");
  scanf("%d", &prioridadedesejada);
  printf("\nCategoria desejada: ");
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {}
  fgets(categoriadesejada, 30, stdin);
  categoriadesejada[strcspn(categoriadesejada, "\n")] = '\0';
  // Percorre a lista de lembretes
  for (int i = 0; i < lt->qtd; i++) {
    // Verifica se a prioridade e a categoria da tarefa são iguais
    // às especificadas
    if (lt->l[i].prioridade == prioridadedesejada &&
        strcmp(lt->l[i].categoria, categoriadesejada) == 0) {
      // Imprime a tarefa
      printf("\n%d. %s: %s (Prioridade: %d, Estado:%s)\n", i + 1, lt->l[i].categoria,
         lt->l[i].descricao, lt->l[i].prioridade,lt->l[i].estado);
    }
  }
}


// Função que imprime o menu
void printMenu() {
  printf("\n======= Menu =======\n1. Criar tarefa\n2. Deletar tarefa\n3. "
         "Listar tarefas. \n4. Alterar tarefas"". \n5. Filtrar tarefas de maneira singular. \n6. Filtrar tarefas a partir de Prioridade e Categoria"
         "\n0. Sair\n====================\n");
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



