/*
// Sample code to perform I/O:

scanf("%s", name);              // Reading input from STDIN
printf("Hi, %s.\n", name);      // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <stdio.h>
#include <string.h>

int main()
{
  int result = 0;
  char input[16];
  char *values;
  int param[3] = {0};
  int idx = 0;
  
//  scanf("%s", input);
  fgets(input, 15, stdin);
//  printf("> %s**\n", input);
 
  values = strtok(input, " ");
  
  while (values != NULL) {
    param[idx] = atoi(values);
    idx++;
    values = strtok(NULL, " ");
  }
  
  // test constraints
  if (param[0] < 1 || param[0] > param[1] || param[1] > 1000 || param[2] > 1000 || param[2] < 1) {
    printf("ERROR (values)\n");
    return 0;
  }
  
  int i = 0;
  for (i = param[0]; i <= param[1]; i++)
  {
    if (i % param[2] == 0)
      result++;
  }
  
  printf("%d\n", result);
  
  return 0;
}
