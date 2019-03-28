#include <stdio.h>
#include "pile.h"
#include "file.h"
#include "truc.h"

int main()
{

    printf("=====================TEST TRUC=====================\n\n");

    int tab[4] = {1, 2, 3};
    
    printf("\n\nTRUC RECURSIF\n");
    TRUC_rec(1, 3, tab);

    printf("\n\nTRUC ITERATIF\n");
    TRUC_ite(1, 3, tab);




    printf("\n\n=====================TEST PILE=====================\n\n");

    int taille_pile = 6;
    pile_t * p = initPile(taille_pile);

    if(p)
    {
        int ok;
        int temp;
        int i;

        if (pileVide(p))
        {
            printf("Pile vide\n");
        }
        empiler (p, 1);
        depiler (p, &temp, &ok);

        if(ok)
        {
            printf("Valeur dépilé : %d\n", temp);
        }

        if(pileVide(p))
        {
            printf("Pile vide\n");
        }

        if(!empiler(p, 1))
        {
            printf("\nImpossible d'empiler l'element: pile pleine\n");
        }
        if(!empiler(p, 8) )
        {
            printf("\nImpossible d'empiler l'element: pile pleine\n");
        }
        if(!empiler(p, 12) )
        {
            printf("\nImpossible d'empiler l'element: pile pleine\n");
        }
        if(!empiler(p, 33))
        {
            printf("\nImpossible d'empiler l'element: pile pleine\n");
        }
        if(!empiler(p, 2))
        {
            printf("\nImpossible d'empiler l'element: pile pleine\n");
        } 
        if(!empiler(p, 17))
        {
            printf("\nImpossible d'empiler l'element: pile pleine\n");
        }

        if(pilePlein(p))
        {
            printf("Pile pleine\n");
        }

        printf("Contenu de la pile: \n");
        afficherPile(p);

        if(!empiler(p, 8))
        {
            printf("\nImpossible d'empiler l'element: pile pleine\n");
        }  
        
        sommet(p, &temp, &ok);
        if(ok)
        {
            printf("\nValeur du sommet de la pile: %d", temp);
        }

        printf("\n\n");
        printf("Vidage de la pile...\n\n");
        for(i = 0; i < taille_pile; i++)
        {
            depiler (p, &temp, &ok);

            if(ok)
            {
                afficherPile(p);
                printf("La valeur sortie est: %d\n\n", temp);
            }
            else
            {
                printf("Oups une erreur est survenue.\n\n");
            }
        }

        libererPile(p);
    }




    printf("\n\n=====================TEST FILE=====================\n\n");

    int taille_file = 8;
    file_t* file = initialisation(taille_file);
    printf("\n\n");

    if(!file)
    {
        printf("Initialisation de la file echoué.");
    }
    else
    {
        printf("Intitialisation de la file réussis.");
        int i;
        int valSortie;
    
        printf("\n\n");


        if(fileVide(file))
        {
            printf("La file est bien vide.");
        }
        else
        {
            printf("Oups la file n'est pas vide.");
        }  


        printf("\n\n");
        printf("Remplissage de la pile...\n\n");
        for(i = 1; i <= taille_file; i++)
        {
            entree(file, i);
        }

        printf("Affichage de la file:\n\n");
        afficherFile(file);


        if(filePlein(file))
        {
            printf("La file est bien pleine.");
        }
        else
        {
            printf("Oups la file n'est pas pleine.");
        }  


        printf("\n\n");
        printf("Vidage de la file...\n\n");
        for(i = 0; i < taille_file; i++)
        {
            if(sortie(file, &valSortie))
            {
                afficherFile(file);
                printf("La valeur sortie est: %d\n\n", valSortie);
            }
            else
            {
                printf("Oups une erreur est survenue.\n\n");
            }
        }

        if(fileVide(file))
        {
            printf("La file est bien vide.");
        }
        else
        {
            printf("Oups la file n'est pas vide.");
        }  
        
        printf("\n\n");

        printf("Suppression de la file..");

        freedom(file);
    }

    printf("\n\n=====================INVERSION PILE AVEC FILE=====================\n\n");


    pile_t    * p2 = initPile(6);
    if (p2)
    {

        empiler(p2, 1);
        empiler(p2, 8); 
        empiler(p2, 12); 
        empiler(p2, 33); 
        empiler(p2, 2); 

        int         reussi = 1;
        int         valeur_recup;
        file_t    * f = initialisation(p2->rang_sommet+1); //On initialise la file avec le nombre maximum d'element qu'elle contiendra

        if(f)
        {

            printf("\nPile avant : \n");
            afficherPile(p2);

            while(!pileVide(p2) && reussi)
            {
                depiler(p2, &valeur_recup, &reussi);

                if (reussi)
                {
                    entree(f, valeur_recup);   
                }
                else
                {
                    printf("Une erreur est survenu\n");
                }
            }

            while(!fileVide(f) && reussi)
            {
                if(sortie(f, &valeur_recup))
                {
                    empiler (p2, valeur_recup);
                }
                else
                {
                    printf("Une erreur est survenu\n");
                    reussi = 0;
                }
            }

            if (reussi)
            {
                printf("\n\nPile après : \n");
                afficherPile(p2);

                freedom(f);
            }
        }
        else
        {
            printf("Probeleme d'initialisation de la file\n");
        }

        libererPile (p2);
    }
    else
    {
        printf("Probleme d'initialisation de la piel\n");
    }

    return 0;
}

