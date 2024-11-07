#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InsertionSort(int lista[], int n) {
    int i, j, aux;
    // Inicializa o contador de trocas
    int trocas = 0;

    for (i = 1; i < n; i++) { // Começa a partir do segundo elemento
        aux = lista[i]; // O elemento a ser inserido
        j = i - 1;

        // Move os elementos que são maiores que aux para uma posição à frente
        while (j >= 0 && lista[j] > aux) {
            lista[j + 1] = lista[j]; // Move o elemento para a direita
            j--; // Decrementa j
            trocas++; // Aumenta o contador de trocas
        }
        lista[j + 1] = aux; // Insere o elemento na posição correta
    }

    // Aqui você pode imprimir o número de trocas se necessário
    printf("Trocas: %d\n", trocas);
}

void printLista(int lista[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int main() {
    int n = 10; // Tamanho da lista (Ajustavel)
    int lista[n];

    srand(time(NULL)); // Inicializa a semente para geração de números aleatórios

    // Preenche a lista com números aleatórios
    for (int i = 0; i < n; i++) {
        lista[i] = rand() % 10000; // Limita o tamanho dos números aleatórios
    }
    
    clock_t inicio, fim;
    double tempo_cpu;
    
    inicio = clock(); // Marca o tempo de início
    InsertionSort(lista, n); // Chama a função de ordenação, use aqui pra trocar o Sort
    fim = clock(); // Marca o tempo de fim
    
    tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo de execução
    
    printf("Tempo de execução: %f segundos\n", tempo_cpu);
    
    // Imprime a lista ordenada
    printf("lista ordenada:\n");
    printLista(lista, n);
    
    return 0;
}
