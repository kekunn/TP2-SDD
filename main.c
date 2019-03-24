#include <stdio.h>
#include "pile.h"
#include "file.h"
#include "truc.h"

int main()
{
    int tab[4] = {1, 2, 3};
    
    printf("\n\nTRUC RECURSIF\n");
    TRUC_rec(1, 3, tab);

    printf("\n\nTRUC ITERATIF\n");
    TRUC_ite(1, 3, tab);

    pile_t * p = initPile(1);
    if(p)
    {
        if (pileVide(p))
        {
            printf("pile vide\n");
        }

        if (!empiler(p, 1))
        {
            printf("pile pleine\n");
        }

        printf("%d\n", pilePlein(p));
        printf("%d\n", pilePlein(p));
        printf("%d\n", pilePlein(p));
        printf("%d\n", pilePlein(p));
        printf("%d\n", pilePlein(p));
        printf("%d\n", pilePlein(p));
        printf("%d\n", pilePlein(p));
        printf("%d\n", pilePlein(p));
        printf("%d\n", pilePlein(p));
        
        libererPile(&p);
    }

    return 0;
}

