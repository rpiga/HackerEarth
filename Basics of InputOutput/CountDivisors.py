'''
# Sample code to perform I/O:

name = input()                  # Reading input from STDIN
print('Hi, %s.' % name)         # Writing output to STDOUT

# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''

# Write your code here
values_in = input().split()

try:
  L, R, K = values_in[0], values_in[1], values_in[2]
  print("ok")
except:
  print("ERROR")

