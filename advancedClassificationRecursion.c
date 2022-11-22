#include "NumClass.h"
#include <math.h>

int isPalindromeReverse(int, int);

int NumberLength(int x)
{
    int length=0;
    while(x!=0)
    {
        length++;
        x=x/10;
    }
    return length;
}

int isPalindromeReverse(int num , int ReverseNum)
{
    if(num==0){
        return 0;
    }
    return ReverseNum*10 + num%10 +isPalindromeReverse(num/10, ReverseNum);
}

int isPalindrome(int OriginalNumber)
{   
    int reveseNum=0;
    int ReverseOriginalNumber=isPalindromeReverse(OriginalNumber,reveseNum);

    if(ReverseOriginalNumber==OriginalNumber)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isArmstongLength(int num)
{   
    int length=NumberLength(num);
    int changeOriginalNumber=num;
    if(changeOriginalNumber==0){
        return 0;
    }
    return pow(changeOriginalNumber%10,length)+isArmstongLength(changeOriginalNumber/10);
}


int isArmstrong(int OriginalNumber)
{
    int sum=isArmstongLength(OriginalNumber);

    if(sum==OriginalNumber)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}