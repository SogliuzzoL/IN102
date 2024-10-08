/* Loris SOGLIUZZO */
#include <stdio.h>

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

int compter_nombre(int* X, int n, int y)
{
    int compte = 0;
    for(int i = 0; i < n; i++)
    {
        if (X[i] == y)
        {
            compte ++;
        }
    }
    return compte;
}

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

int* max_idx(int* X, int n)
{
    int max = X[0];
    int idx_max = 0;
    for (int i = 1; i < n; i++)
    {
        if (X[i] > max)
        {
            max = X[i];
            idx_max = i;
        }
    }
    return &X[idx_max];
}

int neg_max(int* X, int n)
{
    int* idx = max_idx(X, n);
    X[idx - X] = -*idx;
}

int main()
{
    // Question 1
    int n = 20;
    int T[n];
    T[0] = 3;
    for (int i = 1; i < n; i++)
    {
        if (T[i - 1] % 2)
        {
            T[i] = 3 * T[i - 1] + 1;
        }
        else
        {
            T[i] = T[i - 1] / 2;
        }
    }

    // Question 2
    affichage(T, n);

    // Question 3
    int compte1 = compter_nombre(T,20,1);
    int compte3 = compter_nombre(T,20,3);
    int compte6 = compter_nombre(T,20,6);
    printf("Nombre de 1: %d\nNombre de 3: %d\nNombre de 6: %d\n", compte1, compte3, compte6);

    // Question 4
    int max3 = trouver_max(T,3);
    int max5 = trouver_max(T,5);
    int max20 = trouver_max(T,20);
    printf("Max n=3: %d\nMax n=5: %d\nMax n=20: %d\n", max3, max5, max20);

    // Question 5
    int* idx = max_idx(T, 20);
    printf("Max : %d, Index: %ld\n", *idx, idx - T);

    // Question 6
    neg_max(T, 20);
    affichage(T, 20);

}