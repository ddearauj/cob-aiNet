//
//  Alloc.c
//  Cobi
//
//  Created by Daniel Pereira on 1/5/16.
//  Copyright (c) 2016 Akangatu. All rights reserved.
//

#include "Alloc.h"

// ----- Matrix and Array: allocation and free methods

int **alocaMatrizInt (int **mat, int linha, int coluna) {
    mat = (int **)malloc(linha*sizeof(int *));
    for (int i = 0; i < linha; i++)
        mat[i]=(int *)malloc(coluna*sizeof(int));
    return mat;
}

int **liberaMatrizInt(int **mat, int linha, int coluna){
    for (int i = 0; i < linha; i++) {
        free(mat[i]);
    }
    free(mat);
    return NULL;
}


float **alocaMatrizFloat (float **mat, int linha, int coluna) {
    mat = (float **)malloc(linha*sizeof(float *));
    for (int i = 0; i < linha; i++)
        mat[i]=(float *)malloc(coluna*sizeof(float));
    return mat;
}

float **liberaMatrizFloat(float **mat, int linha, int coluna){
    for (int i = 0; i < linha; i++) {
        free(mat[i]);
    }
    free(mat);
    return NULL;
}

double **liberaMatrizDouble(double **mat, int linha, int coluna){
    for (int i = 0; i < linha; i++) {
        free(mat[i]);
    }
    free(mat);
    return NULL;
}


float *alocaVetorFloat (float *vet, int tamanho) {
    vet = (float *)malloc(tamanho * sizeof(float));
    return vet;
}

int *alocaVetorInt (int *vet, int tamanho) {
    vet = (int *)malloc(tamanho * sizeof(int));
    return vet;
}
