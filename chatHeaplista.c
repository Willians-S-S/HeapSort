#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da lista encadeada
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Função para trocar dois elementos da lista encadeada
void swap(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Função para transformar a lista em um heap máximo
void heapify(struct Node* head, int n, struct Node* i) {
    struct Node* largest = i;
    struct Node* left = i->next;
    struct Node* right = left != NULL ? left->next : NULL;

    // Verifica se o filho esquerdo é maior que o pai
    if (left != NULL && left->data > largest->data)
        largest = left;

    // Verifica se o filho direito é maior que o pai ou o filho esquerdo
    if (right != NULL && right->data > largest->data)
        largest = right;

    // Se o maior elemento não é o pai, troca os elementos e chama a heapify recursivamente
    if (largest != i) {
        swap(i, largest);
        heapify(head, n, largest);
    }
}

// Função para ordenar a lista usando o heapSort
void heapSort(struct Node* head, int n) {
    // Transforma a lista em um heap máximo
    struct Node* last = head;
    while (last->next != NULL)
        last = last->next;

    for (struct Node* i = last->prev; i != NULL; i = i->prev)
        heapify(head, n, i);

    // Remove o elemento máximo do heap e restaura a propriedade do heap
    for (struct Node* i = last; i != NULL; i = i->prev) {
        swap(head, i);
        heapify(head, i - head, head);
    }
}

// Função para imprimir a lista
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Função para criar um novo nó da lista
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// Exemplo de uso
int main() {
    struct Node* head = newNode(5);
    head->next = newNode(2);
    head->next->prev = head;
    head->next->next = newNode(7);
    head->next->next->prev = head->next;
    head->next->next->next = newNode(1);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = newNode(9);
    head->next->next->next->next->prev = head->next->next->next;
    printList(head);
    printf("\n");
    heapSort(head, 5);
    printList(head);

}