//
//  cob.c
//  Cobi
//
//  Created by Daniel Pereira on 1/5/16.
//  Copyright (c) 2016 Akangatu. All rights reserved.
//

#include "cob.h"

// --- Not directly tied to the cob-aiNet algorithm but still necessary somehow

int aleatorio_int (int limite) { // generates a random number from 0 to "limite"
    int random1 = rand() % limite;
    return random1;
}

void copiaMatrizAparaB (int **A, int **B, int linha, int coluna) { //copies the values from matrix A to B
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            B[i][j] = A[i][j];
        }
    }
}

void copiaCandidatoAparaB(Candidato A, Candidato B, int linha, int coluna) { //copies all the values from a Candidato type variable to another
    copiaMatrizAparaB(A.mat, B.mat, linha, coluna);
    B.afi = A.afi;
    B.concentracao = A.concentracao;
    B.fit = A.fit;
}

void abreArquivos (int t, int amostras, int **fontes) { //file openers of the samples
    FILE *fp;
    
    switch (amostras) {
        case 128:
            switch (t) {
                case 0:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_128_amostras_t1.txt", "r");
                    break;
                    
                case 1:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_128_amostras_t2.txt", "r");
                    break;
                    
                case 2:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_128_amostras_t3.txt", "r");
                    break;
                    
                case 3:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_128_amostras_t4.txt", "r");
                    break;
                    
                case 4:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_128_amostras_t5.txt", "r");
                    break;
                    
                case 5:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_128_amostras_t6.txt", "r");
                    break;
                    
                case 6:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_128_amostras_t7.txt", "r");
                    break;
                    
                case 7:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_128_amostras_t8.txt", "r");
                    break;
                    
                case 8:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_128_amostras_t9.txt", "r");
                    break;
                    
                case 9:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_128_amostras_t10.txt", "r");
                    break;
                    
            }
            break;
        case 256:
            switch (t) {
                case 0:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_256_amostras_t1.txt", "r");
                    break;
                    
                case 1:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_256_amostras_t2.txt", "r");
                    break;
                    
                case 2:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_256_amostras_t3.txt", "r");
                    break;
                    
                case 3:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_256_amostras_t4.txt", "r");
                    break;
                    
                case 4:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_256_amostras_t5.txt", "r");
                    break;
                    
                case 5:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_256_amostras_t6.txt", "r");
                    break;
                    
                case 6:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_256_amostras_t7.txt", "r");
                    break;
                    
                case 7:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_256_amostras_t8.txt", "r");
                    break;
                    
                case 8:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_256_amostras_t9.txt", "r");
                    break;
                    
                case 9:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_256_amostras_t10.txt", "r");
                    break;
                    
            }
            break;
        case 512:
            switch (t) {
                case 0:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_512_amostras_t1.txt", "r");
                    break;
                    
                case 1:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_512_amostras_t2.txt", "r");
                    break;
                    
                case 2:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_512_amostras_t3.txt", "r");
                    break;
                    
                case 3:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_512_amostras_t4.txt", "r");
                    break;
                    
                case 4:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_512_amostras_t5.txt", "r");
                    break;
                    
                case 5:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_512_amostras_t6.txt", "r");
                    break;
                    
                case 6:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_512_amostras_t7.txt", "r");
                    break;
                    
                case 7:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_512_amostras_t8.txt", "r");
                    break;
                    
                case 8:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_512_amostras_t9.txt", "r");
                    break;
                    
                case 9:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_512_amostras_t10.txt", "r");
                    break;
            }
            break;
        case 1024:
            switch (t) {
                case 0:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_1024_amostras_t1.txt", "r");
                    break;
                    
                case 1:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_1024_amostras_t2.txt", "r");
                    break;
                    
                case 2:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_1024_amostras_t3.txt", "r");
                    break;
                    
                case 3:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_1024_amostras_t4.txt", "r");
                    break;
                    
                case 4:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_1024_amostras_t5.txt", "r");
                    break;
                    
                case 5:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_1024_amostras_t6.txt", "r");
                    break;
                    
                case 6:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_1024_amostras_t7.txt", "r");
                    break;
                    
                case 7:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_1024_amostras_t8.txt", "r");
                    break;
                    
                case 8:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_1024_amostras_t9.txt", "r");
                    break;
                    
                case 9:
                    fp = fopen("/Users/dpereira14/Programação/IC/cob-aiNet_tests/3fontes/3_fontes_1024_amostras_t10.txt", "r");
                    break;
            }
            break;
    }
    int d;
    int i = 0;
    int j = 0;
    while (fscanf(fp, "%d", &d) != EOF) {
        
        
        if (j < amostras) {
            fontes[i][j] = d;
            j++;
        }
        else {
            i++;
            j = 0;
            fontes[i][j] = d;
            j++;
            
        }
        
        if (i > 2) {
            break;
        }
        
        
    }
    
    fclose(fp);
}

