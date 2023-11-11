#include <stdio.h>

int main()
{
    int arr[100], x;
    int *p = arr;

    printf("insert your numbers in the list {-1 to stop}: ");
    while(1)
    {
        if(*p)
    }
    for (p = arr; p < arr + 6; p++)
    {
        scanf("%d", p);
    }

    printf("would you insert the number you wanna remove from the list: ");
    scanf("%d", &x);
    
    for(p = arr; p < arr + 6; p++)
    {   
        if(*p == x)
            continue;
        printf("%d ", *p);
    }
    return 0;
}
