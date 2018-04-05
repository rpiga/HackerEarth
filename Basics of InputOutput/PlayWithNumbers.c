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
//#include <math.h>

#define MAX_STRING_LENGTH_NQ 16 // actual max string's length +1
#define MAX_INTEGER 1000000
#define MAX_ARRAY_ELEMENTS 1000000000

int check_number(long n)
{
	if(n < 1 || n > MAX_INTEGER)
		return 0;
	return 1;
}

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

void split_string(char *src, char *dst[], char *SEP, int N)
{
	// split string in N parts, separated by SEP
	// place in dst
	char *pch;
	int idx = 0;
//	int N = sizeof(dst) / sizeof(dst[0]);
//	printf(">>> %s\n", src);
	
	pch = strtok (src, SEP);
	while (pch != NULL)
	{
		if (idx > N)
			break;
		dst[idx++] = pch;
		pch = strtok (NULL, SEP);
	}
}

void main(int argc, char *argv[])
{
	// input N and Q
	long N, Q, L, R;
	long i;
//	char *array_input = malloc( MAX_STRING_LENGTH_NQ * sizeof(char) );
	char buff[MAX_STRING_LENGTH_NQ] = {0};
	
	if( fgets(buff, MAX_STRING_LENGTH_NQ, stdin) != NULL )
	{
		correct(&buff[0], MAX_STRING_LENGTH_NQ);
	}

	// split string into N and Q numbers
	char *splitted[2];
	char *delim = {" "};
	
	split_string(buff, splitted, delim, 2);
	
	N = atol(splitted[0]);
	Q = atol(splitted[1]);
	
	if(check_number(N) == 0 || check_number(Q) == 0)
	{
		printf("Error N or Q.\n");
		return;
	}

	// input the array of values
	long MAX_STRING_LENGTH = (N * 10) + N;
//	printf("MAX_STRING_LENGTH %li", MAX_STRING_LENGTH-1);
	
	char *array_string = malloc( MAX_STRING_LENGTH * sizeof(char) );
	char *array_splitted[N];
	long long array_values[N];
	
	if (array_string == NULL)
	{
		printf("Error malloc 1");
		exit (0);
	}
	
	if( fgets(array_string, MAX_STRING_LENGTH, stdin) != NULL )
	{
		correct(&array_string[0], MAX_STRING_LENGTH);
	}
	
	split_string(array_string, array_splitted, delim, N);

	// convert splitted strings into long
	for(i=0; i < N; i++)
	{
		if (i == 0)
			array_values[i] = atoll(array_splitted[i] );
		else
			array_values[i] = atoll(array_splitted[i] ) + array_values[i-1];
//		printf(">> %li\t%s\t%li   \n", i, array_splitted[i], array_values[i]);
	}
	
/*
	for(i=0; i < N; i++)
	{
		printf("%li.\t%lli\n", i, array_values[i]);
	}
*/
	// input Q times queries
	while (Q > 0)
	{
		// input row with L and R
		char bounds[MAX_STRING_LENGTH_NQ] = {0};
		char *bounds_splitted[2];
		
		if( fgets(bounds, MAX_STRING_LENGTH_NQ, stdin) != NULL )
		{
			correct(&bounds[0], MAX_STRING_LENGTH_NQ);
		}
		split_string(bounds, bounds_splitted, delim, 2);
	
		L = atol(bounds_splitted[0]);
		R = atol(bounds_splitted[1]);
		//printf("> L %li\tR %li\n", L, R);
		if (R < L)
		{
			printf("Error R < L\n");
			exit (0);
		}
		//printf(">> %li.\t%lli,%lli\n", Q, array_values[L-1], array_values[R-1]);
		long long subtotal = array_values[R-1];
		if (L > 1)
			subtotal -= array_values[L-1-1];
		
		long average = subtotal / (R - L + 1);
		
		//printf("%li.\t%lli,%li\n", Q, subtotal, average);
		printf("%li\n", average);
		Q--;
	}
	
	// END
	//printf("> END\n");
	
	free(array_string);
}
