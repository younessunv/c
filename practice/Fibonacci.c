#include <stdio.h>


int main() {

   int inp, a = 0, b = 1, nextTerm;

   do{
    printf("Enter a positive integer (the number of terms you want in the Fibonacci sequence): ");
    scanf("%d", &inp);
   }while(inp <= 0);

   for(int i = 0; i < inp; i++)
   {
        printf("%d ", a);

        nextTerm = a + b;
        a = b;
        b = nextTerm;
   }
    return 0;
}