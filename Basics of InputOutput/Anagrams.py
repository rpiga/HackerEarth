'''
# Sample code to perform I/O:

name = input()                  # Reading input from STDIN
print('Hi, %s.' % name)         # Writing output to STDOUT

# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''

# Write your code here
tests = int(input())
cond = False


for n in range(tests):
  while cond == False:
    string_a = list(input())
    string_b = list(input())
    if (len(string_a) > 0 and len(string_a) <= 10000) and \
       (len(string_b) > 0 and len(string_b) <= 10000):
      cond = True
  cond = False
  
  count = 0
  total = len(string_a) + len(string_b)
  for n in string_a:
    for i, c in enumerate(string_b):
      if n == c:
        count += 1
        del string_b[i]
        break
  
  print(total - 2*count)