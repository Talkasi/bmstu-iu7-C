#include <stdio.h>

int main(void)
{
    double v1, t1;
    double v2, t2;
    double v, t;

    printf("Enter number of liters V1 and temperature T1: ");
    if (scanf("%lf %lf", &v1, &t1) != 2 || v1 <= 0.0)
    {
        printf("Input error.\n");
        return 1;
    }

    printf("Enter number of liters V2 and temperature T2: ");
    if (scanf("%lf %lf", &v2, &t2) != 2 || v2 <= 0.0)
    {
        printf("Input error.\n");
        return 1;
    }

    v = v1 + v2;
    t = (v1 * t1 + v2 * t2) / v;

    printf("The volume is: %.6lf \nThe temperature is: %.6lf \n", v, t);
    return 0;
}
