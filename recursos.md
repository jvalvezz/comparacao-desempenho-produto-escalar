# Recursos utilizados

- Linguagem C.
- Biblioteca `pthread.h` para criar e controlar threads.
- Compilador `gcc`.
- Opcao de otimizacao `-O2`.
- Opcao `-pthread` para compilar a versao paralela.
- Ubuntu/WSL para executar os testes.
- Acesso aos arquivos do Windows pelo caminho `/mnt/c/prova-lucca`.
- Arquivos de entrada `pequena.txt`, `media.txt` e `grande.txt`.
- Comando `getconf _NPROCESSORS_ONLN` para descobrir o maximo de CPUs logicas da maquina.
- Medicao de tempo com `clock_gettime(CLOCK_MONOTONIC, ...)`.
- Arquivo `resultado.csv` para armazenar os tempos brutos das execucoes.
- Canva para editar os slides da apresentacao.
