from collections import deque


class node:
    childs = []


n, m = input().split()
tree = []
for i in range(int(n)):
    tree.append(node())
for i in range(int(m)):
    tread = input().split()
    id = int(tread[0])
    nod = tree[id - 1]
    nod.childs = tread[2:]

dq = deque()
empty = deque()
dq.append([0, 1])
ans = [0 for i in range(int(n))]
maxlevel = 0
while dq != empty:
    rec = dq.popleft()
    nod = tree[rec[0]]
    nlevel = rec[1]
    if nlevel > maxlevel:
        maxlevel = nlevel
    if nod.childs == []:
        ans[nlevel - 1] += 1
    else:
        for i in nod.childs:
            tid = int(i)
            dq.append([tid - 1, nlevel + 1])
op = ""
for i in range(maxlevel):
    op += str(ans[i]) + " "
print(op[0:-1])
