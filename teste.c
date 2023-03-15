#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó da lista encadeada
struct node {
    float data;
    struct node* next;
};

// Função para inserir um nó no início da lista encadeada
void insert(struct node** head_ref, float data) {
    // Aloca memória para o novo nó
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    // Atribui o dado ao novo nó
    new_node->data = data;
    // Aponta o próximo do novo nó para a cabeça da lista
    new_node->next = (*head_ref);
    // Atualiza a cabeça da lista para o novo nó
    (*head_ref) = new_node;
}

// Função para imprimir os dados da lista encadeada
void printList(struct node* head) {
    while (head != NULL) {
        printf("%.2f ", head->data);
        head = head->next;
    }
}

// Função auxiliar para trocar dois nós na lista encadeada
void swap(struct node* a, struct node* b) {
    float temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Função para ordenar uma lista encadeada usando insertion sort
void insertionSort(struct node* head) {
   struct node *i = head; // ponteiro que percorre a lista da esquerda para direita
   struct node *j; // ponteiro que percorre a lista da direita para esquerda

   while (i != NULL) { // enquanto i não chegar ao fim da lista
       j = i; // j começa na posição atual de i

       while (j != NULL && j->next != NULL) { // enquanto j não chegar ao fim da lista e tiver um próximo elemento

           if (j->data > j->next->data) { // se o dado atual for maior que o próximo dado
               swap(j, j->next); // troca os dados entre eles
           }

           j = j->next; // avança j para direita
       }

       i = i->next; // avança i para direita 
   }
}

// Função principal que implementa o método bucketSort 
void bucketSort(float arr[], int n) {

  int i;

  // Cria N listas encadeadas vazias (uma por balde)
  struct node** buckets = (struct node**)malloc(sizeof(struct node*) * n);
  for (i = 0; i < n; i++) {
      buckets[i] = NULL;
  }

  // Insere os elementos do array nos respectivos baldes 
  for (i = 0; i < n; i++) {
      int bi = n * arr[i]; // calcula o índice do balde usando parte inteira 
      insert(&buckets[bi], arr[i]); // insere o elemento no início da lista encadeada 
  }
}
 