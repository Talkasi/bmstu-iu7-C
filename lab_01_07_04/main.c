#include <math.h>
#include <stdio.h>

double s_computation(double x, double eps);

int main(void)
{
    double x, eps;
    double f, s;
    double absolute_error, relative_error;

    printf("Enter x: ");
    if (scanf("%lf", &x) != 1 || fabs(x) >= 1.0)
    {
        printf("Input error");
        return 1;
    }

    printf("Enter eps: ");
    if (scanf("%lf", &eps) != 1 || eps > 1.0 || eps <= 0.0)
    {
        printf("Input error.");
        return 1;
    }

    f = 1.0 / (1.0 + x) / (1.0 + x) / (1.0 + x);
    s = s_computation(x, eps);

    absolute_error = fabs(f - s);
    relative_error = fabs(f - s) / fabs(f);

    printf("S(x): %.6lf\nF(x): %.6lf\n", s, f);
    printf("Absolute error: %.6lf\nRelative error: %.6lf\n", absolute_error, relative_error);

    return 0;
}

double s_computation(double x, double eps)
{
    double elem = 1.0;
    double s = 1.0;
    int i = 0;

    while (fabs(elem) > eps)
    {
        ++i;
        elem *= -(i + 2) * x / i;
        s += elem;
    }

    return s;
}
