//
//  futoshiki.h - Futoshiki Solver by Jacopx

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