// ---- ---- ---- ----- ---- ---- ---- ---- //


// --- Simulation Methods and Funcitons --- //

void geraFontes (int **fontes, int **prob, int linha, int coluna, int ordem, const gsl_rng * r) {
    //generates the signal sources
    //fontes is the source matrix
    //prob is the probability matrix
    //ordem is the GField order
    double random;
    int psum = 0;
    int psum1 = 0;
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            random = uniformeRandom(r); // it is important that the sources have a uniform distribuiton
            random = random * 100;
            psum = 0;
            for (int h = 0; h < ordem; h++) { // this function makes sure that the values of the source follows the percentage distribuiton that is stabilished in the simulation. For that, we divide the interval for each number.
                
                //take an order 3 GField for instance and we want 0 to have a 50% probability, 1 30% and 2 20% so if the random number generated is between 0-50, we assign the value of 0, if it is between 50-80: 1 and 80-100: 2
                psum1 = psum;
                psum += prob[i][h];
                if (random <= psum && random > psum1) {
                    fontes[i][j] = h;
                }
            }
        }
    }
}

void geraMatrizInversivel (int **mistura) { //it generates an Inversible matrix that will be used to mix the signals (by making sure the determinant is not 0
    int i,j;
    for (i = 0; i < K; i ++) {
        for (j = 0; j < K; j++) {
            mistura[i][j] = aleatorio_int(ORDEM);
        }
    }
    
    if (K == 2) {
        while (checkDeterminante2x2(mistura, ORDEM) == 0) {
            mistura[aleatorio_int(K)][aleatorio_int(K)] = aleatorio_int(ORDEM);
        }
    }
    
    if (K == 3) {
        while (checkDeterminante3x3(mistura, ORDEM) == 0) {
            mistura[aleatorio_int(K)][aleatorio_int(K)] = aleatorio_int(ORDEM);
        }
    }
    
    if (K == 4) {
        while (CheckDeterminante4x4(mistura, ORDEM) == 0) {
            mistura[aleatorio_int(K)][aleatorio_int(K)] = aleatorio_int(ORDEM);
        }
    }
}

void probabilidadeParaEntropia (double **prob, int **mat, int linha, int coluna) { //this it the probability matrix used to calculate the Entropy of the signal.
    // mat = candidateSolution*Mixture
    int sum = 0;
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            sum += mat[i][j];
        }
        prob[i][1] = (double) sum / (coluna);
        prob[i][0] = 1.0 - prob[i][1];
        sum = 0;
    }
}

// entropy calculation
double entropia (double **prob, int n, int k) {
    double entropy = 0.0;
    double escala = log(n);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            if (prob[i][j] >= ZERO)
                entropy += (prob[i][j]*log(prob[i][j]));
        }
    }
    return -1.0*entropy/escala;
}


// this is the distance between the solutions in order to calculate the affinity of the solutions. As the Cartesian distance is not the best way to measure it, we count the different ij values between candidate solutions
double distanciaR (int **mat1, int **mat2, int linha, int coluna) {
    int diferente = 0; // different ij values betwwen matrixes
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            if (mat1[i][j] != mat2[i][j]) {
                diferente+= 1;
            }
        }
    }
    
    return  (double)diferente / (linha*coluna);
}


