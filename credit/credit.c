#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number: ");
    long n = number;
    int sum = 0;
    int count = 0;

    while (n > 0)
    {
        int digit = n % 10;

        if (count % 2 == 1)
        {
            int product = digit * 2;
            sum += (product / 10) + (product % 10);
        }
        else
        {
            sum += digit;
        }

        n /= 10;
        count++;
    }

    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    long start = number;
    while (start >= 100)
    {
        start /= 10;
    }

    if ((start == 34 || start == 37) && count == 15)
    {
        printf("AMEX\n");
    }
    else if ((start >= 51 && start <= 55) && count == 16)
    {
        printf("MASTERCARD\n");
    }
    else if ((start / 10 == 4) && (count == 13 || count == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
