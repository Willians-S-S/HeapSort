#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da lista encadeada
struct node {
    int numero;
    struct node* proximo;
    struct node* anterior;
};

typedef struct node Node;

// Função para trocar dois elementos da lista encadeada
void swap(Node* posLista, Node* pai) {
    int temp = posLista->numero;
    posLista->numero = pai->numero;
    pai->numero = temp;
}

// Função para transformar a lista em um heap máximo
void heapify(Node* posLista) {
    Node* pai = posLista;
    Node* filho_esquerda = posLista->proximo;
    Node* filho_direita = filho_esquerda != NULL ? filho_esquerda->proximo : NULL; // se esquerda for nulo direita recebe nulo, se não direita recebe o proximo de esquerda. 

    // Verifica se o filho esquerdo é maior que o pai
    if (filho_esquerda != NULL && filho_esquerda->numero > pai->numero)
        pai = filho_esquerda;

    // Verifica se o filho direito é maior que o pai ou o filho esquerdo
    if (filho_direita != NULL && filho_direita->numero > pai->numero)
        pai = filho_direita;

    // Se o maior elemento não é o pai, troca os elementos e chama a heapify recursivamente
    if (pai != posLista) {
        swap(posLista, pai);
        heapify(pai);
    }
}

// Função para ordenar a lista usando o heapSort
void heapSort(Node* cabeca) {
    
    Node* last = cabeca;
    while (last->proximo != NULL)
        last = last->proximo;

    for (Node* i = last->anterior; i != NULL; i = i->anterior){
        heapify(i);
    }
}

// Função para imprimir a lista
void printList(Node* cabeca) {
    Node* current = cabeca;
    while (current != NULL) {
        printf("%d ", current->numero);
        current = current->proximo;
    }
    printf("\n");
}

// Função para criar um novo nó da lista
Node* newNode(Node* lista, int numero) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->numero = numero;
    node->proximo = NULL;
    node->anterior = NULL;

    if(!lista) return node;

    Node* aux = lista;
    while(aux->proximo) aux = aux->proximo;

    node->anterior = aux;
    aux->proximo = node;

    return lista;
}

// Exemplo de uso
int main() {
    Node* cabeca = NULL;
    cabeca = newNode(cabeca, 9);
    cabeca = newNode(cabeca,5);
    cabeca = newNode(cabeca, 2);
    cabeca = newNode(cabeca, 7);
    cabeca = newNode(cabeca, 1);
    cabeca = newNode(cabeca, 9);
    cabeca = newNode(cabeca, -1);
    
    printList(cabeca);
    printf("\n");
    heapSort(cabeca);
    printList(cabeca);

}