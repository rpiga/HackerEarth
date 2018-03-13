/*
// Sample code to perform I/O:
#include <stdio.h>

int main(){
	int num;
	scanf("%s", &num);              			// Reading input from STDIN
	printf("Input number is %d.\n", num);       // Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_LENGTH_MAX 4

void correct(char *str_in, int N)
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

  if (strlen(str_in) == N-1 )
    while((ch = getchar())!='\n' && ch != EOF  );
}

int is_prime(int N) 
{
	// check if number N is prime
	// return 0= False; 1= True
	int n = 2;
	
  for (; n < N; n++)
	{
		if(N%n == 0) {
			return 0;
		}
  }
	return 1;
}

int is_lower(int s)
{
	// check if char is lowercase or UPPERCASE
	// return 0= UPPER 1= lower
	if ( s > 64 && s < 91)
		return 0;
return 1;
}

int return_prime(int n)
{
	// return nearest prime number from n
	int lower, i, result;
	
	lower = 65 + (is_lower(n) * 32);
	result = 999;
	
	//printf(" %d %d %d\n", n, is_lower(n), lower);
	
	for (i = lower ; i < lower + 26; i++)
	{
		if(is_prime(i) == 1 && abs(i - n) < result)
			result = i;
			//printf("%c %d OK %d \n", i, i, abs(i - n));
	}
	
	return result;
}

int return_prime_old(int n)
{
	// return nearest prime number from N
	int lower, upper, N;
	N = n;
	printf(" %d %d ", n, is_lower(n));
	// calculate lower bound
	while (N > 1)
	{
		if(is_prime(N) == 1)
		{
			lower = N;
			break;
		}
		N--;
	}
	printf(" %d", lower);
	
	// calculate upper bound
	N = n;
	while (N)
	{
		if ( is_prime(N) == 1 )
		{
			upper = N;
			break;
		}
		N++;
	}
	printf(" %d ", upper);
	
	// return nearest
	if ( (n - lower) <= (upper - n) )
		return lower;
	else
		return upper;
}

void main(int argc, char *argv[])
{
  int T, N, i, j;
  char buf[STR_LENGTH_MAX], str_buf[500];

  do
  {
    fgets(buf, STR_LENGTH_MAX, stdin);
    correct(&buf[0], STR_LENGTH_MAX);
    T = atoi(buf);
  } while ( T < 1 || T > 100 );
  
  while (T > 0)
  {
		// inputs
		do
		{
			fgets(buf, STR_LENGTH_MAX, stdin);
			correct(&buf[0], STR_LENGTH_MAX);
			N = atoi(buf);
		} while ( N < 1 || N > 500 );
		
		if (fgets(str_buf, N+1, stdin) != NULL)
		{
			correct(&str_buf[0], N+1);
			// DEBUG printf(">> %s\n", str_buf);
			for ( i=0; i < N; i++)
			{
				printf("%c", return_prime(str_buf[i]));
				/*DEBUG printf("%c %d %d %c\n", str_buf[i], str_buf[i], \
							is_prime(str_buf[i]), \
							return_prime(str_buf[i]));*/
				//return_prime(str_buf[i]);
			}
		}
	  printf("\n");  
		
    T--;
  }
  
  
}
