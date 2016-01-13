//
//  GFPrime.c
//  Cobi
//
//  Created by Daniel Pereira on 1/5/16.
//  Copyright (c) 2016 Akangatu. All rights reserved.
//

#include "GFPrime.h"


// --- Basic GFields of prime order perations

int somaGFPrimo (int n, int a, int b) {
    return (a+b)%n;
}

int subtraiGFPrimo (int n, int a, int b) {
    if (a - b < 0)
        return n + (a - b);
    else
        return (a-b)%n;
}

int multiplicaGFPrimo (int n, int a, int b) {
    return (a*b)%n;
}

int divideGFPrimo (int n, int a, int b) {
    return (a/b)%n;
}

// Determinant of the matrix

int checkDeterminante2x2 (int **mat, int n) { //retorna o valor do determinante num corpo finito de ordem n
    int a = multiplicaGFPrimo(n, mat[0][0], mat[1][1]);
    int b = multiplicaGFPrimo(n, mat[0][1], mat[1][0]);
    a = subtraiGFPrimo(n, a, b);
    
    return a;
    
}

int checkDeterminante3x3 (int **mat, int n){ //retorna o valor do determinante num corpo finito de ordem n
    int a,b,c,d,e,f;
    
    a = multiplicaGFPrimo(n, mat[0][0], mat[1][1]);
    a = multiplicaGFPrimo(n, a, mat[2][2]);
    
    b = multiplicaGFPrimo(n, mat[0][1], mat[1][2]);
    b = multiplicaGFPrimo(n, b, mat[2][0]);
    
    c = multiplicaGFPrimo(n, mat[0][2], mat[1][0]);
    c = multiplicaGFPrimo(n, c, mat[2][1]);
    
    d = multiplicaGFPrimo(n, mat[0][2], mat[1][1]);
    d = multiplicaGFPrimo(n, d, mat[2][0]);
    
    e = multiplicaGFPrimo(n, mat[0][0], mat[1][2]);
    e = multiplicaGFPrimo(n, e, mat[2][1]);
    
    f = multiplicaGFPrimo(n, mat[0][1], mat[1][0]);
    f = multiplicaGFPrimo(n, f, mat[2][2]);
    
    
    a = somaGFPrimo(n, a, b);
    a = somaGFPrimo(n, a, c);
    
    e = somaGFPrimo(n, e, f);
    e = somaGFPrimo(n, e, d);
    
    return subtraiGFPrimo(n, a, e);
}

int CheckDeterminante4x4(int **mat,int n) {
    
    int **aux = NULL; // colocar a matriz de cofatores (acho que eses é o nome) em aux
    aux = alocaMatrizInt(aux, 3, 3);
    
    int det = 0; // soma total
    
    for (int i = 0; i < 4; i++) { // passar por todas as matrizes de cofatores ou adjunta
        //criação da matriz aux:
        int k = 0;
        int checkColuna = 0;
        while (k < 3) { // preencher 3 colunas da matriz
            if (checkColuna != i) { //só usar colunas que não sejam iguais a i e começando sempre da linha 1 (já que usameremos sempre a linha como 0 como parametro para criar a matriz de cofatores)
                for (int linha = 0; linha < 3; linha++) {
                    aux[linha][k] = mat[linha+1][checkColuna];
                }
                k++;
            }
            checkColuna++;
        }
        //fim da criação da matriz aux
        
        if (i % 2 == 0) {
            det = somaGFPrimo(n, det, multiplicaGFPrimo(n, mat[0][i], checkDeterminante3x3(aux, n)));
        }
        else {
            det = subtraiGFPrimo(n, det, multiplicaGFPrimo(n, mat[0][i], checkDeterminante3x3(aux, n)));
        }
        
    }
    
    liberaMatrizInt(aux, 3, 3);
    return det;
}

// Multiplicatoin of 2 GF matrixes
void multiplicaMatrizABFinito (int **A, int **B, int **C, int linhaA, int colunaA, int colunaB, int n){
    for (int i = 0; i < linhaA ; i ++) {
        for (int j = 0; j < colunaB; j++) {
            int sum = 0;
            int aux = 0;
            
            for (int h = 0; h < colunaA; h++) {
                aux = multiplicaGFPrimo(n, A[i][h], B[h][j]);
                sum = somaGFPrimo(n, sum, aux);
            }
            C[i][j] = sum;
        }
    }
}
