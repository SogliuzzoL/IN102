/* Loris SOGLIUZZO */
#include <stdio.h>
#include <stdlib.h>

// Question 1
struct intervalle
{
    int a;
    int b;
};

// Question 2
void affichage(struct intervalle I)
{
    printf("[%d, %d]\n", I.a, I.b);
}

struct intervalle saisie_intervalle()
{
    int a;
    int b;
    printf("a=");
    scanf("%d", &a);
    printf("b=");
    scanf("%d", &b);
    struct intervalle I = {a, b};
    return I;
}

struct intervalle intersection(struct intervalle I1, struct intervalle I2)
{
    int a;
    int b;

    if (I1.a > I2.a) a = I1.a;
    else a = I2.a;

    if (I1.b < I2.b) b = I1.b;
    else b = I2.b;

    struct intervalle I = {a, b};
    return I;
}

struct intervalle *saisie_tableau(int N)
{
    struct intervalle *tab = malloc(sizeof(struct intervalle) * N);

    for (int i = 0; i < N; i++)
    {
       tab[i] = saisie_intervalle(); 
    }
    
    return tab;
}

struct intervalle intersection_tableau(struct intervalle *tab, int N)
{
    struct intervalle I = tab[0];
    for (int i = 1; i < N; i++)
    {
        I = intersection(I, tab[i]);
    }
    return I;
}

void affichage_tableau_inverse(struct intervalle *tab, int N)
{
    for (int i = 0; i < N; i++)
    {
        affichage(tab[N - i - 1]);
    }
}


int main()
{
    // Question 3
    struct intervalle I1 = {-1, 9};
    affichage(I1);
    struct intervalle I2 = {-3, 5};
    affichage(I2);

    // Question 4
    struct intervalle test = saisie_intervalle();
    affichage(test);

    // Question 5
    test = intersection(I1, I2);
    affichage(test);

    // Question 6
    int N;
    printf("N=");
    scanf("%d", &N);
    struct intervalle *tab = saisie_tableau(N);

    // Question 7
    test = intersection_tableau(tab, N);
    affichage(test);

    // Question 8
    affichage_tableau_inverse(tab, N);

    free(tab);
    return 0;
}