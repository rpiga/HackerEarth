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
      strcpy(string_a, buf); //, sizeof(buf));
    }
    //printf("string_a: %s\n", string_a);

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
    //printf("string_b: %s\n", string_b);
    
    int count = 0;
    buf[0] = '\0';
    
    for(i = 0; i < strlen(string_a); i++)
    {
      char found = 0;
      int idx = 0;
      for (l = 0; l < strlen(string_b); l++)
      {
        if (string_a[i] == string_b[l] && found == 0)
        {
          found = 1;
        }
        else
        {
          buf[idx] = string_b[l];
          idx++;
        }
      }
      buf[idx] = '\0';
      //printf("appo %s\n", appoggio);
      strcpy(string_b, buf);
      if ( found != 1)
      {
        count ++;
      }
    }
    tests --;
    printf("%d\n", count + (int) strlen(buf));
  }
  
  
  free(string_a);
  free(string_b);

  return 0;
}

/*
    char *string_A, *string_B;
    if (strlen(string_a) <= strlen(string_b))
    {
      string_A = &string_a[0];
      string_B = &string_b[0];
    }
    else
    {
      string_A = &string_b[0];
      string_B = &string_a[0];
    }
    
    int count = 0;
    for (i = 0; i < strlen(string_A); i++)
    {
      for (l = 0; l < strlen(string_B); l++)
      {
        if (string_A[i] == string_B[l])
        {
          count ++;
          break;
        }
      }
    }
    //printf("%s\n%d\n", string_A, count);
    
    int answer = strlen(string_A) + strlen(string_B) - (2 * count);
    printf("%d\n", answer);
    
    */

