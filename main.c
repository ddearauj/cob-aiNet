//
//  main.c
//  Sim
//
//  Created by Daniel Pereira on 3/8/14.
//  Copyright (c) 2014 Daniel Pereira. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cob.h"
#include <gsl/gsl_rng.h>
#include <time.h>


int main() {
    
    // Initialize the variables used for the normal distribuition
    // Initialize the seed for the random numbers
    srand(time(NULL));
    
    const gsl_rng_type * T;
    gsl_rng * r;
    
    gsl_rng_env_setup();
    
    T = gsl_rng_default;
    r = gsl_rng_alloc (T);
    gsl_rng_set (r, (int)time(NULL));
    
    // probabilities --> Used to define what are the numbers to be generated on the matrix
    int prob2[4][2] = {{20, 80}, {70,30}, {90, 10}, {40, 60}}; // For the order 2 example, those are the probabilities up to three4 sources
    
    // variables used during the simulation
    int amostrasInicial = 32; // initial value. Always a power of 2
    int amostras = amostrasInicial;
    
    // variable declaration
    int iteracoes;
    int iteracoesMax = 300;
    int tamanhopop = POPINICIAL;
    int ibeta = 0;
    int separacoes = 0;
    
    // matrix pointers declaration
    int **fontes = NULL;
    int **obs = NULL;
    int **mistura = NULL;
    int **aux = NULL;
    int **prob = NULL;
    Candidato *matSepara = NULL;
    
    
    // leitura do txt contendo as amostras das fontes. Log vai tudo e produtoAW saem os produtos
    FILE *log;
    FILE *resultados;
    // FILE *amostrastxt; --> used for the 3 sources problem, was mostly for debbuging purposes
    
    log = fopen("filepath", "w");
    resultados = fopen("filepath", "w");
    
    if (log == NULL) { //erro na abertura do arquivo
        perror("Erro ao abrir o arquivo.\n");
        return 1;
    }
    prob = alocaMatrizInt(prob, K, K);
    
    
    // Processo de definição de quais probabilidades serão usadas já que elas dependem da ordem do campo
    if (ORDEM == 2) {
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < ORDEM; j++) {
                prob[i][j] = prob2[i][j];
            }
        }
    }
    
    /*
     *  
     *  As the idea of the simulation is to test the influence of factors such as # of iterations
     *  and the initial sample size (also, other variables listed in cob.h)
     *  The simulation will run tests of 300, 500 and 700 iterations with sample sizes from
     *  2^5 até 2^10
     *
     */
    
    for(; iteracoesMax < MAXIT; iteracoesMax = iteracoesMax + 200) {
        
        //allocation of the matrixes that don't depend on the sample size
        
        mistura = alocaMatrizInt(mistura, K, K);
        aux = alocaMatrizInt(aux, K, K);
        
        matSepara = (Candidato *)malloc(POPMAX*sizeof(Candidato));
        
        for (int i = 0; i < POPMAX; i++) {
            matSepara[i].mat = (int **)malloc(K*sizeof(int *));
            for (int j = 0; j < K; j++)
                matSepara[i].mat[j]=(int *)malloc(K*sizeof(int));
        }
        
        fprintf(log, "\n\n\nMUDANÇA DE ITERAÇÕES PARA %d !!!\n\n\n", iteracoesMax);
        fprintf(resultados, "\n\n\nMUDANÇA DE ITERAÇÕES PARA %d !!!\n\n\n", iteracoesMax);
        
        amostras = amostrasInicial;
        
        
        for(; amostras <= AMOSTRAS; amostras = amostras * 2) {
            
            // allocation
            fontes = alocaMatrizInt(fontes, K, amostras);
            obs = alocaMatrizInt(obs, K, amostras);
            separacoes = 0;
            
            fprintf(log, "\n\n\nMUDANÇA DE AMOSTRAS PARA %d !!!\n\n\n", amostras);
            
            
            // 30 tests will be conducted
            for (int t = 0; t < 30; t ++) {
                tamanhopop = POPINICIAL;
                
                fprintf(log, "TESTE NUMERO %d\n\n\n", t);
                
                // --- source generation
                geraFontes (fontes, prob, K, amostras, ORDEM, r);
                
                // --- mixture matrix generation
                geraMatrizInversivel(mistura);
                
                // --- observations (mixture*sources) = observations
                multiplicaMatrizABFinito(mistura, fontes, obs, K, K, amostras, ORDEM);
                
                
                // Start of the cob-aiNet
                
                // initial subjects
                for (int i = 0; i < POPINICIAL; i ++) {
                    geraMatrizInversivel(aux);
                    copiaMatrizAparaB(aux, matSepara[i].mat, K, K);
                }
                
                for (int i = 0; i < POPINICIAL; i++) {
                    matSepara[i].concentracao = C0;
                }
                
                calculaFit(matSepara, obs, tamanhopop, amostras);
                calculaAfinidade(matSepara, tamanhopop);
                
                for (iteracoes = 0; iteracoes < iteracoesMax && tamanhopop > 1; iteracoes++) {
                    clonaMutaSelecionaNet(obs, &tamanhopop, matSepara, betat(BETAI, BETAF, ibeta, MAXIT), amostras);
                    calculaFit(matSepara, obs, tamanhopop, amostras);
                    calculaAfinidade(matSepara, tamanhopop);
                    atualizaConcentracao(matSepara, tamanhopop);
                    elimina(matSepara, &tamanhopop);
                    calculaAfinidade(matSepara, tamanhopop);
                    fprintf(log, "%d, %d ind., %f de conc.\n", iteracoes,tamanhopop,matSepara[0].concentracao);
                    if (iteracoes % 20 == 0 && iteracoes != 0) {
                        ibeta++;
                    }
                    buscaLocal(matSepara, obs, tamanhopop, amostras);
                    calculaFit(matSepara, obs, tamanhopop, amostras);
                    calculaAfinidade(matSepara, tamanhopop);
                    atualizaConcentracao(matSepara, tamanhopop);
                    
                }
                
                elimina(matSepara, &tamanhopop);
                
                
              fprintf(log, "Matriz de Mistura:\n");
                for (int i = 0; i < K; i++) {
                    for (int j = 0; j < K; j++) {
                        fprintf(log, "%d ", mistura[i][j]);
                    }
                    fprintf(log, "\n");
                }
              
                
                //prints on cosole if you do not want to print to a file
                //comparaSolConsole(matSepara, mistura, K, &separacoes);
                
                //prints on file
                comparaSol(matSepara, mistura, K, resultados, &separacoes);
                //fclose(amostrastxt);
            }
            
            
            fprintf(log, "\n\nNUMERO DE SEPARAÇÕES\n\n:%d", separacoes);
            fprintf(resultados, "\n\nAMOSTRAS: %d; NUMERO DE SEPARAÇÕES\n\n:%d", amostras, separacoes);
            printf("\n\nAMOSTRAS: %d; NUMERO DE SEPARAÇÕES\n\n:%d", amostras, separacoes);

            
            
            liberaMatrizInt(fontes, K, amostras);
            liberaMatrizInt(obs, K, amostras);
        }
        
        liberaMatrizInt(mistura, K, K);
        liberaMatrizInt(aux, K, K);
        for (int i = 0; i < POPMAX; i++) {
            for (int j = 0; j < K; j++) {
                free(matSepara[i].mat[j]);
            }
            free(matSepara[i].mat);
        }
        
        free(matSepara);
        
    }
    
    liberaMatrizInt(prob, K, K);
    
    fclose(log);
    fclose(resultados);
    
    return 0;
    
}
