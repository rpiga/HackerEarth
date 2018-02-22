/*
// Sample code to perform I/O:

scanf("%s", name);              // Reading input from STDIN
printf("Hi, %s.\n", name);      // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_MAX 10

void input(char *string,int length);

int main()
{
    char firstname[STR_MAX], lastname[STR_MAX];

    printf("What is your first name? ");
    input(firstname,STR_MAX);
    printf("What is your last name? ");
    input(lastname,STR_MAX);
    printf("Please to meet you %s %s.\n",
        firstname,
        lastname);

    return(0);
}

void input(char *string,int length)
{
    int x;

    fgets(string,length,stdin);
    for(x=0;x<=length;x++)
    {
        if( string[x] == '\n')
        {
            string[x] = '\0';
            break;
        }
    }
}


/*
int main()
{
  char buf[11];
  int i = 0;
  
  fgets(buf, 10, stdin );
  
  printf("%s\n%d\n", buf, (int)strlen(buf));
  
  for (; i<=strlen(buf); i++)
  {
    printf(">>%02d: %c ", i, buf[i]);
    if(buf[i] == '\n') {
      printf("-n");
      buf[i] = '\0';
    }
    if(buf[i] == '\0')
      printf("-0");
    
    printf("\n");
    printf(">>%02d: %c\n", i, buf[i]);
  }
  
  return 0;
}
*/