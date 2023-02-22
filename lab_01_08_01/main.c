#include <inttypes.h>
#include <stdio.h>

#define BYTE_LENGTH 8
#define N_BYTES 4

int print_bin_representation(uint32_t integer);

int main()
{
    unsigned char byte;
    uint32_t integer = 0, fifteen = 0xFF;
    int shifter = BYTE_LENGTH * (N_BYTES - 1);

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
        printf(" %u", (integer & fifteen << BYTE_LENGTH * (N_BYTES - i - 1)) >> BYTE_LENGTH * (N_BYTES - i - 1));
    }
}

int print_bin_representation(uint32_t integer)
{
    uint32_t one = 1;
    for (int i = 31; i >= 0; --i)
        printf("%d", (integer & (one << i)) != 0);

    return 0;
}
