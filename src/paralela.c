#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A classe se chama Struct em C
typedef struct {
    double *a;
    double *b;
    long inicio;
    long fim;
    double soma_parcial;
} DadosThread;

void *calcular_parte(void *arg) {
    DadosThread *dados = arg;

    // Cada thread calcula somente do indice inicio ate antes do indice fim.
    dados->soma_parcial = 0.0;
    for (long i = dados->inicio; i < dados->fim; i++) {
        dados->soma_parcial += dados->a[i] * dados->b[i];
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s arquivo_entrada numero_threads\n", argv[0]);
        return 1;
    }

    // Aqui entra o numero de threads digitado no terminal.
    // Exemplo: ./paralela entradas/pequena.txt 4
    // Nesse caso, numero_threads recebe 4.
    int numero_threads = atoi(argv[2]);

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

    pthread_t *threads = malloc(numero_threads * sizeof(pthread_t));
    DadosThread *dados = malloc(numero_threads * sizeof(DadosThread));

    struct timespec inicio, fim;
    clock_gettime(CLOCK_MONOTONIC, &inicio);

    // Aqui o vetor e dividido pelo numero de threads.
    // Exemplo: n = 20000 e numero_threads = 4, entao tamanho_bloco = 5000.
    long tamanho_bloco = n / numero_threads;

    for (int i = 0; i < numero_threads; i++) {
        dados[i].a = a;
        dados[i].b = b;

        // Aqui define qual pedaco do vetor a thread i vai calcular.
        // Thread 0: inicio 0, fim 5000
        // Thread 1: inicio 5000, fim 10000
        // Thread 2: inicio 10000, fim 15000
        // Thread 3: inicio 15000, fim 20000
        dados[i].inicio = i * tamanho_bloco;
        dados[i].fim = (i + 1) * tamanho_bloco;

        // A ultima thread pega o resto caso a divisao nao seja exata.
        if (i == numero_threads - 1) {
            dados[i].fim = n;
        }

        // Aqui a thread e criada e comeca a executar calcular_parte.
        pthread_create(&threads[i], NULL, calcular_parte, &dados[i]);
    }

    double resultado = 0.0;

    for (int i = 0; i < numero_threads; i++) {
        // Aqui o programa espera cada thread terminar.
        pthread_join(threads[i], NULL);

        // Aqui junta a soma parcial da thread no resultado final.
        resultado += dados[i].soma_parcial;
    }

    clock_gettime(CLOCK_MONOTONIC, &fim);

    double tempo = (fim.tv_sec - inicio.tv_sec) +
                   (fim.tv_nsec - inicio.tv_nsec) / 1000000000.0;

    printf("versao,threads,n,resultado,tempo_segundos\n");
    printf("paralela,%d,%ld,%.10f,%.10f\n", numero_threads, n, resultado, tempo);

    free(a);
    free(b);
    free(threads);
    free(dados);

    return 0;
}
