#include <stdio.h>
#include <stdlib.h>

// Existem dois tipos de heap
// I. heap máximo
// II. heap mínimo

// Função para trocar dois elementos do array
void swap(int vetor[], int pos, int pai) {
    int temp = vetor[pos];
    vetor[pos] = vetor[pai];
    vetor[pai] = temp;
}


// A função heapify é usada para transformar um array em um heap, que é uma estrutura de dados que se organiza como
// uma árvore binária em que cada elemento pode ter um filho esquerdo e direito, e o menor (ou maior) elemento fica no
// topo1. A função recebe três parâmetros: arr[], que é o array a ser transformado em heap; n, que é o tamanho do array; 
// e i, que é o índice do elemento pai que será comparado com seus filhos.

// A função faz o seguinte:

// Define a variável largest como i, ou seja, assume que o elemento pai é o maior (se for um max-heap) ou menor (se for um min-heap) entre ele e seus filhos.
// Define as variáveis filho_esquerdo e right como os índices dos filhos esquerdo e direito do elemento pai, usando a fórmula 2i + 1 para o esquerdo e 2i + 2 para o direito2.
// Verifica se o filho esquerdo existe (ou seja, se left < n) e se ele é maior (ou menor) que o elemento pai (ou seja, se arr[left] > arr[largest]). Se for verdadeiro, atualiza a variável largest com o valor de left.
// Verifica se o filho direito existe (ou seja, se right < n) e se ele é maior (ou menor) que o elemento pai ou o filho esquerdo (ou seja, se arr[right] > arr[largest]). Se for verdadeiro, atualiza a variável largest com o valor de right.

// Se a variável largest não for igual a i, significa que houve uma troca entre o elemento pai e um dos filhos. Nesse caso, chama a função swap para trocar os elementos no array e chama a função heapify recursivamente para verificar se há mais trocas necessárias na subárvore abaixo do elemento trocado.

// Função para transformar o array em um heap máximo
void heapify(int vetor[], int tamanho, int pos) {
    int pai = pos;
    int filho_esquerdo = 2*pos + 1;
    int filho_direito = 2*pos + 2;

    // Verifica se o filho esquerdo é maior que o pai
    if (filho_esquerdo < tamanho && vetor[filho_esquerdo] > vetor[pai])
        pai = filho_esquerdo;

    // Verifica se o filho direito é maior que o pai ou o filho esquerdo
    if (filho_direito < tamanho && vetor[filho_direito] > vetor[pai])
        pai = filho_direito;

    // Se o maior elemento não é o pai, troca os elementos e chama a heapify recursivamente
    if (pai != pos) {
        swap(vetor, pos, pai);
        heapify(vetor, tamanho, pai);
    }
}

// Função para ordenar o array usando o heapSort
void heapSort(int vetor[], int tamnaho) {
    // Transforma o array em um heap máximo
    for (int i = tamnaho/2 - 1; i >= 0; i--)
        heapify(vetor, tamnaho, i);
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
