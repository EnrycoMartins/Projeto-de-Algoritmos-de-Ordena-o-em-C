void selectionSort(int vet[], int num_total) //Função
{
    int i; 
    int j; 
    int menor_elemento; //Variáveis
    int troca;

    for (i = 0; i < num_total - 1; i++) 
    {
        menor_elemento = i; //Assume o primeiro como menor

        for (j = i + 1; j < num_total; j++) 
        {
            if (vet[j] < vet[menor_elemento])
            {
                menor_elemento = j; //Assume o novo menor 
            }
        }
        
        troca = vet[menor_elemento]; //Variável temporária-troca dos valores
        vet[menor_elemento] = vet[i]; 
        vet[i] = troca; 
    }
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
    selectionsort(lista, n); // Chama a função de ordenação, use aqui pra trocar o Sort
    fim = clock(); // Marca o tempo de fim
    
    tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo de execução
    
    printf("Tempo de execução: %f segundos\n", tempo_cpu);
    
    // Imprime a lista ordenada
    printf("lista ordenada:\n");
    printLista(lista, n);
    
    return 0;
}
