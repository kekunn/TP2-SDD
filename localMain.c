#include "file.h"

int main()
{
    int tailleMax;
    int i;
    int j;
    int vide;
    int plein;
    int temp;
    int ok;
    int valSortie;
    file_t* file;
    

    printf("Veuillez rentrez la taille max de la pile:\n");
    scanf("%d", &tailleMax);
    file = initialisation(tailleMax);
    printf("\n\n");
    if(file == NULL)
    {
        printf("Initialisation de la file echoué.");
    }
    else
    {
        printf("Intitialisation de la file réussis.");
    }
    printf("\n\n\n\n");
    vide=fileVide(file);
    if(vide)
    {
        printf("La file est bien vide.");
    }
    else
    {
        printf("Oups la file n'est pas vide.");
    }  
    printf("\n\n\n\n");
    printf("Remplissage de la pile...\n\n\n\n");
    for(i=1;i<=tailleMax;i++)
    {
        entree(file, i);
    }
    printf("Affichage de la file:\n\n");
    printf("[");
    for(i=0;i<tailleMax;i++)
    {
        printf(" %d,", file->tab[i]);
    }
    printf("]\n\n\n\n");

    plein=filePlein(file);
    if(plein)
    {
        printf("La file est bien pleine.");
    }
    else
    {
        printf("Oups la file n'est pas pleine.");
    }  
    printf("\n\n\n\n");
    printf("Vidage de la file...\n\n");
    temp=tailleMax;
    for(i=0;i<tailleMax;i++)
    {
        if(ok=sortie(file, &valSortie))
        {
            printf("[");
            for(j=file->rangPremier;j<file->rangPremier+file->compteur;j++)
            {
                printf(" %d,", file->tab[j% file->tailleMax]);
            }
            printf("]\n\n");
            printf("La valeur sortie est: %d\n\n\n\n", valSortie);
        }
        else
        {
            printf("Oups une erreur est survenue.\n\n\n\n");
        }
        
        
    }

    vide=fileVide(file);
    if(vide)
    {
        printf("La file est bien vide.");
    }
    else
    {
        printf("Oups la file n'est pas vide.");
    }  
    printf("\n\n\n\n");

    printf("Suppression de la file..");

    freedom(file);
    

    

    
    
}