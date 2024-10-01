/* Loris SOGLIUZZO */
#include <stdio.h>

#include "paint.h"

/*
Question 1: 5 pixels
Question 2: (i_min = 5, j_min = 10) à (i_max = 9, j_max = 10)
Question 3: On voit 5 pixels rouges en ligne horizontalement sur un fond noir
*/

void ligne_horizontale(int j,int i_min,int i_max, int r, int g, int b, int largeur,int hauteur, unsigned char* pixels) 
{ 
    for (int i = i_min; i <= i_max; i++)
    {
        color_pixel(i,j,r,g,b,largeur,hauteur,pixels);
    }
}

void rectangle(int x_min, int y_min, int x_max, int y_max, int r, int g, int b, int largeur,int hauteur, unsigned char* pixels)
{
    for (int j = y_min; j <= y_max; j++)
    {
        ligne_horizontale(j, x_min, x_max, r, g, b, largeur, hauteur, pixels);
    }
}

int main()
{    
    // Question 4
    
    int largeur = 600;
    int hauteur = 400;
    unsigned char* pixels = create_pixels(largeur,hauteur);
    unsigned char r,g,b;
    r = 255;
    g = 0;
    b = 0;

    /*
    for (int i = 100; i <= 500; i++)
    {
        color_pixel(i,50,r,g,b,largeur,hauteur,pixels);
    }
    save_BMP("ligne.bmp", largeur, hauteur, pixels);
    destroy_pixels(pixels);
    */

    // Question 5
    ligne_horizontale(50, 100, 500, r, g, b, largeur, hauteur, pixels);
    save_BMP("ligne.bmp", largeur, hauteur, pixels);

    // Question 6
    //pixels = create_pixels(largeur,hauteur);
    //for(int j = 100; j <= 250; j++)
    //{
    //    ligne_horizontale(j, 50, 500, r, g, b ,largeur, hauteur, pixels);
    //}
    //save_BMP("rectangle.bmp", largeur, hauteur, pixels);

    // Question 7
    pixels = create_pixels(largeur,hauteur);
    rectangle(50, 100, 500, 250, r, g, b, largeur, hauteur, pixels);
    save_BMP("rectangle.bmp", largeur, hauteur, pixels);

    return 0;
}