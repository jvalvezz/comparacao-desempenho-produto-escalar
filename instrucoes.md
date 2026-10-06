# Instrucoes de compilacao e execucao

Os programas foram executados no Ubuntu/WSL acessando os arquivos do Windows pelo caminho:

```bash
/mnt/c/prova-lucca
```

## 1. Acessar a pasta do projeto

```bash
cd /mnt/c/prova-lucca/src
```

## 2. Compilar a versao sequencial

```bash
gcc sequencial.c -O2 -o sequencial
```

## 3. Compilar a versao paralela

```bash
gcc paralela.c -O2 -pthread -o paralela
```

## 4. Descobrir o maximo de CPUs logicas

```bash
getconf _NPROCESSORS_ONLN
```

No computador utilizado, o valor retornado foi:

```text
12
```

Portanto, a configuracao maxima testada foi com `12` threads.

## 5. Executar com a entrada pequena

```bash
./sequencial entradas/pequena.txt
./paralela entradas/pequena.txt 2
./paralela entradas/pequena.txt 4
./paralela entradas/pequena.txt 8
./paralela entradas/pequena.txt 12
```

## 6. Executar com a entrada media

```bash
./sequencial entradas/media.txt
./paralela entradas/media.txt 2
./paralela entradas/media.txt 4
./paralela entradas/media.txt 8
./paralela entradas/media.txt 12
```

## 7. Executar com a entrada grande

```bash
./sequencial entradas/grande.txt
./paralela entradas/grande.txt 2
./paralela entradas/grande.txt 4
./paralela entradas/grande.txt 8
./paralela entradas/grande.txt 12
```

## 8. Repeticoes

Cada combinacao de entrada e configuracao deve ser executada pelo menos 3 vezes.

Exemplo:

```bash
./paralela entradas/grande.txt 4
./paralela entradas/grande.txt 4
./paralela entradas/grande.txt 4
```

Os tempos individuais devem ser salvos no arquivo `resultado.csv`.