// calculate the affinity of the population
void calculaAfinidade (Candidato *vet, int pop) {
    int i, j;
    double aff[POPMAX][POPMAX];
    double somaconcentracao = 0;
    
    //this creates the matrix that evaluates the affinitity between cells
    for (i = 0; i < pop; i++) {
        for (j = i ; j < pop; j++) {
            aff[i][j] = distanciaR(vet[i].mat, vet[j].mat, K, K);
        }
    }
    
    // the affinity of the ith-cell to the jth-cell is the same
    for (j = 0; j < pop; j++) {
        for (i = j; i < pop; i++) {
            aff[i][j] = aff[j][i];
        }
    }
    
    // if the cells fall in the same supression radius, then we calculate the affinity between cells otherwise, set it to 0
    for (i = 0; i < pop; i++) {
        for (j = 0; j < pop; j++) {
            if (aff[i][j] <= RAIOSUP && i != j) {
                aff[i][j] = vet[j].concentracao * (RAIOSUP - aff[i][j]);
            }
            else
                aff[i][j] = 0;
        }
    }
    
    // now compute the afinity value for each solution
    for (i = 0; i < pop; i++) {
        vet[i].afi = 0;
        somaconcentracao = 0;
        for (j = 0; j < pop; j++) {
            if (vet[j].fit >= vet[i].fit && i!=j) {
                vet[i].afi += aff[i][j];
                somaconcentracao += vet[j].concentracao;
            }
        }
        if (somaconcentracao > 0) {
            vet[i].afi = vet[i].afi/somaconcentracao;
        }
        else // --> the J space is null therefore the afinity is 0
            vet[i].afi = 0;
    }
}

// n is the field order, k is the number of sources and t is the number of samples
double entropiaTotal (int **candidata, int **misturas, int n, int k, int t) {
    double resposta;
    // --- allocation
    double **prob = NULL;
    prob = (double **)malloc(k*sizeof(double*));
    for (int i = 0; i < k; i++)
        prob[i]= (double *)malloc(n*sizeof(double));
    
    int **matriz = NULL;
    
    matriz = (int **)malloc(k*sizeof(int *));
    for (int i = 0; i < k; i++)
        matriz[i]=(int *)malloc(t*sizeof(int));
    // --- end of allocatoin
    
    // multiply candidates and mixes matrixes
    multiplicaMatrizABFinito(candidata, misturas, matriz, k, k, t, n);
    
    // get the probabilities to calculate the entropy
    probabilidadeParaEntropia(prob, matriz, k, t);
    
    // get the entropy value
    resposta = entropia(prob, n, k);
    
    // free the matrixes
    matriz = liberaMatrizInt(matriz, k, t);
    prob = liberaMatrizDouble(prob, k, n);
    
    return resposta;
    
}


// calculate the fitness of each solution based on the entropy
void calculaFit (Candidato *vet, int **misturas, int pop, int amostras) {
    
    for (int i = 0; i < pop; i++) {
        vet[i].fit =  entropiaTotal(vet[i].mat, misturas, ORDEM, K, amostras);
    }
    ordenaEntropia(vet, pop, 0);
    
    for (int i = 0; i < pop; i++) {
        if (vet[0].fit == vet[pop - 1].fit) {
            vet[i].fit = .5;
        }
        else // tries to "parametrizar" the fitness value
            vet[i].fit = 1 - (vet[i].fit - vet[0].fit) / (- vet[0].fit + vet[pop - 1].fit);
    }
    if (pop == 1) vet[0].fit = 1;
}

// returns the index of the pivot for the quicksort. fit0 is the value of the first value on the list, n2 is the middle one, and fitn is the last one. pop is the size of the list
int selecionaPivo(double fit0, double fitn2, double fitn, int pop) {
    if (fit0 > fitn2 && fit0 > fitn) {
        if (fitn2 > fitn) {
            return (pop - 1)/2;
        }
        else{
            return pop - 1;
        }
    }
    else {
        if (fitn > fitn2 && fitn > fit0) {
            if (fit0 > fitn2) {
                return 0;
            }
            else {
                return (pop - 1)/2;
            }
        }
        else{
            if (fit0 > fitn) {
                return 0;
            }
            else {
                return pop - 1;
            }
        }
    }
}


