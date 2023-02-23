#include <inttypes.h>
#include <stdio.h>

#define BYTE_LENGTH 8
#define N_BYTES 4

void print_bin_representation(uint32_t integer);

int main()
{
    unsigned char byte;
    int shifter = BYTE_LENGTH * (N_BYTES - 1);
    uint32_t integer = 0;

    for (int i = 0; i < N_BYTES; ++i)
    {
        printf("Enter byte #%d: ", i);
        if (scanf("%hhu", &byte) != 1)
        {
            printf("Error: Input error.\n");
            return 1;
        }

        integer |= (byte << shifter);
        shifter -= BYTE_LENGTH;
    }

    printf("Result: ");
    print_bin_representation(integer);

    for (int i = 0; i < N_BYTES; ++i)
    {
        printf(" %lu", (integer & 0xFFUL << BYTE_LENGTH * (N_BYTES - i - 1)) >> BYTE_LENGTH * (N_BYTES - i - 1));
    }
}

void print_bin_representation(uint32_t integer)
{
    for (int i = 31; i >= 0; --i)
        printf("%d", (integer & (1UL << i)) != 0);
}
