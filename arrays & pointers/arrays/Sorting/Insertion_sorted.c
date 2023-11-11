int main()
{  
    int x, i, j, temp;
    int array[10];

    printf("would you insert 10 numbers: ");

    for(i = 0; i < 10; i++)
    {
        scanf("%d", &array[i]);
    }

    for(i = 0; i < 9; i++)
    {
        temp = array[i];
        j = i - 1;

        while(j >= 0 && array[j] > temp)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = temp;      
    }

    printf("sorted number: ");

    for(i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
