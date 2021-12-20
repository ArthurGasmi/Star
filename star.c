#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definition des macros espace et etoile
#define espace(n) repete(n,' ')
#define etoile(n) repete(n,'*')

// Retourne 1 si la chaîne est un nombre entier positif
int isNumber(char* x)
{
    for (int i = 0; i<strlen(x); i++) {
        if (x[i] < '0' || x[i] > '9') return 0;
    }
    return 1;
}

// Affiche un caractère n fois
void repete(int n, char c)
{
    for (int i = 0; i < n; i++) printf("%c",c);
}

// Affiche le sommet de l'étoile
void sommet(int size)
{
    espace(3*size+1);
    etoile(1);
    printf("\n");
}

// Affiche la pointe de l'étoile
void pointe(int size, int i,int fin, int pas)
{
    for (i; i != fin; i += pas) {
        espace(size*3-i);
        etoile(1);
        espace(2*i+1);
        etoile(1);
        printf("\n");
    }
}

// Affiche les lignes horizontales de l'étoile
void horizontale(int size)
{
    espace(1);
    etoile(2*size+1);
    espace(2*size-1);
    etoile(2*size+1);
    printf("\n");
}

// Affiche les diagonales de l'étoile
void diagonale(int size, int i, int fin, int pas)
{
    for (i; i != fin; i += pas) {
        espace(i+2);
        etoile(1);
        espace(6*size-3-2*i);
        etoile(1);
        printf("\n");
    }
}


int main(int argc, char** argv)
{
    // Verification des arguments
    if (argc != 2 || !isNumber(argv[1])) {
        fprintf(stderr, "Usage: %s taille\n", argv[0]);
        return 1;
    }

    // Conversion en int et sortie si size vaut 0
    int size = atoi(argv[1]);
    if (size == 0) return 0;

    // Affiche la partie supérieure de l'étoile
    sommet(size);
    pointe(size, 0, size-1, 1);
    horizontale(size);
    diagonale(size, 0, size-1, 1);

    // Affiche la partie inférieure de l'étoile
    diagonale(size, size-1, -1, -1);
    horizontale(size);
    pointe(size, size-2, -1, -1);
    sommet(size);

    // Pas d'erreur, on retourne 0
    return 0;
}
