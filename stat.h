//
//  stat.h
//  Cobi
//
//  Created by Daniel Pereira on 1/5/16.
//  Copyright (c) 2016 Akangatu. All rights reserved.
//

#ifndef __Cobi__stat__
#define __Cobi__stat__

#include <stdio.h>
#include <math.h>
#include <gsl/gsl_rng.h>

double uniformeRandom(const gsl_rng * r);
int uniform_distribution(int rangeLow, int rangeHigh);

#endif /* defined(__Cobi__stat__) */
