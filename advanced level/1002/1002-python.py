maxk = 1001
na = input().split()
nb = input().split()
ka, kb = int(na[0]), int(nb[0])
ans = [0 for i in range(maxk)]
for i in range(ka):
    id = (i + 1) * 2 - 1
    ans[int(na[id])] += float(na[id + 1])
for i in range(kb):
    id = (i + 1) * 2 - 1
    ans[int(nb[id])] += float(nb[id + 1])
num = 0
temp = ""
for i in range(maxk):
    j = maxk - i - 1
    if ans[j] != 0:
        num += 1
        temp += str(j) + " " + "%.1f"%ans[j] + " "
if temp != "":
    temp = temp[:-1]
op = str(num) + " " + temp
if op[-1] == " ":
    op = op[:-1]
print(op)
