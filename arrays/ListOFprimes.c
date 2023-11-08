#include <stdio.h>

int main ()
{
    int n, i, j, count = 0;
    int arr[300];

    for(i = 2; i < 300; i++)
    {
        int is_prime = 1;
        for(j = 2; j * j <= i; j++)
        {
            if(i % j == 0 || i % (j + 2) == 0)
            {
                is_prime = 0;
                break;
            }
        }
        if(is_prime)
            {
                arr[count] = i;
                count++;
            }    
    }

    printf("Would you insert a number of prime numbers you want: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}