//sorts the entropies from lowest to highest using quicksort. inicial is always zero when calling the method
void ordenaEntropia (Candidato *vet, int pop, int inicial) {
    Candidato aux;
    aux.mat = (int **)malloc(K*sizeof(int *));
    for (int j = 0; j < K; j++)
        aux.mat[j]=(int *)malloc(K*sizeof(int));
    
    // stop conditions
    if ((pop - inicial - 1) < 2) {
        if ((pop - inicial - 1) == 1) {
            if (vet[inicial].fit > vet[pop - 1].fit) {
                copiaCandidatoAparaB(vet[inicial], aux, K, K);
                copiaCandidatoAparaB(vet[pop-1], vet[inicial], K, K);
                copiaCandidatoAparaB(aux, vet[pop-1], K, K);
            }
        }
    }
    
    else {
        // In this case, the fit value has not yet been ajusted, therefore the value it holds is the entropy of the candidate solution
        
        // chose the pivot --> median between [0], [n/2] e [n-1]
        int pivo = selecionaPivo(vet[0].fit, vet[(pop-1)/2].fit, vet[pop-1].fit, pop);
        
        // now, switch the value of the pivot with the last element of the array
        
        copiaCandidatoAparaB(vet[pivo], aux, K, K);
        copiaCandidatoAparaB(vet[pop-1], vet[pivo], K, K);
        copiaCandidatoAparaB(aux, vet[pop-1], K, K);
        
        //initiate the partition
        int i = inicial;
        int j = pop - 2;
        double chave = vet[pop-1].fit; // entropy value that the pivot holds
        
        while (j >= i) {
            while (vet[i].fit < chave) {
                i++;
            }
            while (vet[j].fit > chave) {
                j--;
            }
            if (j>=i) {
                //switch
                copiaCandidatoAparaB(vet[i], aux, K, K);
                copiaCandidatoAparaB(vet[j], vet[i], K, K);
                copiaCandidatoAparaB(aux, vet[j], K, K);
                i++;
                j--;
            }
        }
        //switch
        copiaCandidatoAparaB(vet[i], aux, K, K);
        copiaCandidatoAparaB(vet[pop-1], vet[i], K, K);
        copiaCandidatoAparaB(aux, vet[pop-1], K, K);
        
        //start again!
        ordenaEntropia(vet, inicial, i-1);
        ordenaEntropia(vet, i+1, pop-1);
    }
    for (int i = 0; i < K; i++)
        free(aux.mat[i]);
    free(aux.mat);
    
}

//samething as the previous method but for fitness. Now it will be ordered from highest to lowest value
void ordenaFit (Candidato *vet, int pop, int inicial) {
    
    //deixa os com maiores indices nos menores indices
    //utilizando o Quicksort, inicial sempre será zero, menos na recurssão dentro da função,

    
    //deixa os com maiores fit nos menores indices
    Candidato aux;
    aux.mat = (int **)malloc(K*sizeof(int *));
    for (int j = 0; j < K; j++)
        aux.mat[j]=(int *)malloc(K*sizeof(int));
    
    
    if ((pop - inicial - 1) < 2) {
        if ((pop - inicial - 1) == 1) {
            if (vet[inicial].fit < vet[pop - 1].fit) {
                copiaCandidatoAparaB(vet[inicial], aux, K, K);
                copiaCandidatoAparaB(vet[pop-1], vet[inicial], K, K);
                copiaCandidatoAparaB(aux, vet[pop-1], K, K);
            }
        }
    }
    
    else {
        
        //Escolha do pivô --> mediana entre [0], [n/2] e [n-1]
        int pivo = selecionaPivo(vet[0].fit, vet[(pop-1)/2].fit, vet[pop-1].fit, pop);
        
        //agora, trocar o pivô com o ultimo elemento do vetor
        
        copiaCandidatoAparaB(vet[pivo], aux, K, K);
        copiaCandidatoAparaB(vet[pop-1], vet[pivo], K, K);
        copiaCandidatoAparaB(aux, vet[pop-1], K, K);
        
        //iniciar partição
        int i = inicial;
        int j = pop - 2;
        double chave = vet[pop-1].fit; // valor do pivo usado na ordenação
        
        while (j >= i) {
            while (vet[i].fit > chave) {
                i++;
            }
            while (vet[j].fit < chave) {
                j--;
            }
            if (j>=i) {
                //troca!
                copiaCandidatoAparaB(vet[i], aux, K, K);
                copiaCandidatoAparaB(vet[j], vet[i], K, K);
                copiaCandidatoAparaB(aux, vet[j], K, K);
                i++;
                j--;
            }
        }
        //troca!
        copiaCandidatoAparaB(vet[i], aux, K, K);
        copiaCandidatoAparaB(vet[pop-1], vet[i], K, K);
        copiaCandidatoAparaB(aux, vet[pop-1], K, K);
        
        //mais uma vez!
        ordenaEntropia(vet, inicial, i-1);
        ordenaEntropia(vet, i+1, pop-1);
    }
    for (int i = 0; i < K; i++)
        free(aux.mat[i]);
    free(aux.mat);
}


