#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
void BubbleSort (int lista[], int n)
{
  int atual=0;
  int proximo=0;
  int auxiliar=0;

  for (atual=1; atual<n; atual++) //Compara elementos adjacentes
  {
    for (proximo=0; proximo<n-1; proximo++)
      { 
        if (lista[proximo]>lista[proximo+1] //Verefica se o elemento atual é maior que o proximo
        {
          auxiliar=lista[proximo]; //Armazena o Valor atual
          lista[proximo]=lista[proximo+1]; //Coloca o proximo no lugar do atual
          lista[proximo+1]=auxiliar; //Coloca o valor armazenado no proximo
        }
      }
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
    BubbleSort(lista, n); // Chama a função de ordenação, use aqui pra trocar o Sort
    fim = clock(); // Marca o tempo de fim
    
    tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo de execução
    
    printf("Tempo de execução: %f segundos\n", tempo_cpu);
    
    // Imprime a lista ordenada
    printf("lista ordenada:\n");
    printLista(lista, n);
    
    printf("Tempo de execução: %f segundos\n", tempo_cpu);
    
    return 0;
}

/*anotações de tempos demorados com cada tamanho de array pedidos:
		array=100:1°tentativa=0.000037 segundos
				      2°tentativa=0.000052 segundos
				      3°tentativa=0.000043 segundos
				  
		array=1.000:1°tentativa=0.004078 segundos
				        2°tentativa=0.003759 segundos
				        3°tentativa=0.002764 segundos
				   
		array=10.000:1°tentativa=0.205222 segundos
				         2°tentativa=0.301958 segundos
				         3°tentativa=0.228103 segundos
					
		array=50.000:1°tentativa=7.059930 segundos
				         2°tentativa=7.105029 segundos
				         3°tentativa=7.148405 segundos
					
		array=100.000:1°tentativa=40.537809 segundos
				          2°tentativa=30.976330 segundos
				          3°tentativa=41.008506 segundos     */
