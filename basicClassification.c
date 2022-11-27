#include "NumClass.h"
#include <math.h>

int isPrime(int num)
{
    if(num==0)
        return 0;
    for (int i = 2; i <= sqrt(num) ; i++)
    {
        if(num%i==0)
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

int isStrong(int num)
{
    if(num==0){
        return 0;
    }
    int sum=0;
    int number=num;

    while(number>0)
    {
        int obj=number%10;
        sum+=factorial(obj);
        number=number/10;
    }

    if(sum==num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}