/* Loris SOGLIUZO */
#include <stdio.h>

void affichage(char* ch)
{
    int i = 0;
    while (ch[i] != 0)
    {
        printf("%c", ch[i]);
        i++;
    }
    printf("\n");
}

int compter_lettre(char* ch, char x)
{
    int i = 0;
    int compte = 0;

    while (ch[i] != 0)
    {
        if (x == ch[i])
        {
            compte ++;
        }

        i ++;
    }

    return compte;
}

int position(char* ch, char x)
{
    int i = 0;
    while (ch[i] != 0)
    {
        if (x == ch[i])
        {
            return i;
        }
        i ++;
    }
    return -1;
}

int position_chaine(char* ch, char* m)
{
    int i = 0;
    while (ch[i] != 0)
    {
        int j = 0;
        int status = 1;
        while(m[j] != 0)
        {
            if (m[j] != ch[i + j])
            {
                status = 0;
                break;
            }
            j ++;
        }
        if (status)
        {
            return i;
        }
        i ++;
    }
    return -1;
}

int main()
{
    // Question 1
    char M[] = "suissesse";
    printf("%s\n", M);

    // Question 2
    affichage(M);

    // Question 3
    int s_nombre = compter_lettre("suissesse",'s');
    int x_nombre = compter_lettre("suissesse",'x');
    int e_nombre = compter_lettre("suissesse",'e');
    printf("Nombre de s: %d, nombre de x: %d, nombre de e: %d\n", s_nombre, x_nombre, e_nombre);

    // Question 4
    int s_pos = position("suissesse", 's');
    int x_pos = position("suissesse", 'x');
    int e_pos = position("suissesse", 'e');
    printf("Position de s: %d, position de x: %d, position de e: %d\n", s_pos, x_pos, e_pos);

    // Question 5
    int pos1 = position_chaine("suissesse","ss");
    int pos2 = position_chaine("suissesse","ee");
    int pos3 = position_chaine("suissesse","suissesse");
    int pos4 = position_chaine("suissesse","suissesses");
    printf("Position de 'ss': %d\nPosition de 'ee': %d\nPosition de 'suissesse': %d\nPosition de 'suissesses': %d\n", pos1, pos2, pos3, pos4);

    return 0;
}