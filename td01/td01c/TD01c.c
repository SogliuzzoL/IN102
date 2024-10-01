/* Loris SOGLIUZZO */
#include <stdio.h>

int main()
{
    // Question 1 à 5
    int nb_lignes = 5;
    int n = 20;
    int k = 9;

    for(int j = 0; j < nb_lignes; j++)
    {
        for(int i = 0; i < n; i++)
        {
            if (i % 2 == j % 2 || i < k) printf(" ");
            else printf("*");       
        }
        printf("\n");
    }
    printf("\n");

    // Question 6
    int m = 7;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j <= k + i; j++)
        {
            if(j < k) printf(" ");
            if (j <= k + i && j > k - 1) printf("*");
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}