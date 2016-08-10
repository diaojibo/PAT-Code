n,m,c1,c2 = raw_input().split()
hands = raw_input().split()
n,m,c1,c2 = int(n),int(m),int(c1),int(c2)
map = [[-1 for i in range(n)] for j in range(n)]
for i in range(m):
  x,y,length = raw_input().split()
  map[int(x)][int(y)] = int(length)
  map[int(y)][int(x)] = int(length)
def dij(source,target):
  parent = [[] for i in range(n)]
  isVisited = [False for i in range(n)]
  isVisited[source] = True
  dest = [map[source][i] for i in range(n)]
  dest[source] = 0
  pathcount = [0 for i in range(n)]
  amount = [0 for i in range(n)]
  # print map
  # print hands
  for i in range(n):
      if map[source][i] != -1:
        parent[i].append(source)
        amount[i] = int(hands[source])+int(hands[i])
        pathcount[i] = 1
  for i in range(n-1):
    min = -1
    for j in range(n):
      if (not isVisited[j]) and (dest[j]!=-1):
        if min==-1 or dest[j]<dest[min]:
          min = j
    isVisited[min] = True
    for j in range(n):
      if map[min][j]!=-1:
        if dest[j] == -1 or dest[min]+map[min][j]<=dest[j]:
          if dest[j] == dest[min]+map[min][j]:
            parent[j].append(min)
            pathcount[j] += pathcount[min]
            if amount[min] + int(hands[j]) > amount[j]:
              amount[j] = amount[min] + int(hands[j])
          else:
            parent[j] = [min]
            pathcount[j] = pathcount[min]
            amount[j] = amount[min] + int(hands[j])
          dest[j] = dest[min]+map[min][j]
  return parent,dest[target]
  # print (pathcount)
  # print (amount)
parents,sp = dij(c1,c2)
max = -1
num = 0
st = []
st.append([c2,0])
while st != []:
  now = st.pop()
  nc = now[0]
  handnum = now[1] + int(hands[nc])
  if(nc == c1):
    num += 1
    if handnum>max:
      max = handnum
  else:
    for i in parents[nc]:
      st.append([i,handnum])
print(str(num)+" "+str(max))