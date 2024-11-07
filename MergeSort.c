#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int lista[], int n) 
{
    int meio = n / 2; //Calcula o ponto médio da lista
    int i = 0, j = meio, k = 0; // i=indice da primeira metade da lista, j=indice da segunda metade da lista, k=indice da lista auxiliar
    int auxiliar[n]; //lista auxiliar para armazenar a lista mesclada
    while( i < meio && j < n ) //Mescla as duas metades ordenadas
    {
        if( lista[i] <= lista[j] )
            auxiliar[k] = lista[i++]; //Copia o elemento da primeira metade
        else
            auxiliar[k] = lista[j++]; //Copia o elemento da segunda metade
            k++;
    }
    //Copia os elementos restantes da primeira metade se houver
	if( i == meio )
    while( j < n )
        auxiliar[k++] = lista[j++];
    else
    while( i < meio ) //Copia os elemento restantes da segunda metade se houver
        auxiliar[k++] = lista[i++];
    for( i = 0; i < n; i++ ) // Copias os elementos ordenados de volta para a lista original
        lista[i] = auxiliar[i];
}

void MergeSort(int lista[], int n)
{
    int meio = n / 2; //Calcula o ponto médio da lista
    if( n > 1 )
    {
        MergeSort(lista, meio); //Ordena recursivamente a primeira metade da lista
        MergeSort(lista+meio, n-meio); //Ordena recursivamente a segunda metade da lista
        merge(lista, n); //Mescla as duas metades ordenadas
    }
}
void printLista(int lista[], int n) 
{
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}
int main() 
{
    int n = 100000; // Tamanho da lista (Ajustavel)
    int lista[n];

    srand(time(NULL)); // Inicializa a geração de números aleatórios

    // Preenche a lista com números aleatórios
    for (int i = 0; i < n; i++) {
        lista[i] = rand() % 100000; // Limita o tamanho dos números aleatórios
    }
    
    clock_t inicio, fim;
    double tempo_cpu;
    
    inicio = clock(); // Marca o tempo de início
    MergeSort(lista, n); // Chama a função de ordenação, use aqui pra trocar o Sort
    fim = clock(); // Marca o tempo de fim
    
    tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo de execução
    
    printf("Tempo de execução: %f segundos\n", tempo_cpu);
    
    // Imprime a lista ordenada
    printf("lista ordenada:\n");
    printLista(lista, n);
    
    printf("Tempo de execução: %f segundos\n", tempo_cpu);
    
    return 0;
}
