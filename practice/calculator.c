#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int choice;
    char try;
    float x, y;
    char* menu = "  ----Calculatrice: MENU----\n"
                 "1- Addition: \n"
                 "2- Subtraction: \n"
                 "3- Multiplication: \n"
                 "4- Division: \n"
                 "5- Remainder of an integer division: \n"
                 "6- Power: \n"
                 "Enter the number of the operation you want to perform: ";

    do{
        printf("%s", menu);
        scanf("%d", &choice);
    
        printf("enter the first term: ");
        scanf("%f", &x);
        
        printf("enter the second term: ");
        scanf("%f", &y);
        
        switch(choice)
        {
            case 1: printf("The result is: %.2f", x + y);
                    break;
            case 2: printf("The result is: %.2f", x - y);
                    break;
            case 3: printf("The result is: %.2f", x * y);
                    break;
            case 4: if(y != 0)
                        printf("The result is: %.2f", x / y);
                    else
                        printf("Division by zero is impossible, try again.");
                    break;
            case 5: if(y != 0)
                        printf("The result is: %.2f", fmod(x,y));
                    else
                        printf("Division by zero is impossible, try again.");
                    break;
            case 6: printf("The result is: %.2f", pow(x,y));
                    break;
        }
        printf("\ndo you want to do another calculation (y/n): ");
        scanf(" %c", &try);
        system("cls");
    }while(try == 'y');
    
    return 0;
}
