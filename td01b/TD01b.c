/* Loris SOGLIUZZO */
#include <stdio.h>

int main()
{
    float x;
    float y;

    x = 0.0;
    y = 5.0 / 9.0 * (x - 32.0);
    
    printf("%.2f F = %.2f C\n", x, y);
    printf("%g F = %g C\n", x, y);
    printf("%.3g F = %.3g C\n", x, y);
    printf("%d F = %d C\n", x, y);

    return 0;
}

/* 
Question 1: float
Question 4: 0.00 F = -17.78 C
Question 5: 80.00 F = 26.67 C
Question 6: 100.00 F = 37.78 C
Question 7: 0 F = -17.7778 C
Question 8: 0 F = -17.8 C
Question 9: 1516528288 F = 0 C
*/