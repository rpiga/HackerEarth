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

void split_string(char *string_in, int N, char *array_out[])
{
	// split string in n parts, separated by space
	// array_in
	// n
	// array_out
	char *pch;
	int idx = 0;
	
//	printf(">>> %s\n", string_in);
	
	pch = strtok (string_in, " ");
	while (pch != NULL)
	{
		if (idx > N)
		{
			printf("Error 1.\n");
			break;
		}
		array_out[idx++] = pch;
		pch = strtok (NULL, " ");
	}
}
	
int main(int argc, char *argv[])
{
	char buf[STR_INPUT_MAX];
	// DELETE char appo[100];
	int input_flag = 0, idx = 0;
	char *strings[2], *pch;
	int N, Q, L, R;
	
	// input (N)umber of array elements and number of (Q)ueries
	while (input_flag == 0)
	{
		if( fgets(buf, STR_INPUT_MAX+1, stdin) != NULL )
		{
			correct(&buf[0], STR_INPUT_MAX);
		}
		
		// split string in two parts, separated by space
/*		pch = strtok (buf, " ");
		while (pch != NULL)
		{
			if (idx > 1)
			{
				printf("Error 1.\n");
				return 0;
			}
			strings[idx++] = pch;
			pch = strtok (NULL, " ");
		}
*/	
		split_string(&buf[0], 2, strings);
		N = atoi(strings[0]);
		Q = atoi(strings[1]);
		
		if( (N >= 1 && N <= NUM_LIMIT_1) && (Q >= 1 && Q <= NUM_LIMIT_1) )
			input_flag = 1;
		else
		{
			idx = 0;
			printf("Error.\n");
		}
	}

	// input the array of N Elements
	int N_STRING_MAX = N * 10 + (N - 1);
	char array_string[N_STRING_MAX];
	
	if( fgets(array_string, N_STRING_MAX+1, stdin) != NULL )
	{
		correct(&array_string[0], N_STRING_MAX+1);
	}
	
	// put the string into an array
	char *array_values[N];
	split_string(&array_string[0], N, array_values);
	
	// input the (Q)ueries
	char *query_bound[2];
	
	while (Q > 0)
	{
		if( fgets(buf, STR_INPUT_MAX+1, stdin) != NULL )
		{
			correct(&buf[0], STR_INPUT_MAX);
		}
		
		split_string(&buf[0], 2, query_bound);
		
		L = atoi( query_bound[0] );
		R = atoi( query_bound[1] );
		printf("== %d %d\n", L, R);
		
		if (L > R)
		{
			printf("Error: L > R.\n");
			return 0;
		}
		
		// walk throuhg the array_string and get only the needed values
		int idx = 0, result = 0;

		printf("RES %d %s\n", result, array_string);
		pch = strtok (array_string, " ");
		while (pch != NULL)
		{
			if (idx >= (L-1) && idx <= (R-1))
			{
				result += atoi(pch);
				printf("PART %d %d\n", atoi(pch), result);
			}
			pch = strtok (NULL, " ");
			idx++;
		}
		result = result / (R-L+1);
		
/*		
		for ( c = L; c < R; c++)
		{
			val +=
		}
*/		
		Q--;
	}
}
