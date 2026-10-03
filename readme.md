## Grupo e Problema

# 1. Grupo

• Andre Bortolanza, João Vitor André Alves, Guilherme Dietrich e Fernando Otávio Folador

# 2. Problema Escolhido

Problema: Produto Escalar

• O que é: dados de dois vetores A e B, calcular A · B =
P

• O que implementar: multiplicar os pares correspondentes e somar todos os produtos, gerando um único valor final.

• Ideia de paralelização: cada thread calcula a soma dos produtos de uma faixa dos vetores. Ao final,
as somas parciais são reduzidas a um único resultado. Atualizar uma soma global a cada elemento
deve ser evitado, pois criaria muita contenção.


# 3. Checklist de metodologia

• Use a mesma entrada nas duas versões.

• Meça exatamente a mesma região do algoritmo.

• Não inclua leitura de arquivo em uma versão e exclua na outra.
• Compile ambas com a mesma política de otimização, por exemplo -O2 ou -O3.

• Não altere o algoritmo sequencial apenas para fazê-lo artificialmente pior.

• Registre o número de CPUs lógicas e as características básicas do computador.

• Preserve resultados que contrariem a hipótese inicial.