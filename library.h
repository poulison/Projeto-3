#ifndef PROJECT2_LIBRARY_H
#define PROJECT2_LIBRARY_H

// Definindo a estrutura do tarefa
typedef struct tarefa {
  // Variável da prioridade
  int prioridade;
  // Variável da descrição
  char descricao[300];
  // Variável da categoria
  char categoria[100];
  // Variavel do estado
  char progresso[30];
} tarefa;

// Define a estrtura da lista com tarefas
typedef struct {
  // Quantidade de tarefas
  tarefa l[100];
  // Variável da quantidade
  int qtd;
} ListaDetarefas;

// Função que adiciona tarefas
int criartarefa(ListaDetarefas *ll);
// Função que deleta tarefas
int deletartarefa(ListaDetarefas *ll);
// Função que lista os tarefas
int listartarefa(ListaDetarefas ll);
// Função para alterar os tarefas
int alterartarefa(ListaDetarefas *ll);

//  Função que imprime o menu
void printMenu();
// Função que salva a lista de tarefas no arquivo
int salvarLista(ListaDetarefas ll, char nome[]);
// Função que carrega os tarefas do arquivo
int carregarLista(ListaDetarefas *ll, char nome[]);

#endif // PROJECT2_LIBRARY_H
