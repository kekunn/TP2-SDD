#include "file.h"

/*---------------------------------------------------------------
* initialisation        Initialise une file
*
* Entrees: tailleMaxUser, un entier contenant la taille maximale de
*                         la pile, choisit par l'utilisateur
*
* Sortie: adresse d'une nouvelle file allouee
*
* On alloue un espace mémoire de la taille d'un element "file" et on
* initialise ses champs dont un tableau que l'on initialise grâce au
* données passée en argument.
*
* Lexique: nouv, pointeur sur le nouvel élément que l'on creer et
* que l'on initialise
*
*---------------------------------------------------------------
*/



file_t* initialisation(int tailleMaxUser)
{
    file_t* nouv = NULL;

    if ((tailleMaxUser) > 0)//La file doit au moins pouvoir contenir un element
    {
        nouv = (file_t*)malloc (sizeof(file_t));

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
    }
    return nouv;
}


/*---------------------------------------------------------------
* fileVide      Verifie si la file est vide
*
* Entree: file, adresse d'un pointeur de file
*
* Retourne un entier non nul si le compteur de la file est egal à 0
* et un entier nul sinon
*--------------------------------------------------------------- 
*/


int fileVide(file_t* file)
{
    return !(file->compteur);
}


/*---------------------------------------------------------------
* filePlein      Verifie si la file est pleine
*
* Entree: file, adresse d'un pointeur de file
*
* Retourne un entier non nul si le compteur de la file est egal à 
* la taille maximal de celle ci et un entier nul sinon
*--------------------------------------------------------------- 
*/


int filePlein(file_t* file)
{
    return (file->compteur == file->tailleMax);
}

/*---------------------------------------------------------------
* freedom        Libere la file
* 
* Entree: file, adresse d'un pointeur de file
*  
* Libere le tableau contenu dans l'element file et libere la file
* elle meme par la suite
*-------------------------------------------------------------------------
*/ 

void freedom(file_t* file)
{
    free(file->tab);
    free(file);
}


/*---------------------------------------------------------------
* entree         Insere un element dans la file
*
* Entree: file, adresse d'un pointeur de file
*         val, variable de type T contenant l'element que l'on 
*         veut inserer
*
* Sortie: bienPasse, booleen permettant de verifier si l'insertion
*         ses bien passee ou pas
*
* Insere un element val dans le tableau de la file à la postion
* du dernier rang si ce tableau n'est pas plein
*-------------------------------------------------------------------------
*/


int entree(file_t* file, T val)
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


/*---------------------------------------------------------------
* sortie         Retire un element dans la file
*
* Entree: file, adresse d'un pointeur de file
*         val, pointeur sur un element de type T qui va contenir
*              la valeur retiree
*
* Sortie: bienPasse, booleen permettant de verifier si l'insertion
*         ses bien passee ou pas
*
* Retire un element dans le tableau de la file à la postion
* du premier rang si ce tableau n'est pas vide et le stocke à 
* l'adresse pointee par val
*-------------------------------------------------------------------------
*/


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


/* -------------------------------------------------------------------- */
/* afficherFile         Affiche le contenu de la file                   */
/*                                                                      */
/* Entree: file, adresse de la pile                                     */
/*                                                                      */
/* On affiche tout les element de la file                               */
/*                                                                      */
/* Lexique: i, vairable de position dans la file                        */
/*                                                                      */
/* -------------------------------------------------------------------- */
void afficherFile(file_t* file)
{
    int i;
    printf("[");
    for(i = file->rangPremier; i < file->rangPremier + file->compteur; i++)
    {
        printf(FORMAT, file->tab[i% file->tailleMax]);
        
        if (i != file->rangPremier + file->compteur - 1)
        {
            printf(",");
        }
    }
    printf("]\n");
}