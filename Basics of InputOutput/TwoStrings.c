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

#define STR_LENGTH_MAX 10000

void correct(char *str_in)
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

  if (strlen(str_in) == STR_LENGTH_MAX-1 )
    while((ch = getchar())!='\n'  && ch != EOF  );
}

int main(int argc, char *argv[])
{
  int tests;
  char str_buf[STR_LENGTH_MAX+1], buf[4];
	char *pch; // pointer for strtok()
	char *strings[2];
	int idx = 0, i, j, f;
  
  do
  {
    fgets(buf, 4, stdin);
    correct(&buf[0]);
    tests = atoi(buf);
  } while (tests < 1 || tests > 100);

	while (tests > 0)
	{
		// input strings
		if (fgets(str_buf, STR_LENGTH_MAX, stdin) != NULL)
		{
			correct(&str_buf[0]);
		}
		//printf("%s ", str_buf); // DEBUG
			
		// split string in two parts, separated by space
		idx = 0;
		pch = strtok (str_buf, " ");
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
		

		// check size of strings. If differ, they're not the same
		// and check if strings are equals
		if (idx != 2)
			printf("NO\n");
		else if ( strlen(strings[0]) != strlen(strings[1]) )
			printf("NO\n");
		else if ( strcmp (strings[0], strings[1]) == 0 )
			printf("YES\n");
		else
		{	
			f = 0; // initialize "found" flag
			for (i = 0; i < strlen(strings[0]); i++)
			{
				for (j = 0; j < strlen(strings[1]); j++)
				{
					// printf("%s %c %s\n", strings[0], (char) strings[0][i], strings[1]); // DEBUG
					if(strings[0][i] == strings[1][j])
					{
						f = 1;
						strings[1][j] = ' ';
						break;
					}
					else
					{
						f = 0;
					}
				}
				
				if (f != 1)
				{
					printf("NO\n");
					break;
				}
			}
			if (f == 1)
				printf("YES\n");
		}

		tests--;
	}
  
  return 0;
}