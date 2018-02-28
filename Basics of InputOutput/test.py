for _ in range(int(input())):
  s1,s2 = (sorted(s) for s in input().split())
  print(['NO','YES'][s1==s2])