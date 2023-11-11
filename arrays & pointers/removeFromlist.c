#include <stdio.h>

#define Max_size 100

int main()
{
    int x, count = 0;
    int arr[Max_size];
    int *p = arr;

    printf("insert your numbers in the list {-1 to stop}: ");
    while(1)
    {
        if(count >= Max_size)
        {
            printf("you've reached the maximum of amount allowed");
            break;
        }
        
        scanf("%d", p);

        if(*p == -1)
            break;

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
