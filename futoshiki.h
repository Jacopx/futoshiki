//
//  futoshiki.h
//  eser11_1
//
//  Created by Jacopo Nasi on 15/12/15.
//  Copyright © 2015 Jacopo Nasi. All rights reserved.
//

#ifndef futoshiki_h
#define futoshiki_h

#include <stdio.h>

typedef struct {
    int V, N, O, S, E;
}rules;

void stampa_schema (rules **tb, int dim);
int controlla (rules **tb, int dim, int pos);
int disp_ripet(rules **tb, int dim, int pos);

#endif /* futoshiki_h */
