#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    //prompts for credit card number
    long creditcardno = get_long("Number: ");

    //determining number of digits in credit card
    int digitcount = 0;
    long digitcounter = creditcardno;
    do
    {
        digitcounter /= 10;
        digitcount ++;
    }
    while (digitcounter != 0);


    //if it has more than 16 digits
    if (digitcount > 16)
    {
        printf("INVALID\n");
    }
    //if it has less than 13 digits
    else if (digitcount < 13)
    {
        printf("INVALID\n");
        exit(0);
    }
    // if it is equal to 14 digits
    else if (digitcount == 14)
    {
        printf("INVALID\n");
        exit(0);
    }



    //retriving individual digits backwards
    int oddno = 0;
    int evenno = 0;
    long idigit = creditcardno;
    for (int x = 0; x != digitcount; x++)
    {
        //when x is even its the last number
        //when x is odd its the second last number
        long i = pow(10, (x + 1));
        long j = pow(10, x);
        long z = (idigit % i) / j;

        //adding odd numbers to oddno
        if (x % 2 == 1)
        {
            if (z * 2 >= 10)
            {
                int a = (z * 2) % 10;
                int b = (z * 2) / 10;
                oddno = oddno + a + b;
            }
            else
            {
                oddno = oddno + (z * 2);
            }
        }
        //adding even numbers to evenno
        else if (x % 2 == 0)
        {
            evenno = evenno + z;
        }
    }
    int sum = oddno + evenno;
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        exit(0);
    }


    //determines the first 2 digits and first digit of the card
    long digitstarter2 = creditcardno;
    for (int x = 0; x != (digitcount - 2); x++)
    {
        digitstarter2 /= 10;
    }

    if (digitstarter2 == 34)
    {
        printf("AMEX\n");
    }
    else if (digitstarter2 == 37)
    {
        printf("AMEX\n");
    }
    else if (digitstarter2 == 51)
    {
        printf("MASTERCARD\n");
    }
    else if (digitstarter2 == 52)
    {
        printf("MASTERCARD\n");
    }
    else if (digitstarter2 == 53)
    {
        printf("MASTERCARD\n");
    }
    else if (digitstarter2 == 54)
    {
        printf("MASTERCARD\n");
    }
    else if (digitstarter2 == 55)
    {
        printf("MASTERCARD\n");
    }
    else if (digitstarter2 >= 0)
    {
        digitstarter2 /= 10;
        if (digitstarter2 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
            exit(0);
        }

    }

}