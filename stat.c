//
//  stat.c
//  Cobi
//
//  Created by Daniel Pereira on 1/5/16.
//  Copyright (c) 2016 Akangatu. All rights reserved.
//

#include "stat.h"

double uniformeRandom(const gsl_rng * r) {
    double u = gsl_rng_uniform (r);
    return u;
    
}

int uniform_distribution(int rangeLow, int rangeHigh) {
    int range = rangeHigh - rangeLow + 1; //rangeLow, rangeHigh], inclusive.
    int copies=RAND_MAX/range; // we can fit n-copies of [0...range-1] into RAND_MAX
    int limit=range*copies;
    int myRand = 0;
    do {
        myRand=rand();
    } while(myRand>=limit);
    return myRand/copies+rangeLow;
}