// updates the concentration of the cells
void atualizaConcentracao (Candidato *vet, int tamanho) {
    double alfa = 0;
    
    if(vet[0].afi > vet[0].concentracao || vet[0].concentracao < ZERO){
        printf("teste");
    }
    
    for (int i = 0; i < tamanho; i++) {
        if (vet[i].afi <= ZERO) {
            alfa = 1 + 0.1*vet[i].fit;
        }
        else
            alfa = 0.7;
        vet[i].concentracao = vet[i].concentracao*(alfa) - vet[i].afi;
        if (vet[i].concentracao > 1)
            vet[i].concentracao = 1;
        if (vet[i].concentracao < 0) {
            vet[i].concentracao = 0;
        }
    }
}

//this beta dictates the frequency of the local search
double betat (double i, double f, int iteracao, double tmax) {
    return (i - f)/(1 + exp((20/tmax)*(iteracao - tmax/2))) + f;
}


//mutates the cell by selecting two random cells and adding them together to form a mutated cell
void muta (int **Clone) {
    int randLinha1 = aleatorio_int(K);
    int randLinha2 = aleatorio_int(K);
    
    while (randLinha2 == randLinha1) {
        randLinha1 = aleatorio_int(K);
    }
    
    for (int j = 0; j < K; j++) {
        Clone[randLinha1][j] = somaGFPrimo(ORDEM, Clone[randLinha1][j], Clone[randLinha2][j]);
    }
}


