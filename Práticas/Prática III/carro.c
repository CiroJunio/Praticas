#include "carro.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct funcionario {
    char* nome;
    int matricula;
};


struct carro {
    int chassi;
    char* marca;
    int lugares_no_carro;
    int ano;
    Funcionario* func;
};

Funcionario* FuncionarioAloca() {
    Funcionario* f = (Funcionario*) malloc (sizeof(Funcionario));
    if (f == NULL) {
        printf("Não existe memória para a alocação!\n");
        exit(1);
    }
    return f;
}

void FuncionarioDesaloca(Funcionario** func) {
    free(*func);
}

Carro* CarroAloca(int n) {
    Carro* c = (Carro*) malloc (n * sizeof(Carro));
    if(c == NULL) {
        printf("Não existe memória para a alocação!\n");
        exit(1);
    }
    return c;
}

void CarroDesaloca(Carro** carros, int n) {
    for(int i = 0; i < n; i++) {
        free(carros[i]);
    }
    free(carros);
}

void le(Carro* carros, int n) {
    for(int i = 0; i < n; i++) {
        scanf("%d", &carros[i].chassi);
        scanf("%s", carros[i].marca);
        scanf("%d", &carros[i].lugares_no_carro);
        scanf("%s", carros[i].func->nome);
        scanf("%d", &carros[i].func->matricula);
    }
}

int conta(Carro* carros, int n, const int ano, const int lugares) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (carros[i].ano <= ano && carros[i].lugares_no_carro >= lugares) {
            count += 1;
            continue;
        }
    }
    return count;
}

void imprime(Carro* carros, int n, const char* nome) {
    for (int i = 0; i < n; i++) {
        if (carros[i].func->nome == nome) {
            printf("%s [%d|%d|%d]\n",
                   carros[i].marca, 
                   carros[i].ano,
                   carros[i].lugares_no_carro,
                   carros[i].chassi);
        }
    }
}
