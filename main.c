#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int main()
{
    int FirstNum;
    int SecondNum;

    scanf("%d" "%d",&FirstNum, &SecondNum);

    printf("The prime numbers are:");

    for(int i=FirstNum; i<=SecondNum; i++)
    {
        if(isPrime(i))
        {
            printf(" %d" ,i);
        }
    }

    printf("\n");

    printf("The armstong numbers are:");

    for(int i=FirstNum; i<=SecondNum; i++)
    {
        if(isArmstrong(i))
        {
            printf(" %d" ,i);
        }
    }

    printf("\n");

    printf("The Strong numbers are:");

    for(int i=FirstNum; i<=SecondNum; i++)
    {
        if(isStrong(i))
        {
            printf(" %d" ,i);
        }
    }

    printf("\n");

    printf("The palindromes are:");

    for(int i=FirstNum; i<=SecondNum; i++)
    {
        if(isPalindrome(i))
        {
            printf(" %d" ,i);
        }
    }

    printf("\n");

    return 0;

}