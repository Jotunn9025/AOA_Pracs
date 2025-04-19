def floydWarshall(graph):
    V = len(graph)
    for k in range(V):
        for i in range(V):
            for j in range(V):
                if(graph[i][k] != float("inf") and graph[k][j]!= float("inf")):
                    graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j])
                    
inf=float("inf")
graph=[
    [0  , 5  , inf, 10,  inf, inf],
    [inf, 0  , 3  , inf, inf, inf],
    [inf, inf, 0  , 1  , 8  , inf],
    [inf, inf, inf, 0  , inf, 2  ],
    [inf, inf, inf, 4  , 0  , inf],
    [inf, inf, inf, inf, 6  , 0  ]
]
floydWarshall(graph)
print([[val for val in row]for row in graph])