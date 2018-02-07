'''
# Sample code to perform I/O:

name = input()                  # Reading input from STDIN
print('Hi, %s.' % name)         # Writing output to STDOUT

# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''

# Write your code here
N = int(input())

if N < 1 or N > 1000:
  print("Error (N).")
  quit()


for n in range(2,N):
  is_prime = True
  for m in range(2,n):
    if n%m == 0:
      is_prime = False
      break
      
  if is_prime: print(n, sep=' ', end=' ', flush=True)
