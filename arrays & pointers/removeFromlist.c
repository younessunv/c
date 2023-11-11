#include <stdio.h>

int main()
{
    int x, count = 0;
    int arr[100];
    int *p = arr;

    printf("insert your numbers in the list {-1 to stop}: ");
    while(1)
    {
        scanf("%d", p);

        if(*p == -1)
            break;
        if(count >= 100)
        {
            printf("you've reached the maximum of amount allowed");
            break;
        }

        p++;
        count++;
    }

    printf("would you insert the number you wanna remove from the list: ");
    scanf("%d", &x);
    
    for(p = arr; p < arr + count; p++)
    {   
        if(*p == x)
            continue;
        printf("%d ", *p);
    }
    return 0;
}
