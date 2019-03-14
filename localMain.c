#include "file.h"

int main()
{
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
    
}