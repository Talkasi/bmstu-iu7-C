#include <math.h>
#include <stdio.h>

int main()
{
    double x, eps;
    double eps_float = 1e-8;
    double f, s, elem;
    double absolute_error, relative_error;
    long long s_parameter;

    printf("Enter x: ");
    if (scanf("%lf", &x) != 1 || fabs(x) >= 1)
    {
        printf("Input error");
        return 1;
    }

    printf("Enter eps: ");
    if (scanf("%lf", &eps) != 1 || eps > 1 || eps <= 0)
    {
        printf("Input error.");
        return 1;
    }

    f = 1.0 / (1 + x) / (1 + x) / (1 + x);

    s = 1.0;
    s_parameter = 2.0;
    elem = s;

    while (fabs(elem) - eps > eps_float)
    {
        ++s_parameter;
        elem = -elem * s_parameter / (s_parameter - 2.0) * x;
        s += elem;
    }

    absolute_error = fabs(f - s);
    relative_error = fabs(f - s) / fabs(f);

    printf("S(x): %lf\nF(x): %lf\n", s, f);
    printf("Absolute error: %lf\nRelative error: %lf\n", absolute_error, relative_error);

    return 0;
}
