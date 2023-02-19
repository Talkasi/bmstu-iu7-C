#include <math.h>
#include <stdio.h>

int is_prime(int n);
int primes(int n);

int main()
{
    int n;

    printf("Enter number to work with: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Input error.");
        return 1;
    }

    if (n > 1)
        primes(n);

    return 0;
}

int is_prime(int n)
{
    if (n == 2)
        return 1;

    for (int i = 2; i <= ceil(sqrt(n)); ++i)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int primes(int n)
{
    int border;
    printf("Answer: ");

    if (is_prime(n))
    {
        printf("%d ", n);
        return 0;
    }

    border = ceil(n / 2.0);
    for (int i = 2; i <= border; ++i)
    {
        if (n % i == 0 && is_prime(i))
        {
            while (n % i == 0)
            {
                printf("%d ", i);
                n = n / i;
            }
        }
    }
    return 0;
}
