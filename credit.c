#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long num;
    do
    {
        num = get_long("Input your credit card number:\n");
    }

    while (num < 0);



    // sum the 1th, 3th, 5th, "odd" digits, starting from the last
    int sum;
    int x2_sum = 0, add_sum = 0;

    // sum the 1st, 3rd, 5th, "odd" digits, starting from the left
    for (long n = num / 10; n > 0; n /= 100)

    {
        int d = 2 * (n % 10);

        if (d>9)
        {
            x2_sum += d / 10;
            x2_sum += d % 10;
        }
        else
        {
            x2_sum += d;
        }
    }

    // sum the 2nd, 4th, 6th, "odd" digits, starting from the left
    for (long m = num; m > 0; m /= 100)

    {
        add_sum += m % 10;
    }



    // sum up the digits according to the rules
    sum = add_sum + x2_sum;


    // check validity
    if (sum % 10 == 0)
    {
        if ((num >= 34 * pow(10.0, 13.0) && num < 35 * pow(10.0, 13.0)) || (num >= 37 * pow(10.0, 13.0) &&  num < 38 * pow(10.0, 13.0)))
        {
            printf("AMEX\n");
        }

        else if (num >= 51 * pow(10.0, 14.0) && num < 56 * pow(10.0, 14.0))
        {
            printf("MASTERCARD\n");
        }

        else if ((num >= 4 * pow(10.0, 12.0) && num < 5 * pow(10.0, 12.0)) || (num >= 4 * pow(10.0, 15.0) && num < 5 * pow(10.0, 15.0)))
        {
            printf("VISA\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}