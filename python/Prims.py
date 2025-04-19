import sys
graph=[]
n=int(input("How many vertices does your graph have"))
print("Please input adjacency matrix putting a newline after each row and a space b/w values")
for _ in range(n):
    row = list(map(int, input().split()))
    graph.append(row)

selected = [False] * n
ne = 0  

def prim(n):
    selected[0] = True
    global ne
    cost=0
    print("MST Edges:")
    while ne < n-1:
        minimum = sys.maxsize
        x = -1
        y = -1

        for i in range(5):
            if selected[i]:#check for edges connected to current mst(initially source node only)
                for j in range(5):
                    if not selected[j] and graph[i][j] and graph[i][j] < minimum:#smallest connected edge
                        minimum = graph[i][j]
                        x = i
                        y = j
        
        if x != -1 and y != -1:#if we found a value
            print(f"{x} - {y} : {graph[x][y]}")#print connecting edge
            selected[y] = True#set visited true
            ne += 1#number of edges+=1
            cost+=graph[x][y]
    print(f"Cost of MST: {cost}")
prim(n)