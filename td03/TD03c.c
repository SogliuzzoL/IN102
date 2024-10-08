/* Loris SOGLIUZZO */
#include <stdio.h>
#include <stdlib.h>

int trouver_max(int* X, int n)
{
    int max = X[0];
    for (int i = 1; i < n; i++)
    {
        if (X[i] > max)
        {
            max = X[i];
        }
    }
    return max;
}

void affichage(int* X, int n)
{
    for(int i = 0; i < n; i++)
    {
        if (i)
        {
            printf(",%d", X[i]);
        }
        else
        {
            printf("%d", X[i]);
        }
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    // Question 1
    for (int i = 1; i < argc; i++)
    {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    // Question 2
    int somme = 0;
    for (int i = 1; i < argc; i++)
    {
        int value = atoi(argv[i]);
        somme += value;
    }
    printf("Somme = %d\n", somme);

    // Question 3
    double produit = 1.0;
    for (int i = 1; i < argc; i++)
    {
        produit *= atof(argv[i]);
    }
    printf("Multiplication = %f\n", produit);

    // Question 4
    int T[argc - 1];
    for (int i = 1; i < argc; i++)
    {
        T[i - 1] = atoi(argv[i]);
    }
    affichage(T, argc - 1);
    printf("Le plus grand nombre est %d\n", trouver_max(T, argc - 1));
    return 0;
}