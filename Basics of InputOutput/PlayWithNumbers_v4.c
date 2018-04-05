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
#include <math.h>

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
	long Q, N, idx, c, i;
	long min, max, L, R;
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
	char array_string[N_STRING_MAX]; //, array_string_cpy[N_STRING_MAX];
	long array_values[N_STRING_MAX];

printf(">OK %li %li %li\n", sizeof(N_STRING_MAX), sizeof(array_string), sizeof(array_values));
return 0;	

	if( fgets(array_string, N_STRING_MAX+1, stdin) != NULL )
	{
		correct(&array_string[0], N_STRING_MAX+1);
	}
	
	char *ptr;
	ptr = array_string;
	c = 0;
	while(*ptr)
	{
		char *end;
		long nu = strtol(ptr, &end, 10);
		array_values[c++] = nu;
		while (*end == ' ') end++;
		ptr = end;
	}

	// run Q queries to input L and R
	char *query_bounds[2];
	while (Q > 0)
	{
		if( fgets(buf, STR_INPUT_MAX+1, stdin) != NULL )
		{
			correct(&buf[0], STR_INPUT_MAX);
		}
		//printf("buf %s ", buf);
		split_string(&buf[0], 2, query_bounds, delim);
		
		L = atoi( query_bounds[0] );
		R = atoi( query_bounds[1] );
		
		if (L > R)
		{
			printf("Error L > R. (%li: %li,%li %s)\n", Q, L, R, buf);
			return 0;
		}
		
		double total =0, average=0;
		long c = 1;
		for (i = L-1; i<R; i++)
		{
			total += array_values[i];
			average = total /c++;
			//printf("> %lu %d\n", array_values[i], (int) average);
		}
		printf("%d\n", (int) average);
		Q--;
	}
//	printf(">OK %s\n", array_string);
	return 0;
	
}
/*
			printf("%d %lu\n",c, nu);
			while (*ptr == ' ')
			{
				ptr++;
			}
	long nu;
	
	for(i = 0; i < N; i++)
	{
		nu = strtol(array_string, &ptr, 10);
		printf("a.%s b.%s c.%lu\n", array_string, ptr, nu);	
	}

*/	
/*
	//printf("> %s\n\n", array_string);
	// populate array_values
	idx = 0;
	pch = strtok(array_string, " ");
	while (pch != NULL)
	{
		printf("idx pre %li\n", idx);
		array_values[idx++] = atoi(pch);
		pch = strtok(NULL, " ");
		printf("idx post %li\n", idx);
	}
	
	

	
	return 0;

}
/*		
		double result = 0;
		double average = 0;
		c = 1;
//		printf("L %lu R %lu\n", L, R );
		for (i=L-1; i<R; i++)
		{
			//printf("> %lu\n", array_values[i]);
			result += array_values[i];
			average = result / c;
/*			if (c < 3)
			{
				average += array_values[i];
				average /= c;
			}
			else
			{
				result = (array_values[i] - average) / c;
				average += result;
			}
			//printf("%d %li \tres %li\tavg %lu \n", c, array_values[i], result, average);
			c++;
		}
		
		printf("> %lu\n", (long) average);	
		Q--;
	}
	

		strcpy(array_string_cpy, array_string);
		idx = 0;
		result = 0;
		
		pch = strtok(array_string_cpy, " ");
		while (pch != NULL)
		{
			if(idx >= L-1 && idx <R)
			{
				printf("%s\n", pch);
				result += atoi(pch);
			}
			pch = strtok(NULL, " ");
			idx++;
		}
// -----------------		
		// convert string in an array of values
		idx = 0;
		c = 0;
		
		pch = strtok (array_string, " ");
		while (pch != NULL)
		{
			if(idx >= L && idx <=R)
			{
				c++;
				result += (atoi(pch) / c);
			}
			//array_values[idx++] = atoi(pch);
			pch = strtok (NULL, " ");
			idx++;
		}

// --------------
int average = 0;
		result = 0;
		idx = L-1;
		min = NUM_LIMIT_2;
		max = 0;
		c = 1;
				
		while(idx < R)
		{
			if (c < 3)
			{
				average += array_values[idx] / c; 
			}
			else
			{
				result = (array_values[idx] - average) / c;
				average += result;
			}
			//printf("%d avg %d\n", c, average);
			c++;
			idx++;
		}
		printf("%lu\n", average);
		
		
		
		while(idx < R)
		{
//			printf("%d %d", (R-L+1));
			if (array_values[idx] < min)
				min = array_values[idx];
			if (array_values[idx] > max)
				max = array_values[idx];
			idx++;
			c++;
//			printf("idx %d\n", idx);
			result += array_values[idx++] / c;
			c++;
		}
		//result = result / (R-L+1);
		//printf("min %lu max %lu\n", min, max);
//		result = result / (R-L+1);
*/		


