'''
# Sample code to perform I/O:

name = input()                  # Reading input from STDIN
print('Hi, %s.' % name)         # Writing output to STDOUT

# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''

# Write your code here
tests = int(input())
if tests < 0 or tests > 100:
  print("ERROR (value)")
  quit()

for n in range(tests):
  try:
    A, B = input().split(' ')
    A, B = list(A), list(B)
    A.sort()
    B.sort()
  except:
    print("ERROR (input)")
    quit()
  
  if A == B:
    print("YES")
  else:
    print("NO")
  
"""
  if (len(A) < 1 or len (A) > 10000 or \
     len(B) < 1 or len(B)> 10000):
    print("NO")
  elif A == B:
    print("YES")
  elif len(A) != len(B):
    print("NO")
  else:
    similar = False
    for n in A:
      for i, c in enumerate(B):
        if n == c:
          similar = True
          del B[i]
          break
        else:
          similar = False
          
      if similar == False:
        print("NO")
        break
        
    if similar:
      print("YES")
"""