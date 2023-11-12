#ifndef PROJECT2_LIBRARY_H
#define PROJECT2_LIBRARY_H

// Definindo a estrutura do tarefa
typedef struct tarefa {
  // Variável da prioridade
  int prioridade;
  // Variável da categoria
  char categoria[30];
  // Variável da descrição
  char descricao[30];
  // Variavel do estado
  char estado[30];

  int numero;

} tarefa;

// Define a estrtura da lista com tarefas
typedef struct {
  // Quantidade de tarefas
  tarefa l[100];
  // Variável da quantidade
  int qtd;
} ListaDetarefas;

// Função que adiciona tarefas
int criartarefa(ListaDetarefas *lt);
// Função que deleta tarefas
int deletartarefa(ListaDetarefas *lt);
// Função que lista os tarefas
int listartarefa(ListaDetarefas lt);
// Função para alterar os tarefas
int alterartarefa(ListaDetarefas *lt);

int filtrodetarefasI(ListaDetarefas *lt);

int filtrodetarefasS(ListaDetarefas *lt);

int exportaprioridade(ListaDetarefas *lt);

int exportacategoria(ListaDetarefas *lt);

int exportacatpri(ListaDetarefas *lt);

//  Função que imprime o menu
void printMenu();
// Função que salva a lista de tarefas no arquivo
int salvarLista(ListaDetarefas lt, char nome[100]);
// Função que carrega os tarefas do arquivo
int carregarLista(ListaDetarefas *lt, char nome[]);

#endif // PROJECT2_LIBRARY_H
