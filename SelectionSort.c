#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
void selectionSort(int lista[], int n) //Função
{
    int i; 
    int j; 
    int menor_elemento; //Variáveis
    int troca;

    for (i = 0; i < n - 1; i++) 
    {
        menor_elemento = i; //Assume o primeiro como menor

        for (j = i + 1; j < n; j++) 
        {
            if (lista[j] < lista[menor_elemento])
            {
                menor_elemento = j; //Assume o novo menor 
            }
        }
        
        troca = lista[menor_elemento]; //Variável temporária-roda
        lista[menor_elemento] = lista[i]; 
        lista[i] = troca; 
    }
}
void printLista(int lista[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}
int main() {
    int n = 100000; // Tamanho da lista (Ajustavel)
    int lista[n];

    srand(time(NULL)); // Inicializa a geração de números aleatórios

    // Preenche a lista com números aleatórios
    for (int i = 0; i < n; i++) {
        lista[i] = rand() % 10000; // Limita o tamanho dos números aleatórios
    }
    
    clock_t inicio, fim;
    double tempo_cpu;
    
    inicio = clock(); // Marca o tempo de início
    selectionSort(lista, n); // Chama a função de ordenação, use aqui pra trocar o Sort
    fim = clock(); // Marca o tempo de fim
    
    tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo de execução
    
    printf("Tempo de execução: %f segundos\n", tempo_cpu);
    
    // Imprime a lista ordenada
    printf("lista ordenada:\n");
    printLista(lista, n);
    
    printf("Tempo de execução: %f segundos\n", tempo_cpu);
    return 0;
}
