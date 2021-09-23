#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void dfs(vector<vector<int>> matrix, vector<bool>& visited, int cur)
{

    visited[cur] = true;
    cout << cur << " ";

    for(int i =1; i<visited.size(); i++)
    {
        if(!visited[i] and matrix[cur][i] == 1)
        {
            dfs(matrix,visited,i);
        }
    }
}
void bfs(vector<vector<int>> matrix,vector<bool>& visited,int start,int n)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for(int i=1; i<= n ; i++)
        {
            if(!visited[i] and matrix[cur][i] == 1)
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
int main(void)
{
    int n,m,v;
    cin >> n >> m >> v;
    vector<vector<int>> matrix(1001,vector<int>(1001,0));
    vector<bool> visited(1001,false);
    for(int i=0; i<m; i++) 
    {
        int v1,v2;
        cin >> v1 >> v2;
        matrix[v1][v2] = 1;
        matrix[v2][v1] = 1;
    } 
    dfs(matrix,visited,v);
    cout << "\n";
    visited.assign(n+1,false);
    bfs(matrix,visited,v,n);
}