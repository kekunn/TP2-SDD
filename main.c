#include <stdio.h>
#include "pile.h"
#include "file.h"
#include "truc.h"

int main()
{
    int tab[4] = {1, 2, 3};
    
    printf("\n\nTRUC RECURSIF\n");
    TRUC(0, 3, tab);

    printf("\n\nTRUC ITERATIF\n");
    TRUC_ite(0, 3, tab);

    pile_t * p = init_pile(2);
    if (estVide(p))
    {
        printf("pile vide\n");
    }

    return 0;
}

