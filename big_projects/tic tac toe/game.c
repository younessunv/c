#include <stdio.h>
#include <stdlib.h>

void answer();
void checker();

int main()
{
    int menu_option = 0;

    char *game = ("         *         *          \n"
                 "         *         *          \n"
                 "         *         *          \n"
                 "         *         *          \n"
                 "******************************\n"
                 "         *         *          \n"
                 "         *         *          \n"
                 "         *         *          \n"
                 "         *         *          \n"
                 "******************************\n"
                 "         *         *          \n"
                 "         *         *          \n"
                 "         *         *          \n"
                 "         *         *          \n");

    do {
        printf("1-Play\n"
               "2-Leave\n");
        scanf("%d", &menu_option);
        system("cls");
    } while(menu_option != 1 && menu_option != 2);

    if (menu_option == 1) {
        printf("%s\n", game);
        
    } else if (menu_option == 2) {
        exit(0);
    }

    return 0;
}
