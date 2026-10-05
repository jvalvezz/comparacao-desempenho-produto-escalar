# Produto escalar: como compilar e executar

## Compilacao no Ubuntu

Entre na pasta do projeto e compile:

```bash
cd /caminho/da/pasta/prova-lucca/src
gcc sequencial.c -O2 -o sequencial
gcc paralela.c -O2 -pthread -o paralela
```

## Execucao

Versao sequencial:

```bash
./sequencial entradas/pequena.txt
./sequencial entradas/media.txt
./sequencial entradas/grande.txt
```

Versao paralela:

```bash
./paralela entradas/pequena.txt 2
./paralela entradas/pequena.txt 4
./paralela entradas/pequena.txt 8
./paralela entradas/pequena.txt $(getconf _NPROCESSORS_ONLN)
```

Repita os mesmos comandos para `media.txt` e `grande.txt`.

## O que anotar

Cada execucao imprime:

```text
versao,threads,n,resultado,tempo_segundos
```

Repita cada combinacao pelo menos 3 vezes e guarde os tempos individuais.

## Conferencia

O campo `resultado` da versao sequencial e da paralela deve ser praticamente igual para a mesma entrada.
Pode aparecer uma pequena diferenca nas ultimas casas decimais por causa da ordem diferente das somas com `double`.

## Calculos do relatorio

Para cada entrada e numero de threads:

```text
speedup = tempo_sequencial_medio / tempo_paralelo_medio
eficiencia = speedup / numero_de_threads
```
