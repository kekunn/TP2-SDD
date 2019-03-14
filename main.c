#include <stdio.h>
#include "pile.h"
#include "file.h"

void TRUC(int i,int n,int* T)
{
    int j;
    int temp;
    if( i == n)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ",T[j]);
        }
        printf("\n");
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

int main()
{
    int tab[4] = {1, 2, 3};
    TRUC(0, 3, tab);

    pile_t * p = init_pile(2);
    if (estVide(p))
    {
        printf("pile vide\n");
    }

    int tailleMax;
    int i;
    file_t* file;
   /* printf("Veuillez entrer les differents champs de votre file\n");
    printf("-------------------------------------------------------\n");
    printf("taille?\n");
    scanf("%d", &tailleMax);*/
    tailleMax= 5;
    file = initialisation(tailleMax);
    if(file == NULL)
    {
        printf("ça marche po\n");
    }
    else
    {
        printf("voici la pile qui marche %d\n", file->tailleMax);
    }

    printf("%d\n", fileVide(file));
    freedom(file);

    return 0;
}

