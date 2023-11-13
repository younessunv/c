#include <stdio.h>
#include <string.h>

int length(char string)
{
  int len = 0;
  while (string != '\0') 
  {
    len++;
    string++;
  }
  return len;
}

int main()
{
    char string[] = "Practicing strings";

    int len = length(string);
    printf("the lenght using the function: %d", len);
}