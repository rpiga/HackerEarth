/*
// Sample code to perform I/O:

scanf("%s", name);              // Reading input from STDIN
printf("Hi, %s.\n", name);      // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <stdio.h>

int main() {
  int N, n, m;
  char buf[4];

  do
  {
    fgets(buf, sizeof(buf), stdin);
    N = atoi(buf);
  } while(N < 1 || N > 10000);
  
  for (n=2; n < N; n++) {
    int result = 0;
    for (m=2; m < n; m++) {
      if(n%m == 0) {
        result = 1;
        break;
      }
    }
    if (result == 0)
      printf("%d ", n);
  }
  
}