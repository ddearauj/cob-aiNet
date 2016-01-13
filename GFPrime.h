//
//  GFPrime.h
//  Cobi
//
//  Created by Daniel Pereira on 1/5/16.
//  Copyright (c) 2016 Akangatu. All rights reserved.
//

#ifndef __Cobi__GFPrime__
#define __Cobi__GFPrime__

#include <stdio.h>
#include "Alloc.h"

// ---  Operações básicas em corpos finitos de ordem prima --- //

int somaGFPrimo (int n, int a, int b);

int subtraiGFPrimo (int n, int a, int b);

int multiplicaGFPrimo (int n, int a, int b);

int divideGFPrimo (int n, int a, int b);

// --- Checar determinantes de matrizes em GF --- //

int checkDeterminante2x2 (int **mat, int n);

int checkDeterminante3x3 (int **mat, int n);

int CheckDeterminante4x4(int **mat,int n);

// --- Multiplicar matrizes em campos finitos --- //

void multiplicaMatrizABFinito (int **A, int **B, int **C, int linhaA, int colunaA, int colunaB, int n);
// multiplicação A*B e joga o valor na matriz C



#endif /* defined(__Cobi__GFPrime__) */
