#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int lista[], int n) 
{
    int meio = n / 2; //Calcula o ponto médio da lista
    int i = 0, j = meio, k = 0; // i=indice da primeira metade da lista, j=indice da segunda metade da lista, k=indice do array auxiliar
    int auxiliar[n]; //array auxiliar para armazenar a lista mesclada
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
    int n = 100; // Tamanho da lista (Ajustavel)
    int lista[n];

    srand(time(NULL)); // Inicializa a semente para geração de números aleatórios

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

/* anotações de tempos demorados com cada tamanho de array pedidos:
		array=100:1°tentativa=0.000015 segundos
				      2°tentativa=0.000010 segundos
				      3°tentativa=0.000015 segundos
				  
		array=1.000:1°tentativa=0.000108 segundos
				        2°tentativa=0.000134 segundos
				        3°tentativa=0.000196 segundos
				   
		array=10.000:1°tentativa=0.001566 segundos
				         2°tentativa=0.001542 segundos
				         3°tentativa=0.001517 segundos
					
		array=50.000:1°tentativa=0.009362 segundos
				         2°tentativa=0.008857 segundos
				         3°tentativa=0.009343 segundos
					
		array=100.000:1°tentativa=0.018194 segundos
				          2°tentativa=0.017318 segundos
				          3°tentativa=0.017433 segundos */
