# Pensamento Computacional e Algoritmos em C

Cada arquivo .c tem seu próprio main. Compile e execute um arquivo de cada vez.

## Índice

| Arquivos | Conteúdo |
| --- | --- |
| Aula_05 | Consumo de água, cofrinho, atendimento, passos e oito exercícios de repetição |
| Aula_06 | Cadastro de notas, vetores, matrizes, pesquisa e estoque |
| Aula_07 | Doze atividades sobre funções |
| Aula_08 | Sorteio, separação de inteiros, animais, apostadores e participantes |
| Aula_09 | Cinco atividades de registros e arquivos do slide-base, mais um gerador de clientes de teste |

## Como rodar

Baixe ou clone o repositório e abra um terminal na pasta do projeto. Os nomes dos arquivos começam com o número da aula. Exemplo com GCC:

```sh
gcc -std=c17 -Wall -Wextra -pedantic Aula_08_02_separar_e_ordenar.c -lm -o separar
./separar
```

No Windows com GCC, use `-o separar.exe` e execute `.\separar.exe`. Em números decimais, use ponto. Digite nomes completos em linhas separadas quando o exercício pedir.

Para o exercício de separação, digite `8 -3 0 -2 -9 2 7 6 -1 2`. Os positivos pares são `2 2 6 8` e os negativos ímpares são `-9 -3 -1`.

Para atualizar um saldo com dados fictícios, compile e execute primeiro `Aula_09_03a_gerar_clientes_de_teste.c`. Depois rode `Aula_09_03_atualizar_saldo.c` no mesmo diretório. A conta 101 começa com R$ 500,00. Um movimento de `-20` reduz o saldo para R$ 480,00. Os arquivos de dados são gerados no diretório onde os programas são executados.

## Decisões nos enunciados

- Nas aulas 1 a 3, os programas são exemplos de revisão. Na aula 6, exercícios repetidos nos slides têm um único arquivo por enunciado.
- No caixa eletrônico, o usuário informa o estoque inicial. Cada denominação com estoque positivo conserva uma cédula. Na análise de três números, crescente e decrescente indicam ordem estrita.
- Na atividade de animais, o programa cadastra um nome para cada soma encontrada. Para cada número de frequência par, usa sua primeira posição no vetor (contando de 1) para consultar a lista de nomes. Uma posição fora da lista gera a mensagem de ausência de correspondência.
- Na competição de apostadores, a sequência começa em 1, 1, e o programa aceita até 40 termos por participante. Em empates, vale a ordem de cadastro.
- Na atividade de participantes, a idade aceita é de 1 a 170. Na colisão de IDs, a primeira tentativa usa o expoente do enunciado. Nas seguintes, o expoente aumenta em uma unidade. Se as tentativas continuarem gerando colisão ou um resultado fora da faixa numérica, usa-se o menor inteiro positivo disponível. Isso permite concluir o cadastro quando a fórmula sempre devolve o mesmo valor, como na potência de 1. A ordenação por nome usa strcmp, com distinção entre maiúsculas e minúsculas.

Os 50 programas foram compilados e passaram por 57 execuções de teste com o GCC.
