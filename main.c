//
//  main.c
//  eser11_1
//
//  Created by Jacopo Nasi on 15/12/15.
//  Copyright © 2015 Jacopo Nasi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "futoshiki.h"

int main(int argc, char **argv)
{
    FILE *fp=fopen(argv[1], "r");
    int n, i, j, k;
    rules **tb;
    
    fscanf(fp, "%d", &n);
    tb=malloc(n*sizeof(rules *));
    for(i=0; i<n; i++) {
        tb[i]=malloc(n*sizeof(rules));
    }
    for(k=0; k<n*n; k++) {
        i=k/n;
        j=k%n;
        fscanf(fp, "%d", &tb[i][j].V);
        fscanf(fp, "%d", &tb[i][j].N);
        fscanf(fp, "%d", &tb[i][j].O);
        fscanf(fp, "%d", &tb[i][j].S);
        fscanf(fp, "%d", &tb[i][j].E);
    }
    
    disp_ripet(tb, n, 0);
    
    return 0;
}
