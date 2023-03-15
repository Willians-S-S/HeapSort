#include <stdio.h>
#include <stdlib.h>

// Define a estrutura de um nó da lista ligada
struct Node {
    float data;
    struct Node* next;
};

// Insere um valor na lista ligada
void insert(struct Node** head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    
    // Insere o nó no final da lista
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Remove todos os nós da lista ligada
void clearList(struct Node** head) {
    struct Node* temp = *head;
    while (temp != NULL) {
        *head = temp->next;
        free(temp);
        temp = *head;
    }
}

// Ordena o array usando o algoritmo de Bucket Sort
void bucketSort(float arr[], int n) {
    // Cria um array de listas ligadas vazio
    struct Node* buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }
    
    // Insere cada elemento no bucket correto
    for (int i = 0; i < n; i++) {
        int index = (int)(n * arr[i]);
        insert(&buckets[index], arr[i]);
    }
    
    // Ordena cada bucket usando Insertion Sort e concatena os buckets
    int i = 0;
    for (int j = 0; j < n; j++) {
        struct Node* current = buckets[j];
        while (current != NULL) {
            arr[i++] = current->data;
            current = current->next;
        }
        clearList(&buckets[j]);
    }
}

// Função para imprimir um array
void printArray(float arr[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("]\n");
}

// Função principal
int main() {
    float arr[] = {0.23, 0.45, 0.12, 0.56, 0.78, 0.34};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array original:\n");
    printArray(arr, n);
    
    bucketSort(arr, n);
    
    printf("Array ordenado:\n");
    printArray(arr, n);
    
    return 0;
}
