#include <math.h>
#include <stdio.h>

int main()
{
    double xq, yq, xr, yr, xp, yp, eps = 1e-10, folder, k, b;

    printf("Enter x of the point q: ");
    if (scanf("%lf", &xq) != 1)
    {
        printf("Input error");
        return 1;
    }

    printf("Enter y of the point q: ");
    if (scanf("%lf", &yq) != 1)
    {
        printf("Input error.");
        return 1;
    }

    printf("Enter x of the point r: ");
    if (scanf("%lf", &xr) != 1)
    {
        printf("Input error.");
        return 1;
    }

    printf("Enter y of the point r: ");
    if (scanf("%lf", &yr) != 1)
    {
        printf("Input error.");
        return 1;
    }

    printf("Enter x of the point p: ");
    if (scanf("%lf", &xp) != 1)
    {
        printf("Input error.");
        return 1;
    }

    printf("Enter y of the point p: ");
    if (scanf("%lf", &yp) != 1)
    {
        printf("Input error.");
        return 1;
    }

    if (yq > yr)
    {
        folder = yr;
        yr = yq;
        yq = folder;

        folder = xr;
        xr = xq;
        xq = folder;
    }

    if (fabs(xq - xr) > eps)
    {
        k = (yq - yr) / (xq - xr);
        b = yr - k * xr;

        if (yp - k * xp - b <= eps && yp >= yq && yp <= yr)
            printf("1");
        else
            printf("0");
    }
    else
    {
        if (fabs(xp - xq) > eps || (fabs(xp - xq) <= eps && (yp < yq || yp > yr)))
            printf("0");
        else
            printf("1");
    }

    return 0;
}
