'''
# Sample code to perform I/O:

name = input()                  # Reading input from STDIN
print('Hi, %s.' % name)         # Writing output to STDOUT

# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''

# Write your code here
#values_in = input().split()

tests = int(input())

def return_prime(n):
  if n < 67:
    return 67
  if n > 113:
    return 113
  
  primes = [67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113]
  
  if n in primes:
    return n
  else:
    lowest = 128
    for i,c in enumerate(primes):
      if abs(n - c) < lowest:
        lowest = abs(n - c)
        answer = c
        
      #print(i, c, abs(n - c) )
      
  return answer
  

def is_prime(n):
  for m in range(2,n):
    if n%m == 0:
      return False

  return True

for t in range(tests):
  S = int(input())
  word = list(input())
  
  for i in range(S):
    w = word[i]
    print(chr(return_prime(ord(w)) ), end='')
  print()
#    print("> ", w, ord(w))
    
  
  