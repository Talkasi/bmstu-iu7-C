#include <stdio.h>

int main()
{
    double v1, v2;
    double t1, t2;
    double v, t;

    printf("Enter number of liters V1: ");
    if (scanf("%lf", &v1) != 1 || v1 <= 0)
    {
        printf("Input error. Value should be bigger than zero.\n");
        return 1;
    }

    printf("Enter temperature T1: ");
    if (scanf("%lf", &t1) != 1)
    {
        printf("Input error.\n");
        return 1;
    }

    printf("Enter number of liters V2: ");
    if (scanf("%lf", &v2) != 1 || v2 <= 0)
    {
        printf("Input error. Value should be bigger than zero.\n");
        return 1;
    }

    printf("Enter temperature T2: ");
    if (scanf("%lf", &t2) != 1)
    {
        printf("Input error.\n");
        return 1;
    }

    v = v1 + v2;
    t = (v1 * t1 + v2 * t2) / v;

    printf("The volume is: %lf\nThe temperature is: %lf\n", v, t);
    return 0;
}
