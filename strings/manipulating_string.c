#include <stdio.h>
#include <string.h>

int main()
{
  char string[50];

  fputs("insert a string: ", stdout);
  fgets(string, 50, stdin);
  int len = strlen(string);
  int characters = len - 1;

  int i, count = 0;
  for(i = 0; i < len; i++)
  {
    if(string[i] == ' ')
      count++;
  }

  printf("the string contains %d characters and %d words.\n", characters, count + 1);

  int j = 0;
  for (i = 0; i < len; i++)
  {
    if(string[i] != ' ')
    {
      string[j] = string[i];
      j++;
    }
  }
  string[j] = '\0';

  fputs(string, stdout);

}