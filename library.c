#include "library.h"
#include "string.h"
#include <stdio.h>

// Função que adiciona tarefas
int criartarefa(ListaDetarefas *ll) {
  printf("\nNovo tarefa\n");
  printf("Prioridade: ");
  // Recebe a entrada do usuário e armazena no array da opção prioridade
  scanf("%d", &ll->l[ll->qtd].prioridade);
  // Limpa o buffer
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
  printf("Categoria: ");
  // Recebe a entrada do usuário e armazena no array da opção categoria
  gets(ll->l[ll->qtd].categoria);
  // Substitui qualquer caractere que não seja letra, no caso \n, por \0 para
  // simbolizar o final da string
  ll->l[ll->qtd].categoria[strcspn(ll->l[ll->qtd].categoria, "\n")] = '\0';
  printf("Descricao: ");
  // Recebe a entrada do usuário e armazena no array da opção descrição
  gets(ll->l[ll->qtd].descricao);

  printf("Progresso: ");
  // Recebe a entrada do usuário e armazena no array da opção progresso
  gets(ll->l[ll->qtd].progresso);
  // Substitui qualquer caractere que não seja letra, no caso \n, por \0 para
  // simbolizar o final da string
  ll->l[ll->qtd].descricao[strcspn(ll->l[ll->qtd].descricao, "\n")] = '\0';
  // Aumenta a quantidade/número do tarefa
  ll->qtd = ll->qtd + 1;
  return 0;
}

// Função que deleta tarefas
int deletartarefa(ListaDetarefas *ll) {
  printf("\nDeletar tarefa\n");
  // Erro caso não exista tarefas
  if (ll->qtd == 0) {
    printf("Nao ha tarefas, crie um");
  }
  // Variável do numero do tarefa desejado
  int numerodotarefa;
  printf("\nNumero do tarefa: ");
  // Recebe o numero do tarefa e armazena na variável
  scanf("%d", &numerodotarefa);
  // Verifica se o tarefa existe dentre os já existentes
  if (numerodotarefa < 1 || numerodotarefa > ll->qtd) {
    printf("Esse tarefa nao existe");
  }
  // Caso exista tarefas e o número do tarefa exista...
  else {
    // Loop que percorre os elementos da lista
    for (int i = numerodotarefa; i < ll->qtd; i++) {
      // Atribui o valor do tarefa seguinte ao tarefa desejado
      ll->l[i] = ll->l[i + 1];
    }
    // Diminui o número de tarefas
    ll->qtd--;
    printf("\ntarefa %d deletado", numerodotarefa);
  }
  return 0;
}

// Função que lista os tarefas
int listartarefa(ListaDetarefas ll) {
  printf("\nLista de tarefa\n");
  // Loop que percorre os elementos da lista e imprime eles
  for (int i = 0; i < ll.qtd; i++) {
    printf("\n%d. %s: %s (Prioridade: %d)\n", i + 1, ll.l[i].categoria,
           ll.l[i].descricao, ll.l[i].prioridade, ll.l[i].progresso);
  }
  return 0;
}

// Função para alterar os tarefas
int alterartarefa(ListaDetarefas *ll) {
  printf("\nAlterar tarefa\n");
  // Erro caso não exista tarefas
  if (ll->qtd == 0) {
    printf("Nao ha tarefas, crie um");
  }
  // Variável do numero do tarefa desejado
  int numerodotarefa;
  printf("\nNumero do tarefa: ");
  // Recebe o numero do tarefa e armazena na variável
  scanf("%d", &numerodotarefa);
  // Verifica se o tarefa existe dentre os já existentes
  if (numerodotarefa < 1 || numerodotarefa > ll->qtd) {
    printf("Esse tarefa nao existe");
  }
  // Caso exista tarefas e o número do tarefa exista...
  else {
    // Variável do numero da categoria desejada
    int categoria;
    printf("\nCategoria: ");
    // Recebe o numero da categoria e armazena na variável
    scanf("%d", &categoria);
    // Verifica se a categoria existe dentre as existentes
    if (categoria < 1 || categoria > ll->qtd) {
      printf("Essa categoria nao existe");
      return 0;
      // Caso exista categoria e o número da categoria exista...
      else {
        // Variável da descrição desejada
        char descricao[100];
        printf("\nDescricao: ");
        // Recebe a descrição e armazena na variável
        scanf("%s", descricao);
        // Variável da prioridade desejada
        int prioridade;
        printf("\nPrioridade: ");
        // Recebe a prioridade e armazena na variável
        scanf("%d", &prioridade);
        // Variável do progresso desejado
        int progresso;
        printf("\nProgresso: ");
        // Recebe o progresso e armazena na variável
        scanf("%d", &progresso);
        // Atribui os valores dos campos do tarefa desejado
        ll->l[numerodotarefa - 1].categoria = categoria;
        ll->l[numerodotarefa - 1].descricao = descricao;
        ll->l[numerodotarefa - 1].prioridade = prioridade;
        ll->l[numerodotarefa - 1].progresso = progresso;
        printf("\ntarefa %d alterado", numerodotarefa);
        return 0;
      }

      // Função que imprime o menu
      void printMenu() {
        printf("\n======= Menu =======\n1. Criar tarefa\n2. Deletar "
               "tarefa\n3. "
               "Listar tarefas\n0. Sair\n====================\n");
      }
      // Função que salva a lista em um arquivo
      int salvarLista(ListaDetarefas ll, char nome[]) {
        // Abre o arquivo
        FILE *f = fopen(nome, "wb");
        // Verifica se o arquivo foi aberto
        if (f == NULL) {
          return 1;
        }
        // Escreve a lista no arquivo
        fwrite(&ll, sizeof(ListaDetarefas), 1, f);
        // Fecha o arquivo
        fclose(f);
        return 0;
      }
      int carregarLista(ListaDetarefas * ll, char nome[]) {
        // Abre o arquivo
        FILE *f = fopen(nome, "rb");
        // Verifica se o arquivo foi aberto
        if (f == NULL) {
          return 1;
        }
        // Lê o que está escrito no arquivo
        fread(ll, sizeof(ListaDetarefas), 1, f);
        // Fecha o arquivo
        fclose(f);
        return 0;
      }

      //funcao de listar por prioridade
      int listarprioridade(ListaDetarefas ll) {
        printf("\nTarefas prioritarias\n");
        // Loop que percorre os elementos da lista e imprime eles
        for (int i = 0; i < ll.qtd; i++) {
          printf("\n%d. %s: %s (Prioridade: %d)\n", i + 1, ll.l[i].categoria,
                 ll.l[i].descricao, ll.l[i].prioridade, ll.l[i].progresso);
        }
        return 0;
      }