//
//  Alloc.h
//  Cobi
//
//  Created by Daniel Pereira on 1/5/16.
//  Copyright (c) 2016 Akangatu. All rights reserved.
//

#ifndef __Cobi__Alloc__
#define __Cobi__Alloc__

#include <stdio.h>
#include <stdlib.h>

int **alocaMatrizInt (int **mat, int linha, int coluna);

int **liberaMatrizInt(int **mat, int linha, int coluna);

float **alocaMatrizFloat (float **mat, int linha, int coluna);

float **liberaMatrizFloat(float **mat, int linha, int coluna);

double **liberaMatrizDouble(double **mat, int linha, int coluna);

float *alocaVetorFloat (float *vet, int tamanho);

int *alocaVetorInt (int *vet, int tamanho);

#endif /* defined(__Cobi__Alloc__) */
