#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s arquivo_entrada\n", argv[0]);
        return 1;
    }

    FILE *arquivo = fopen(argv[1], "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    long n;
    fscanf(arquivo, "%ld", &n);

    double *a = malloc(n * sizeof(double));
    double *b = malloc(n * sizeof(double));

    for (long i = 0; i < n; i++) {
        fscanf(arquivo, "%lf %lf", &a[i], &b[i]);
    }

    fclose(arquivo);

    struct timespec inicio, fim;
    clock_gettime(CLOCK_MONOTONIC, &inicio);

    // Versao sequencial: um unico for calcula o vetor inteiro.
    double resultado = 0.0;
    for (long i = 0; i < n; i++) {
        resultado += a[i] * b[i];
    }

    clock_gettime(CLOCK_MONOTONIC, &fim);

    double tempo = (fim.tv_sec - inicio.tv_sec) +
                   (fim.tv_nsec - inicio.tv_nsec) / 1000000000.0;

    printf("versao,threads,n,resultado,tempo_segundos\n");
    printf("sequencial,1,%ld,%.10f,%.10f\n", n, resultado, tempo);

    free(a);
    free(b);

    return 0;
}
