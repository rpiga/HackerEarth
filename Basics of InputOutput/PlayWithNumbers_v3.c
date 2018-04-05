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

#define STR_INPUT_MAX 15
#define NUM_LIMIT_1 1000000
#define NUM_LIMIT_2 1000000000

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

void split_string(char *string_in, int N, char *array_out[], char *SEP)
{
	// split string in N parts, separated by SEP
	// place in array_out
	char *pch;
	int idx = 0;
	
//	printf(">>> %s\n", string_in);
	
	pch = strtok (string_in, SEP);
	while (pch != NULL)
	{
		if (idx > N)
		{
			printf("Error 1.\n");
			break;
		}
		array_out[idx++] = pch;
		pch = strtok (NULL, SEP);
	}
}
	
int main(int argc, char *argv[])
{
	int Q, N, L, R, idx;
	long unsigned result;
	char buf[STR_INPUT_MAX];
	char *values_in[2];
	char *delim = {" "};
	char *pch;
	
	if( fgets(buf, STR_INPUT_MAX+1, stdin) != NULL )
	{
		correct(&buf[0], STR_INPUT_MAX);
	}

	split_string(buf, 2, values_in, delim);
	
	N = atoi(values_in[0]);
	Q = atoi(values_in[1]);
	
	if( (N < 1 || N > NUM_LIMIT_1) || (Q < 1 || Q > NUM_LIMIT_1) )
	{
		printf("Error Q and N values.\n");
		return 0;
	}
	
	// input the array of N Elements
	int N_STRING_MAX = N * 10 + (N - 1);
	char array_string[N_STRING_MAX];
	int array_values[N];
	
	if( fgets(array_string, N_STRING_MAX+1, stdin) != NULL )
	{
		correct(&array_string[0], N_STRING_MAX+1);
	}
	
	// convert string in an array of values
	pch = strtok (array_string, " ");
	while (pch != NULL)
	{
		array_values[idx++] = atoi(pch);
		pch = strtok (NULL, " ");
	}

	// run Q queries to input L and R
	char *query_bounds[2];
	
	while (Q > 0)
	{
		if( fgets(buf, STR_INPUT_MAX+1, stdin) != NULL )
		{
			correct(&buf[0], STR_INPUT_MAX);
		}
		
		split_string(&buf[0], 2, query_bounds, delim);
		
		L = atoi( query_bounds[0] );
		R = atoi( query_bounds[1] );
		
		if (L > R)
		{
			printf("Error L > R.\n");
			return 0;
		}
		result = 0;
		idx = L-1;
		
		while(idx < R)
		{
			printf("idx %d\n", idx);
			result += array_values[idx++];
			//idx++;
		}
		result = result / (R-L+1);
		
		printf("%lu\n", result);
		Q--;
	}
	
	return 0;

}


