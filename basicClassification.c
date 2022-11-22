#include "NumClass.h"
#include <math.h>

int isPrime(int n)
{
    for (int i = 2; i <= sqrt(n) ; i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}

int factorial(int x)
{
    if(x==0)
    {
       return 1; 
    }
    return x*factorial(x-1);
}

int isStrong(int y)
{
    int sum=0;
    int number=y;

    while(number>0)
    {
        int obj=number%10;
        sum+=factorial(obj);
        number=number/10;
    }

    if(sum==y)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}