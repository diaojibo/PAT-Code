import decimal
n = int(raw_input())
numbers = raw_input().split()
def judge(num,tags):
  if num=="":
    return True
  if num.isdigit():
    t = int(num)
    if t<=1000:
      return True
    else:
      return False
  else:
    if num[0]=="-":
      if not tags:
        return False
      return judge(num[1:],False)
    parts = num.split(".")
    if len(parts)==2:
      ndec = len(parts[1])
      if ndec>2:
        return False
      if(not ((parts[0].isdigit()or parts[0]=="") and (parts[1].isdigit()or parts[1]==""))):
        return  False
      return (((judge(parts[0],tags)or parts[0]=="")and (judge(parts[1],tags)or parts[1]=="")))
  return False

total = 0
nt = 0
for i in range(n):
  if judge(numbers[i],True)and(float(numbers[i])<=1000 and float(numbers[i])>=-1000):
    total += float(numbers[i])
    nt += 1
  else:
    print("ERROR: "+numbers[i]+" is not a legal number")
if(nt==0):
  print("The average of 0 numbers is Undefined")
else:
  fushu = "numbers"
  if nt==1:
    fushu = "number"
  print("The average of "+str(nt)+" "+fushu+" is "+"{:.2f}".format(decimal.Decimal(total/nt+0.0001)))