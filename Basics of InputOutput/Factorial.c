/*
// Sample code to perform I/O:

scanf("%s", name);              // Reading input from STDIN
printf("Hi, %s.\n", name);      // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <stdio.h>

void main() {
  int N, result = 1;
  char buf[3];

  do
  {
    fgets(buf, sizeof(buf), stdin);
    N = atoi(buf);
  } while(N < 1 || N > 10);
  
  for(; N >0; N--) {
    result *= N;
  }
  
  printf("%d\n", result);
}