from collections import deque
import sys
read = sys.stdin.readline

def dfs(v):
    visited[v] = 1
    print(v, end = " ")
    for i in range(1,n+1) :
        if(visited[i] == 0 and graph[v][i] == 1) :
            dfs(i)

def bfs(v):
    visited2[v] = 1
    q = deque()
    q.append(v)
    while q :
        v = q.popleft()
        print(v, end = " ")
        for i in range(1, n+1) :
            if(visited2[i] == 0 and graph[v][i] == 1) :
                q.append(i)
                visited2[i] = 1


n,m,v = map(int, read().split())

graph = [[0] * (n+1) for _ in range(n+1)]
visited = [False] * (n+1)
visited2 = [False] * (n+1)
for _ in range(m) :
    a, b = map(int, read().split())
    graph[a][b] = graph[b][a] = 1

dfs(v)
print()
bfs(v)

