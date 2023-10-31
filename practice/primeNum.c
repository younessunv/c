#include <stdio.h>
#include <math.h>

int main()
{
    int x, i;
    int is_prime = 1;

    printf("insert a number: ");
    scanf("%d", &x);

    if(x == 1)
        printf("the number 1 is Not a prime number.");
    else if(x == 2)
        printf("the number 2 is a prime number.");
    else
        for(i = 2; i <= sqrt(x); i++)
        {
            if(x % i == 0)
            {
                is_prime = 0;
                break;
            }
        }
    
    if(is_prime == 0)
        printf("the number %d is Not prime number.", x);
    else
        printf("the number %d is a prime number.", x);
    return 0;
}
