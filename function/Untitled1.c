#include<stdio.h>
#include<math.h>
int main()
{
    int i,num,count=0;
    printf("Enter any number=");
    scanf("%d",&num);
    if(num<=1)
    {
    count=1;
    }
    else
    {
    for(i=2;i<=num/2;i++)
    {
        if(num%i==0)
        {
            count=1;
            break;
        }

    }
        }
    if(count==0)
    {
        printf("%d is a prime number",num);

    }
    else
    {
        printf("%d is not a prime number",num);
    }

}
