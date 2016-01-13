//
//  cob.h
//  Cobi
//
//  Created by Daniel Pereira on 1/5/16.
//  Copyright (c) 2016 Akangatu. All rights reserved.
//

#include <stdio.h>
#include "stat.h"
#include "Alloc.h"
#include "GFPrime.h"

//definition of the initial simulation parameters

#define ORDEM 2 // Order of the Galois Fields
#define K 2 // Number of sources
#define AMOSTRAS 1024 // number of observations
#define MAXIT 700 // max number of iterations
#define POPINICIAL 2 // initial population
#define POPMAX 100 // maximum population
#define CLONESMAX 10 // maximum number of clones
#define CLONESMIN 3 // min number of clones
#define RAIOSUP .0625 // it is almost as a % of how diferent the matrix must be from one another in order to not be in the same supression radious. x/k^2 with x being the number of different values
#define C0 .5 // initial concentration
#define ZERO .0000001
#define BETAI 2
#define BETAF .2

typedef struct candidato {
    double fit;
    double afi;
    double concentracao;
    int **mat;
} Candidato;

typedef struct clonecandidato {
    int **mat;
}CloneCandidato;


// --- Coisas não especificas do algoritmo que vou precisar --- //

int aleatorio_int (int limite); // cria numero aleatório de 0 até "limite"

void copiaMatrizAparaB (int **A, int **B, int linha, int coluna); //copia todos os valores de uma matriz para outra de um para um

void copiaCandidatoAparaB(Candidato A, Candidato B, int linha, int coluna); // copia todos os valores de uma variavel tipo candidato para outra

void abreArquivos (int t, int amostras, int **fontes); // criar txts para cada teste com outputs sobre a simulação

// --- Fim das coisas não especificas --- //

// --- Não fazem parte da cobainet mas são importantes--- //

void geraFontes (int **fontes, int **prob, int linha, int coluna, int ordem, const gsl_rng * r); // gera as fontes usadas na simulação a partir da matriz de probabilidade definida no inicio da simulacao (no main.c)

void geraMatrizInversivel (int **mistura); // cria uma matriz que é inversivel

void probabilidadeParaEntropia (double **prob, int **mat, int linha, int coluna); // calcula a probabilidade de cada elemento em cada coordenada ij da matriz (mat é  produto Candidato * Misutra) usado no calculo da entropia

double entropia (double **prob, int n, int k); // retornar o valor da entropia de uma matriz a partir de suas probabilidades

double distanciaR (int **mat1, int **mat2, int linha, int coluna); // para o calculo da distancia entre duas soluções, ja que não são pontos em coordenadas para medir a distancia euclidiana, a distancia é medida pelo numero de elementos diferentes entre as matrizes

void calculaAfinidade (Candidato *vet, int pop); // calcula a afinidade de uma celula (solução) com outra

double entropiaTotal (int **candidata, int **misturas, int n, int k, int t); // calculo da entropia da matriz candidata a partir das nossas misturas. Usando a funcao que calcula as probabilidades da matriz e sua entropia (ME PARECE REDUNTANTE. ACHO QUE DA PARA TIRAR ELA DAQUI)

void calculaFit (Candidato *vet, int **misturas, int pop, int amostras); // calculo do fitness de cada solucao candidata a patir da parametrização da sua entropia

int selecionaPivo(double fit0, double fitn2, double fitn, int pop);//seleciona o Pivo para o algoritmo de quicksort

void ordenaEntropia (Candidato *vet, int pop, int inicial); //ordena entropia usando quicksort

void ordenaFit (Candidato *vet, int pop, int inicial); //ordena o fitness usando quick sort

void atualizaConcentracao (Candidato *vet, int tamanho); // atualiza a concentraçao das celulas

double betat (double i, double f, int iteracao, double tmax); //betat é um coeficiente para determinar a frequencia da busca local

void clonaMutaSelecionaNet (int **misturas, int *tamanho, Candidato *vet, float beta, int amostras); //etapas de mutacao, clonagem e seleção

void elimina (Candidato *vet, int *tamanho); //elimina as solucoes ruins

void comparaSol (Candidato *vet, int **resp, int k, FILE *fp, int *contador); //comparacao das solucoes e print em txt

void comparaSolConsole (Candidato *vet, int **resp, int k, int *contador); //compara as solucoes, e imprime no console

void buscaLocal (Candidato *vet, int **misturas, int pop, int amostras); //busca local para tentar melhorar as solucoes
