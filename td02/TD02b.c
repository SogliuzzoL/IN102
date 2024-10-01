/* Loris SOGLIUZZO */
#include <stdio.h>
#include <math.h>

#include "paint.h"

// Question 1
int compter_iterations(double x, double y, int max_iter)
{
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;

    for (int i = 0; i < max_iter; i ++)
    {
        if (a*a + b*b > 4)
        {
            return i;
        }

        double temp_a = a;
        double temp_b = b;

        a = a * a - b * b + x;
        b = 2 * c + y;
        c = a * b;
    }

    return max_iter;
}

int main()
{
    int max_iter = 100;

    int k = compter_iterations(1.0, 0.0, max_iter);
    printf("%d iteréations pour x=1 y=0\n", k);
    // Question 3 : 3 itérations

    k = compter_iterations(-1.0, 0.0, max_iter);
    printf("%d iteréations pour x=-1 y=0\n", k);
    // Question 4 : 100 itérations

    k = compter_iterations(0.0, 0.75, max_iter);
    printf("%d iteréations pour x=0 y=0.75\n", k);
    // Question 5 : 34 itérations

    // Question 6
    int width = 600;
    int height = 400;
    int x_left = -2;
    int y_top = 1;
    int x_width = 3;
    int y_height = x_width * height / width;
    /*
    x = x_left + i * x_width / (width - 1)
    y = y_top - j * y_height / (height - 1)
    */

    // Question 7
    int nb_iterations = 0;
    int r = 0;
    int g = 0;
    int b = 0;
    double x = 0;
    double y = 0;
    unsigned char* pixels = create_pixels(width, height);
    // Question 9
    double dx = 0.1;
    double dy = 0.2;
    // Question 10 : On doit créer xr pour stocker la valeur de x afin de calculer y, sinon la valeur de x serait changé et la valeur de y ne serait pas correcte.
    double angle = -0.5;
    double xr = 0;

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            x = x_left + i * x_width / (width - 1.0) + dx;
            y = y_top - j * y_height / (height - 1.0) + dy;
            xr = x * cos(angle) + y * sin(angle);

            y = -x*sin(angle)+y*cos(angle);
            x = xr;

            nb_iterations = compter_iterations(x, y, max_iter);

            // Question 8
            r = 255* nb_iterations / max_iter;
            b = sqrt(255*255-r*r);
            g = 255 * sin(sqrt(nb_iterations));

            if (nb_iterations == max_iter)
            {
                color_pixel(i, j, 0, 0, 0, width, height, pixels);
            }
            else
            {
                color_pixel(i, j, r, g, b, width, height, pixels);
            }
        }
    }

    save_BMP("mandelbrot.bmp", width, height, pixels);
}