// Clones, mutates and Select (Can I modulate more?)
void clonaMutaSelecionaNet (int **misturas, int *tamanho, Candidato *vet, float beta, int amostras) {
    
    int nclones = 0; //# of clones, initially is zero
    int parada = 0;
    int tamanhofix = *tamanho;
    int nmutacoes = 0;
    int maxPossiveisClones = *tamanho;
    int contadorDePossiveisClones = 0;
    CloneCandidato *possiveisClones1; ///list of the possible clones that will be inserted
    int contadorClone = 0; //counts from which clone the cell was generated
    int jaTemClonePossivel = 0;
    
    // allocation
    possiveisClones1 = (CloneCandidato *)malloc(maxPossiveisClones*sizeof(CloneCandidato));
    
    for (int i = 0; i < maxPossiveisClones; i++) {
        possiveisClones1[i].mat = (int **)malloc(K*sizeof(int *));
        for (int j = 0; j < K; j++)
            possiveisClones1[i].mat[j]=(int *)malloc(K*sizeof(int));
    }
    
    int **Clone = NULL;
    int **possivelClone = NULL;
    
    possivelClone = alocaMatrizInt(possivelClone, K, K);
    Clone = alocaMatrizInt(Clone, K, K);
    
    // end of allocation
    
    
    // do the following for every solution
    for (int n = 0 ; n < tamanhofix; n++) {
        nclones = vet[n].concentracao*(CLONESMAX - CLONESMIN) + CLONESMIN;
        jaTemClonePossivel = 0;
        for (contadorClone = 0; contadorClone < nclones; contadorClone++) {
            // generate nc clones
            // mutate the clones
            
            //1st step: copy
            for (int j = 0; j < K; j++) {
                for (int h = 0; h < K; h++) {
                    Clone[j][h] = vet[n].mat[j][h];
                }
            }
            
            // 2nd step: draft the position of the mutation then alter the matrix
            // calculate how many mutations will be made for every cadidate solution based on the equation:
            // nmutações = max between b(t)* exp(-fit*concentracao) and 1;
            // b(t) is a sigmoidal curve for the expression of
            // betat (betai - betaf)/(1 + expf((20/tmax)*(iteracao - tmax/2))) + betaf;
            
            nmutacoes = beta* exp(((-1)*(vet[n].fit))*vet[n].concentracao);
            if (nmutacoes < 1)
                nmutacoes = 1;
            
            parada = 0;
            do {
                muta(Clone);
                parada++;
            } while (parada < nmutacoes); // mutate util the number defined before
            
            if (entropiaTotal(Clone, misturas, ORDEM, K, amostras) < entropiaTotal(vet[n].mat, misturas, ORDEM, K, amostras)) { //if the entropy of clone is less than the father's
                if (distanciaR(Clone, vet[n].mat, K, K) > RAIOSUP) { //if distance between clone and father is larger than the supression radious
                    if (jaTemClonePossivel == 0) { // if there is no possible clone yet?
                        copiaMatrizAparaB(Clone, possivelClone, K, K);
                        jaTemClonePossivel = 1;
                    }
                    else { // if there is, pick the best clone
                        if (entropiaTotal(Clone, misturas, ORDEM, K, amostras) < entropiaTotal (possivelClone, misturas, ORDEM, K, amostras)) {
                            copiaMatrizAparaB(Clone, possivelClone, K, K);
                        }
                    }
                }
                else { // if inside the supression radious, the clone takes the place of the father and has the concentration set to the initial value of the simulation
                    copiaMatrizAparaB(Clone, vet[n].mat, K, K);
                    vet[n].concentracao = C0;
                }
            }
        }
        
        // if a possible clone was actually found
        if (jaTemClonePossivel == 1) { //add to the counter
            possiveisClones1[contadorDePossiveisClones].mat = possivelClone;
            copiaMatrizAparaB(possivelClone, possiveisClones1[contadorDePossiveisClones].mat, K, K);
            contadorDePossiveisClones++;
        }
    }
    
    
    // now check to see if the clone will be inserted in the population
    int seraIncerido;
    int contadorInceridos = 0;
    
    // check for every possible clone
    for (int i = 0; i < contadorDePossiveisClones; i++) {
        seraIncerido = 1;
        for (int k = 0; k < *tamanho; k++) {
            //if the possible clone is in the supression radious of a different already estabilished cell, then it will not be incerted (to maintain the variability of the population)
            if (distanciaR(possiveisClones1[i].mat, vet[k].mat, K, K) < RAIOSUP) {
                seraIncerido = 0;
            }
        }
        
        // if it will be incerted and the size of the population has not reach its limit
        if (seraIncerido == 1 && (*tamanho) < POPMAX) {
            copiaMatrizAparaB(possiveisClones1[i].mat, vet[tamanhofix + contadorInceridos].mat, K, K);
            vet[tamanhofix + contadorInceridos].concentracao = C0;
            contadorInceridos++;
            *tamanho += 1;
        }
    }
    
    // free the allocated matrixes
    liberaMatrizInt(Clone, K, K);
    liberaMatrizInt(possivelClone, K, K);
}

// eliminate candidate solutions from the pop
void elimina (Candidato *vet, int *tamanho) {
    int contEliminados = 0;
    for (int i = 0; i < *tamanho; i++) {
        if (vet[i].concentracao <= ZERO) {
            contEliminados++;
        }
    }
    
    if (*tamanho-contEliminados >= 1) {
        for (int i = 0; i < *tamanho; i++) {
            if (vet[i].concentracao <= ZERO) {
                vet[i].fit = -1;
            }
        }
        
        ordenaFit(vet, *tamanho-contEliminados,0);
        *tamanho -= contEliminados;
    }
}

