#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da lista encadeada
struct Node {
    int numero;
    struct Node* proximo;
    struct Node* anterior;
};

// Função para trocar dois elementos da lista encadeada
void swap(struct Node* cabeca, struct Node* no) {
    int temp = cabeca->numero;
    cabeca->numero = no->numero;
    no->numero = temp;
}

// Função para transformar a lista em um heap máximo
// void heapify(struct Node* cabeca) {
//     struct Node* maior = cabeca;
//     struct Node* esquerda = cabeca->proximo;
//     struct Node* direita = esquerda != NULL ? esquerda->proximo : NULL; // se esquerda for nulo direita recebe nulo, se não direita recebe o proximo de esquerda.

//     // Verifica se o filho esquerdo é maior que o pai
//     if (esquerda != NULL && esquerda->numero < maior->numero)
//         maior = esquerda;

//     // Verifica se o filho direito é maior que o pai ou o filho esquerdo
//     if (direita != NULL && direita->numero < maior->numero)
//         maior = direita;

//     // Se o maior elemento não é o pai, troca os elementos e chama a heapify recursivamente
//     if (maior != cabeca) {
//         swap(cabeca, maior);
//         heapify(maior);
//     }
// }

// Função para transformar a lista em um heap máximo
void heapify(struct Node* cabeca, struct Node* i) {
    struct Node* maior = i;
    struct Node* esquerda = i->proximo;
    struct Node* direita = esquerda != NULL ? esquerda->proximo : NULL; // se esquerda for nulo direita recebe nulo, se não direita recebe o proximo de esquerda. 

    // Verifica se o filho esquerdo é maior que o pai
    if (esquerda != NULL && esquerda->numero > maior->numero)
        maior = esquerda;

    // Verifica se o filho direito é maior que o pai ou o filho esquerdo
    if (direita != NULL && direita->numero > maior->numero)
        maior = direita;

    // Se o maior elemento não é o pai, troca os elementos e chama a heapify recursivamente
    if (maior != i) {
        swap(i, maior);
        heapify(cabeca, maior);
    }
}

// Função para ordenar a lista usando o heapSort
void heapSort(struct Node* cabeca) {
    
    struct Node* last = cabeca;
    while (last->proximo != NULL)
        last = last->proximo;

    for (struct Node* i = last->anterior; i != NULL; i = i->anterior){
        heapify(cabeca, i);
    }
}


    // Remove o elemento máximo do heap e restaura a propriedade do heap
    // for (struct Node* no = last->anterior; no != NULL; no = no->anterior) {
    //     swap(cabeca, no);
    //     heapify(cabeca, no);
    // }

// Função para imprimir a lista
void printList(struct Node* cabeca) {
    struct Node* current = cabeca;
    while (current != NULL) {
        printf("%d ", current->numero);
        current = current->proximo;
    }
    printf("\n");
}

// Função para criar um novo nó da lista
struct Node* newNode(struct Node* lista, int numero) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->numero = numero;
    node->proximo = NULL;
    node->anterior = NULL;

    if(!lista) return node;

    struct Node* aux = lista;
    while(aux->proximo) aux = aux->proximo;

    node->anterior = aux;
    aux->proximo = node;

    return lista;
}

// Exemplo de uso
int main() {
    struct Node* cabeca = NULL;
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