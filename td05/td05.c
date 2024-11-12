/* Loris SOGLIUZZO */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Question 1
int* creer_grille()
{
    int* t = malloc(sizeof(int) * 9);
    for(int i = 0; i < 9; i ++)
    {
        t[i] = 0;
    }
    return t;
}

// Question 2
void afficher(int* grille)
{
    for(int i = 0; i < 9; i++)
    {
        switch (grille[i])
        {
            case 1:
                printf("x");
                break;

            case 2:
                printf("o");
                break;

            default:
                printf(".");
                break;
        }

        if ( (i + 1) % 3 == 0)
        {
            printf("\n");
        } 
    }
    printf("============\n");
}

// Question 3
void test_affichage()
{
    int* grille_test = creer_grille();
    afficher(grille_test);
    grille_test[3] = 1;
    grille_test[7] = 2;
    afficher(grille_test);
    free(grille_test);
}

// Question 4
void placer(int* grille, int chiffre, int joueur)
{
    grille[chiffre - 1] = joueur;
}

// Question 5
void placer_alea(int* grille, int joueur)
{
    int chiffre;
    do
    {
        chiffre = rand() % 9 + 1;
    } 
    while (grille[chiffre - 1] != 0);
    
    placer(grille, chiffre, joueur);
}

// Question 6
int a_gagne(int* grille, int joueur)
{
    int aligne_diag1 = 0;
    int aligne_diag2 = 0;
    for(int i = 0; i < 3; i++)
    {
        // Tests lignes et colones
        int aligne_ligne = 0;
        int aligne_colone = 0;
        for (int j = 0; j < 3; j++)
        {
            if (grille[j + 3 * i] == joueur)
            {
                aligne_ligne ++;
            }
            if (grille[i + j * 3] == joueur)
            {
                aligne_colone ++;
            }
            
        }
        if (aligne_ligne == 3 || aligne_colone == 3)
        {
            return 1;
        }
        // Tests diagonales
        if (grille[i + 3 * i] == joueur)
        {
            aligne_diag1 ++;
        }
        if (grille[2 + 2 * i] == joueur)
        {
            aligne_diag2 ++;
        }
    }

    if (aligne_diag1 == 3 || aligne_diag2 == 3)
    {
        return 1;
    }
    
    return 0;
}

// Question 8
int match_nul(int* grille)
{
    for (int i = 0; i < 9; i ++)
    {
        if (grille[i] == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    srand(time(0));
    test_affichage();
    // Question 7
    int* grille = creer_grille();
    int chiffre;
    int n_tours = 0;
    while (1)
    {
        n_tours ++;
        afficher(grille);
        do
        {
            printf("Entrez un chiffre entre 1 et 9: ");
            scanf("%d", &chiffre);
        } 
        while (grille[chiffre - 1] != 0);
        placer(grille, chiffre, 1);
        if (a_gagne(grille, 1))
        {
            afficher(grille);
            printf("Vous avez gagné !\n");
            break;
        }
        
        if (match_nul(grille))
        {
            afficher(grille);
            printf("Match nul en %d tours.\n", n_tours);
            break;
        }
        
        placer_alea(grille, 2);
        if (a_gagne(grille, 2))
        {
            afficher(grille);
            printf("L'ordinateur a gagné !\n");
            break;
        }
        
        if (match_nul(grille))
        {
            afficher(grille);
            printf("Match nul en %d tours.\n", n_tours);
            break;
        }
        
    }
    
    
    free(grille);
    return 0;
}