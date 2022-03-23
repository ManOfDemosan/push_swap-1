#include <stdio.h>

int main(void)
{
    double  a = 5.29427309e-7;
    double  b = 0.024;
    int     c;
    c = a * (5000 * 5000) + b * (5000) + 15;
    printf("%d\n", c);
    return (0);
}