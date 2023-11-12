#ifndef PROJECT2_LIBRARY_H
#define PROJECT2_LIBRARY_H

// Definindo a estrutura do tarefa
typedef struct tarefa {

  int prioridade;      // Variável da prioridade
  char categoria[30];  // Variável da categoria
  char descricao[100]; // Variável da descrição
  char estado[30];     // Variavel do estado
  int numero;          // Varivale do numero da tarefa

} tarefa;

// Define a estrtura da lista com tarefas
typedef struct {
  tarefa l[100]; // Quantidade de tarefas
  int qtd;       // Variável da quantidade
} ListaDetarefas;

int criartarefa(ListaDetarefas *lt);   // Função que adiciona tarefas
int deletartarefa(ListaDetarefas *lt); // Função que deleta tarefas
int listartarefa(ListaDetarefas lt);   // Função que lista os tarefas
int alterartarefa(
    ListaDetarefas *lt); // funcao para alterar as caracteristicas de uma tarefa
int filtrodetarefasI(
    ListaDetarefas *lt); // funcao para filtrar tarefas com base na prioridade,
                         // categoria ou estado
int filtrodetarefasS(
    ListaDetarefas *lt); // funcao para filtrar tarefas com base na prioridade e
                         // categoria simultaneamente
int exportaprioridade(ListaDetarefas *lt); // funcao para exportar tarefas
                                           // usando prioridade como filtro
int exportacategoria(ListaDetarefas *lt); // funcao para exportar tarefas usando
                                          // categoria como filtro
int exportacatpri(
    ListaDetarefas *lt); // funcao para exportar tarefas usando prioridade e
                         // categoria simultaneamente como filtro

void printMenu(); //  Função que imprime o menu
int salvarLista(
    ListaDetarefas lt,
    char nome[100]); // Função que salva a lista de tarefas no arquivo
int carregarLista(ListaDetarefas *lt,
                  char nome[]); // Função que carrega os tarefas do arquivo

#endif // PROJECT2_LIBRARY_H
