#include "library.h"
#include "string.h"
#include <stdio.h>



// Função que adiciona tarefas
int criartarefa(ListaDetarefas *lt) {
  printf("Crie uma tarefa\n");

  printf("\nPrioridade: ");
  scanf("%d", &lt->l[lt->qtd].prioridade);
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
  printf("Categoria: ");
  fgets(lt->l[lt->qtd].categoria, 10,
        stdin); // escanea a categoria que o usuario digitou
  lt->l[lt->qtd].categoria[strcspn(lt->l[lt->qtd].categoria, "\n")] = '\0';

  printf("Descricao: ");
  fgets(lt->l[lt->qtd].descricao, 30,
        stdin); // escanea a descricao que o usuario digitou
  lt->l[lt->qtd].descricao[strcspn(lt->l[lt->qtd].descricao, "\n")] = '\0';

  printf("estado(Completo/Em andamento/Não iniciado): ");
  fgets(lt->l[lt->qtd].estado, sizeof(lt->l[lt->qtd].estado), stdin);
  lt->l[lt->qtd].estado[strcspn(lt->l[lt->qtd].estado, "\n")] = '\0';

  lt->qtd = lt->qtd + 1;

  return 0;
}

// Função que deleta tarefas
int deletartarefa(ListaDetarefas *lt) {
  printf("\nDeletar tarefa\n");
  // Erro caso não exista tarefas
  if (lt->qtd == 0) {
    printf("Nao ha tarefas, crie um");
    return 0;
  }
  // Variável do numero do tarefa desejado
  int numerodatarefa;
  printf("\nNumero do tarefa: ");
  // Recebe o numero do tarefa e armazena na variável
  scanf("%d", &numerodatarefa);
  // Verifica se o tarefa existe dentre os já existentes
  if (numerodatarefa < 1 || numerodatarefa > lt->qtd) {
    printf("Esse tarefa nao existe");
  }
  // Caso exista tarefas e o número do tarefa exista...
  else {
    // Loop que percorre os elementos da lista
    for (int i = numerodatarefa; i < lt->qtd; i++) {
      // Atribui o valor do tarefa seguinte ao tarefa desejado
      lt->l[i] = lt->l[i + 1];
    }
    // Diminui o número de tarefas
    lt->qtd--;
    printf("\ntarefa %d deletado", numerodatarefa);
  }
  return 0;
}

// Função que lista os tarefas
int listartarefa(ListaDetarefas lt) {
  printf("\nLista de tarefa\n");
  // Loop que percorre os elementos da lista e imprime eles
  for (int i = 0; i < lt.qtd; i++) {
    printf("\n%d. %s: %s (Prioridade: %d, estado: %s)\n", i + 1,
           lt.l[i].categoria, lt.l[i].descricao, lt.l[i].prioridade,
           lt.l[i].estado); // updated printf statement
  }

  return 0;
}

int procuratarefa(ListaDetarefas lt, int qtd) {
  int local = 0;
  while (local < lt.qtd && lt.l[local].numero != qtd) {
    local++;
  }
  return local == lt.qtd ? 0 : local;
}


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
    void limpar();
    fgets(lt->l[Ntarefa].categoria, sizeof(lt->l[Ntarefa].categoria),
          stdin);
    lt->l[Ntarefa].categoria[strcspn(lt->l[Ntarefa].categoria, "\n")] =
        '\0';
    printf("\nCategoria alterada\n");
    break;
  case 3:
    printf("\nDescrição: ");
    void limpar();
    fgets(lt->l[Ntarefa].descricao, sizeof(lt->l[Ntarefa].descricao),
          stdin);
    lt->l[Ntarefa].descricao[strcspn(lt->l[Ntarefa].descricao, "\n")] =
        '\0';
    printf("\nDescrição alterada\n");
    break;
  case 4:
    printf("\nEstado: ");
    void limpar();
    fgets(lt->l[Ntarefa].estado, sizeof(lt->l[Ntarefa].estado), stdin);
    lt->l[Ntarefa].estado[strcspn(lt->l[Ntarefa].estado, "\n")] = '\0';
    printf("\nEstado alterado\n");
    break;
  default:
    printf("\nOpção inválida\n");
    break;
  }
  return 0;
}

// Função que imprime o menu
void printMenu() {
  printf("\n======= Menu =======\n1. Criar tarefa\n2. Deletar tarefa\n3. "
         "Listar tarefas. \n4. Alterar tarefas"
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

void limpar() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

