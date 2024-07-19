#include <stdio.h>
#include <stdlib.h> 

// Função para aplicar deslocamento em um vetor
void desloca_posicoes(int *vetor, int tamanho, int deslocamento) {
    int *temp = (int *)malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++) {
        temp[i] = vetor[i];
    }

    for (int i = 0; i < tamanho; i++) {
        int nova_posicao = (i + deslocamento) % tamanho;
        if (nova_posicao < 0) {
            nova_posicao += tamanho;
        }
        vetor[nova_posicao] = temp[i];
    }

    free(temp);
}

int main() {
    int M, N;
    int teste = 1; // Contador de testes

    while (1) {
        // Lê M (linhas) e N (colunas)
        if (scanf("%d %d", &M, &N) != 2 || (M == 0 && N == 0)) {
            break; // Sai do loop se M e N forem zero (fim da entrada) ou houver erro de leitura
        }
        
        printf("Teste %d\n", teste++); // Imprime o identificador do teste
        
        // Aloca memória para a matriz
        int **matriz = (int **)malloc(M * sizeof(int *));
        for (int i = 0; i < M; i++) {
            matriz[i] = (int *)malloc(N * sizeof(int));
        }
        
        // Lê os elementos da matriz da entrada padrão
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }
        
        // Inicializa acumuladores de deslocamento
        int acumulador_x = 0;
        int acumulador_y = 0;

        // Lê e acumula os comandos de deslocamento
        int x = 0, y = 0;
        while (1) {
            if (scanf("%d %d", &x, &y) != 2 || (x == 0 && y == 0)) {
                break; // Sai do loop se encontrar o comando de término ou houver erro de leitura
            }
            acumulador_x += x;
            acumulador_y += y;
        }
        
        // Aplica o deslocamento acumulado das colunas (horizontal)
        if (acumulador_x != 0) {
            for (int i = 0; i < M; i++) {
                desloca_posicoes(matriz[i], N, acumulador_x);
            }
        }

        // Aplica o deslocamento acumulado das linhas (vertical)
        if (acumulador_y != 0) {
            int *coluna_temp = (int *)malloc(M * sizeof(int));
            for (int j = 0; j < N; j++) {
                for (int i = 0; i < M; i++) {
                    coluna_temp[i] = matriz[i][j];
                }
                desloca_posicoes(coluna_temp, M, -acumulador_y);  // negativo porque Y positivo é para baixo
                for (int i = 0; i < M; i++) {
                    matriz[i][j] = coluna_temp[i];
                }
            }
            free(coluna_temp);
        }

        // Imprime a matriz resultante
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", matriz[i][j]);
            }
            printf("\n");
        }
        
        // Libera a memória alocada para a matriz
        for (int i = 0; i < M; i++) {
            free(matriz[i]);
        }
        free(matriz);
    }
    
    return 0;
}
