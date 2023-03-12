#include <stdio.h>
#include <stdlib.h>

// Função para trocar dois elementos do array
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Função para transformar o array em um heap máximo
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    // Verifica se o filho esquerdo é maior que o pai
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Verifica se o filho direito é maior que o pai ou o filho esquerdo
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Se o maior elemento não é o pai, troca os elementos e chama a heapify recursivamente
    if (largest != i) {
        swap(arr, i, largest);
        heapify(arr, n, largest);
    }
}

// Função para ordenar o array usando o heapSort
void heapSort(int arr[], int n) {
    // Transforma o array em um heap máximo
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Remove o elemento máximo do heap e restaura a propriedade do heap
    for (int i = n-1; i >= 0; i--) {
        swap(arr, 0, i);
        heapify(arr, i, 0);
    }
}

// Exemplo de uso
int main() {
    int arr[] = {5, 2, 7, 1, 9, 35, 3, 6, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("%d\n", n);
    
    heapSort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    return 0;
}