// returns the order size if it separeted the sources completely
int checaSeparacao (int **w) {
    int soma = 0;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            soma += w[i][j];
        }
    }
    
    return soma;
}


void comparaSol (Candidato *vet, int **resp, int k, FILE *fp, int *contador) {//counts how many of the tests separeted all the sources, prints on file
    int **w = NULL;
    w = (int **)malloc(K*sizeof(int*));
    for (int i = 0; i < k; i++)
        w[i]= (int *)malloc(K*sizeof(int));
    
    multiplicaMatrizABFinito(vet[0].mat, resp, w, k, k, k, ORDEM);
    
    int check = checaSeparacao(w);
    
    fprintf(fp, "\n---------\nSOMA = %d\n\n", check);
    if (check == K) {
        *contador = *contador + 1;
    }
    
    fprintf(fp, "\n-----------\n");
    fprintf(fp, "Produto A*W:\n");
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            fprintf(fp, "%d ", w[i][j]);
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "\n-----------\n");
    
    for (int i = 0; i < K; i++) {
        free(w[i]);
    }
    free(w);
    
}

void comparaSolConsole (Candidato *vet, int **resp, int k, int *contador) { //counts how many of the tests separeted all the sources, prints on the console
    int **w = NULL;
    w = (int **)malloc(K*sizeof(int*));
    for (int i = 0; i < k; i++)
        w[i]= (int *)malloc(K*sizeof(int));
    
    multiplicaMatrizABFinito(vet[0].mat, resp, w, k, k, k, ORDEM);
    
    int check = checaSeparacao(w);
    
    printf("\n---------\nSOMA = %d\n\n", check);
    if (check == K) {
        *contador = *contador + 1;
    }
   
  // impressão
    printf("\n-----------\n");
    printf("Produto A*W:\n");
    for (int i = 0; i < k; i++) {
       for (int j = 0; j < k; j++) {
            printf("%d ", w[i][j]);
        }
        printf("\n");
    }
    printf("\n-----------\n");
    
    for (int i = 0; i < K; i++) {
        free(w[i]);
    }
    free(w);
}


void buscaLocal (Candidato *vet, int **misturas, int pop, int amostras) {
    int n = 10; // times the search will run
    int randi;
    int randj;
    
    
    // allocation
    int **aux = NULL;
    
    aux = (int **)malloc(K*sizeof(int*));
    for (int i = 0; i < K ; i++) {
        aux[i] = (int *)malloc(K*sizeof(int));
    }
    int **matTransforma = NULL;
    
    matTransforma = (int **)malloc(K*sizeof(int*));
    for (int i = 0; i < K ; i++) {
        matTransforma[i] = (int *)malloc(K*sizeof(int));
    }
    // end of allocation
    
    
    //identity matrix
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            if (i == j)
                matTransforma[i][j] = 1;
            else
                matTransforma[i][j] = 0;
        }
    }
    
    for (int individuo = 0; individuo < pop; individuo++) {
        for (int i = 0; i < n; i++) {
            randi = aleatorio_int(K);
            randj = aleatorio_int(K);
            
            while (randi == randj) { // to make sure the value changed to 1 will not be in the identity matrix
                randi = aleatorio_int(K);
            }
            
            matTransforma[randi][randj] = 1; // the transformation matrix is now created
            
            //multiply the candidate by the transformation matrix to check if the change yielfs a better fitness
            multiplicaMatrizABFinito(matTransforma, vet[individuo].mat, aux, K, K, K, ORDEM);
            
            if (entropiaTotal(vet[individuo].mat, misturas, ORDEM, K, amostras > entropiaTotal(aux, misturas, ORDEM, K, amostras))) {
                copiaMatrizAparaB(aux, vet[individuo].mat, K, K);
                
                matTransforma[randi][randj] = 0;
                break;
            }
            matTransforma[randi][randj] = 0;
        }
    }
    //free
    liberaMatrizInt(matTransforma, K, K);
    liberaMatrizInt(aux, K, K);
}