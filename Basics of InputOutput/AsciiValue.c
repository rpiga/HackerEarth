/*
// Sample code to perform I/O:

scanf("%s", name);              // Reading input from STDIN
printf("Hi, %s.\n", name);      // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <stdio.h>

int main()
{
  char char_in[2];
  int c = 0;
  
  fgets(char_in, 2, stdin);
  if (char_in[0] < 0 || char_in[0] > 127) {
    printf("ERROR (ascii)\n");
    return 0;
  } 

  printf("%d\n", char_in[0]);
  
  
  return 0;
}
