//
//  futoshiki.c - Futoshiki Solver by Jacopx

#include "futoshiki.h"
#include <stdio.h>
#include <stdlib.h>

//stampa matrix
void stampa_schema (rules **tb, int dim)
{
    int i, j;
    printf("Soluzione Generata:\n");
    for(i=0; i<dim; i++)  {
        for(j=0; j<dim; j++) {
            printf("%d ", tb[i][j].V);
        }
        printf("\n");
    }
}

int disp_ripet(rules **tb, int dim, int pos)
{
    int i, j, k;
    
    if(pos>=dim*dim)
    {
        stampa_schema(tb, dim);
        return 1;
    }
    
    i=pos/dim;
    j=pos%dim;
    
    if(tb[i][j].V!=0)
        return(disp_ripet(tb, dim, pos+1));
    
    for(k=1;k<=dim;k++)
    {
        tb[i][j].V=k;
        if(controlla(tb, dim, pos))
            if(disp_ripet(tb, dim, pos))
                return 1;
        tb[i][j].V=0;
    }
    return 0;
}

//controll function
int controlla (rules **tb, int dim, int pos)
{
    int r, c, occ[dim], i, j;
    
    i=pos/dim;
    j=pos%dim;
    
    //controllo righe
    for(r=0; r<dim; r++) {
        
        for(c=0; c<dim; c++) //azzero vettore occorrenze
            occ[c] = 0;
        
        for(c=0; c<dim; c++)  //calcolo occorrenze
            occ[tb[r][c].V-1]++;
        
        for(c=0; c<dim; c++) //verifico se c'e' piu' di un'occorrenza
            if(occ[c] > 1)
                return 0;
    }
    
    // controllo colonne
    for(c=0; c<dim; c++) {
        
        for(r=0; r<dim; r++) //azzero vettore occorrenze
            occ[r] = 0;
        
        for(r=0; r<dim; r++)  //calcolo occorrenze
            occ[tb[r][c].V-1]++;
        
        for(r=0; r<dim; r++) //verifico se c'e' piu' di un'occorrenza
            if(occ[r] > 1)
                return 0;
    }
    
    //Controllo vincoli N O S E
    if(tb[i][j].N==1)
    {
        if(tb[i][j].V<tb[i-1][j].V)
        {
            return 0;
        }
    }
    if(tb[i][j].N==-1)
    {
        if(tb[i][j].V>tb[i-1][j].V)
        {
            return 0;
        }
    }
    if(tb[i][j].O==1)
    {
        if(tb[i][j].V<tb[i][j-1].V)
        {
            return 0;
        }
    }
    if(tb[i][j].O==-1)
    {
        if(tb[i][j].V>tb[i][j-1].V)
        {
            return 0;
        }
    }
    
    return 1;
}



