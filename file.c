#include "file.h"


file_t* initialisation(int tailleMaxUser)
{
    file_t* nouv=(file_t*)malloc (sizeof(file_t));
    if (nouv != NULL)
    {
        nouv->tab=(int*) malloc (tailleMaxUser*sizeof(int));
        if(nouv->tab == NULL)
        {
            free (nouv);
            nouv = NULL;
        }
        else
        {
            nouv->tailleMax = tailleMaxUser;
            nouv->compteur = 0;
            nouv->rangPremier = 0;
            nouv->rangDernier = 0;
        }
        
    }
    return nouv;
}

int fileVide(file_t* file)
{
    return !(file->compteur);
}

int filePlein(file_t* file)
{
    return (file->compteur == file->tailleMax);
}

void freedom(file_t* file)
{
    free(file->tab);
    free(file);
}

int entree(file_t* file, int val)
{
    int bienPasse;
    if(!filePlein(file))
    {
        file->tab[file->rangDernier] = val;
        file->rangDernier = (file->rangDernier+1) %  file->tailleMax;
        file->compteur = file->compteur+1;
        bienPasse = 1;
    }
    else bienPasse = 0;
    
    return bienPasse;
}

int sortie(file_t* file, T* val)
{
    int bienPasse;
    if(!fileVide(file))
    {
        *val = file->tab[file->rangPremier];
        file->rangPremier= file->rangPremier+1 % file->tailleMax;
        file->compteur = file->compteur-1;
        bienPasse = 1;
    }
    else bienPasse = 0;

    return bienPasse;
}