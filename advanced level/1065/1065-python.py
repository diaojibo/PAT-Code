import decimal
t = int(raw_input())
tag = ""
for i in range(t):
  x,y,z = raw_input().split()
  x,y,z = decimal.Decimal(x),decimal.Decimal(y),decimal.Decimal(z)
  if x+y>z:
    tag = "true"
  else:
    tag = "false"
  print("Case #"+str(i+1)+": "+tag)