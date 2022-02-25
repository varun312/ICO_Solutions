a = 2
dict = {}

def recursiveFill(i, j, array, isRoot):
    global a
    array[i][j] = a
    if isRoot:
        dict[a] = 1
    if array[i+1][j] == 0:
        array = recursiveFill(i+1, j, array, False)
        dict[a] = dict[a] + 1
    if array[i-1][j] == 0:
        array = recursiveFill(i-1, j, array, False)
        dict[a] = dict[a] + 1
    if array[i][j+1] == 0:
        array = recursiveFill(i, j+1, array, False)
        dict[a] = dict[a] + 1
    if array[i][j-1] == 0:
        array = recursiveFill(i, j-1, array, False)
        dict[a] = dict[a] + 1
    if isRoot:
        a += 1
    return(array)

m,n = map(int, input().split())
arr = []
for i in range(m):
    tmparr = list(map(int, input().split()))
    arr.append(tmparr)

for i in range(m):
    for j in range(n):
        if arr[i][j]==0:
            arr = recursiveFill(i, j, arr, True)

print(len(dict))
max = 0
for i in dict.values():
    if i>max:
        max = i

print(max)