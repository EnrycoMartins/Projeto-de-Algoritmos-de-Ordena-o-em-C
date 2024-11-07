#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void Roda_de_troca(int *x, int *y) {
    int temporario = *x; 
    *x = *y;
    *y = temporario;
}

void Galhos(int lista[], int n, int inicio_raiz) {
    int maior = inicio_raiz; 
    int esquerda = 2 * inicio_raiz + 1; // filho esquerdo
    int direita = 2 * inicio_raiz + 2; // filho direito

    if (esquerda < n && lista[esquerda] > lista[maior]) //esquerdo maior
        maior = esquerda;

    if (direita < n && lista[direita] > lista[maior]) //direito maior
        maior = direita;

    if (maior != inicio_raiz) {
        Roda_de_troca(&lista[inicio_raiz], &lista[maior]); //troca de valores
        Galhos(lista, n, maior);
    }
}

void heapSort(int lista[], int n) {
    for (int indice = n / 2 - 1; indice >= 0; indice--)
        Galhos(lista, n, indice);

    for (int final = n - 1; final >= 0; final--) {
        Roda_de_troca(&lista[0], &lista[final]); // Move a raiz atual para o final
        Galhos(lista, final, 0); // Chama Galhos na árvore reduzida
    }
}
void printLista(int lista[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int main() {
    int n = 100000; // Tamanho da lista (Ajustável)
    int lista[n];

    srand(time(NULL)); // Inicializa a geração de números aleatórios

    // Preenche a lista com números aleatórios
    for (int i = 0; i < n; i++) {
        lista[i] = rand() % 10000; // Limita o tamanho dos números aleatórios
    }


    clock_t inicio, fim;
    double tempo_cpu;

    inicio = clock(); // Marca o tempo de início
    heapSort(lista, n); // Chama a função de ordenação
    fim = clock(); // Marca o tempo de fim

    tempo_cpu = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo de execução

    printf("Tempo de execução: %f segundos\n\n", tempo_cpu);

    // Imprime a lista ordenada
    printf("Lista ordenada:\n\n");
    printLista(lista, n);
    
    printf("Tempo de execução: %f segundos\n\n", tempo_cpu);

    return 0;
}
