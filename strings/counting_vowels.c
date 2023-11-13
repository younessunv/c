#include <stdio.h>
#include <string.h>

int main()
{
   int i, j, count = 0;
   char vowels[10] = {'a', 'e', 'u', 'o', 'i', 'A', 'E', 'U', 'O', 'I'};
   char string[33];

   printf("Would you insert a string and i will tell you how many strings it contains.");
   fgets(string, 33, stdin);
   int len = strlen(string);

   for(i = 0; i < len; i++)
   {
      for(j = 0; j < 10; j++)
         if(string[i] == vowels[j])
            count++;
   }

   printf("there are %d vowels in your string.", count);
}