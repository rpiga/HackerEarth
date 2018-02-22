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

#define STR_LENGTH_MAX 10001

void correct(char *str_in)
{
  // Correct last char from newline to string termination
  //
  int l = strlen(str_in), i;
  char ch; // char buffer manage stdin overflow
  
  for(i = 0; i <= l; i++)
  {
    if (str_in[i] == '\n')
    {
      str_in[i] = '\0';
      break;
    }
  }

  if (strlen(str_in) == STR_LENGTH_MAX-1 )
    while((ch = getchar())!='\n'  && ch != EOF  );
}

int main()
{
  char *string_a, *string_b, *t;
  char buf[STR_LENGTH_MAX+1]; // add extra space for newline
  int i, l, tests;
  
  // input number of tests
  //
  if (fgets(buf, STR_LENGTH_MAX, stdin) != NULL)
  {
    correct(&buf[0]);
    tests = atoi(buf);
  }
  
  while (tests > 0)
  {
    // input string A
    //
    if (fgets(buf, STR_LENGTH_MAX, stdin) != NULL)
    {
      correct(&buf[0]);
      string_a = (char *)malloc((strlen(buf)) * sizeof(char));
      if (string_a == NULL)
        exit (0);
      strcpy(string_a, buf);
    }

    // input string B
    //
    if (fgets(buf, STR_LENGTH_MAX, stdin) != NULL)
    {
      correct(&buf[0]);
      string_b = (char *)malloc((strlen(buf)) * sizeof(char));
      if (string_b == NULL)
        exit (0);
      strcpy(string_b, buf);
    }
    
    int count = 0;
    for(i = 0; i < strlen(string_a); i++)
    {
      for (l = 0; l < strlen(string_b); l++)
      {
        if (string_a[i] == string_b[l])
        {
          string_b[l] = ' ';
          count ++;
          break;
        }
      }
    }
    tests --;
    int total = strlen(string_b) + strlen(string_a) - (2 * count);
    printf("%d\n", total );
  }
  
  
  free(string_a);
  free(string_b);

  return 0;
}
