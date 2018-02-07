'''
# Sample code to perform I/O:

name = input()                  # Reading input from STDIN
print('Hi, %s.' % name)         # Writing output to STDOUT

# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''

# Write your code here
values_in = input().split()

try:
  L, R, K = int(values_in[0]), int(values_in[1]), int(values_in[2])
except:
  print("ERROR (input)")
  quit()

if (L < 1 or L > R) or (R < L or R > 1000) or (K < 1 or K > 1000):
  print("ERROR (values)")
  quit()
  
count = 0
for n in range(L, R+1):
  count+=1 if (n%K== 0) else False
  
print(count)