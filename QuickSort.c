#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função que realiza a partição do vetor e retorna a posição do pivô
int particiona(int *v, int inicio, int final) {
    int esq, dir, pivo, aux;
    esq = inicio; 
    dir = final; 
    pivo = v[inicio]; 

    while (esq < dir) {
        // Move o índice esquerdo para a direita enquanto o elemento for menor ou igual ao pivô
        while (v[esq] <= pivo && esq < final) // Verifica se esq não ultrapassa final
            esq++; // Incrementa esq

        // Move o índice direito para a esquerda enquanto o elemento for maior que o pivô
        while (v[dir] > pivo && dir > inicio) // Verifica se dir não ultrapassa inicio
            dir--; // Decrementa dir

        // Se os índices esquerdo e direito ainda não se cruzaram
        if (esq < dir) {
            // Troca os elementos em esq e dir
            aux = v[esq]; // Armazena o valor de v[esq] em aux
            v[esq] = v[dir]; // Atribui v[dir] a v[esq]
            v[dir] = aux; // Atribui o valor armazenado em aux a v[dir]
        }
    }

    // Coloca o pivô na posição correta
    v[inicio] = v[dir]; // Move o elemento em dir para a posição de início
    v[dir] = pivo; // Coloca o pivô na posição dir, que é a posição correta após a partição

    return dir; // Retorna a posição do pivô
}

// Função que realiza o algoritmo QuickSort
void QuickSort(int *v, int inicio, int final) {
    int pivo; // Declaração da variável pivo para armazenar a posição do pivô
    // Verifica se a partição tem mais de um elemento
    if (final > inicio) {
        // Chama a função particiona e obtém a posição do pivô
        pivo = particiona(v, inicio, final);
        // Chama recursivamente QuickSort para a parte esquerda da partição
        QuickSort(v, inicio, pivo - 1);
        // Chama recursivamente QuickSort para a parte direita da partição
        QuickSort(v, pivo + 1, final);
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
    QuickSort(lista, 0, n - 1); // Chama a função de ordenação
    fim = clock(); // Marca o tempo de fim

    tempo_cpu = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo de execução

    printf("Tempo de execução: %f segundos\n\n", tempo_cpu);

    // Imprime a lista ordenada
    printf("Lista ordenada:\n\n");
    printLista(lista, n);
    
     printf("Tempo de execução: %f segundos\n\n", tempo_cpu);

    return 0;
}
