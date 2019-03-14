#include <stdio.h>
#include "truc.h"
#include "pile.h"

void TRUC(int i,int n,int* T)
{
    int j;
    int temp;
    if( i == n)
    {
        printf("[ ");
        for(j = 0; j < n; j++)
        {
            printf("%d ",T[j]);
        }
        printf("]\n");
    }
    else
    {
        for (j = i; j < n; j++)
        {
            temp = T[i];
            T[i] = T[j];
            T[j] = temp;
            TRUC(i + 1, n, T);
            temp = T[i];
            T[i] = T[j];
            T[j] = temp;
        }
    }
}

void Affichage(int n, int * T)
{
    int i;
    printf("[ ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", T[i]);
    }
    printf("]\n");
}

void Inverser(int i, int j, int* T)
{
    int temp = T[i];
    T[i] = T [j];
    T[j] = temp;
}

void TRUC_ite (int i, int n, int* T)
{
    pile_t*          p = init_pile(n);
    pile_t*          p2 = init_pile(n);
    element_pile     il = i;
    element_pile     j = 0;
    int              fin = 0;
    int              ok;

    while(!fin)
    {
        if( il != n-1 && j < n)
        {
            while (j < n)
            {
                Inverser(il, j, T);
                empiler(p, j);
                empiler(p2, il);
                il++;
                j = il;
            }
        }

        if(il == n-1)
        {
            Affichage(n, T);
        }

        if(estVide(p))
        {
            fin = 1;
        }
        else
        {
            depiler(p, &j, &ok);
            depiler(p2, &il, &ok);
            Inverser(il, j, T);
            j++;
        }
    }
}