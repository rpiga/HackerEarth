/*
// Sample code to perform I/O:

scanf("%s", name);              // Reading input from STDIN
printf("Hi, %s.\n", name);      // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <stdio.h>

void main() {
  int N, r =1;
  for (scanf("%d", &N); N > 0; N--)
  {
    r *=N;
  }
  printf("%d\n", r);
}