def Djikstras(graph, source_vertex):
    visited = [False] * len(graph)  
    distance = [float('inf')] * len(graph)  
    distance[source_vertex] = 0
    while not all(visited):#repeat till visit all  
        min_distance = float('inf')
        current_vertex = -1
        for v in range(len(graph)):
            if not visited[v] and distance[v] < min_distance:
                min_distance = distance[v]
                current_vertex = v
        visited[current_vertex] = True

        for neighbor in range(len(graph)):
            if graph[current_vertex][neighbor] != 0 and not visited[neighbor]:  # Skip non-existing edges
                new_distance = distance[current_vertex] + graph[current_vertex][neighbor]#calc dist from curr vert to adjacent verts
                distance[neighbor] = min(distance[neighbor], new_distance)# update dist list    
    return distance

graph=[
    [0,2,30,5],
    [12,0,11,12],
    [9,4,0,9],
    [10,6,6,0]
    ]
print(Djikstras(graph,0))