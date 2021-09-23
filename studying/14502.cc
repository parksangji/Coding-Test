#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int answer = 0;
void bfs(vector<vector<int>> matrix)
{
    queue<pair<int,int>> q;
    for(int i=0; i< matrix.size(); i++) 
        for(int j=0; j<matrix[i].size(); j++) 
            if(matrix[i][j] == 2) q.push({i,j});

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i< 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >=0 and ny >=0 and nx < matrix.size() and ny < matrix[0].size() and matrix[nx][ny] == 0)
            {
                matrix[nx][ny] = 2;
                q.push({nx,ny});
            }
        }
    }
    int cnt = 0;
    for(int i=0 ;i< matrix.size(); i++)
        for(int j=0; j<matrix[i].size(); j++)
            if(matrix[i][j] == 0) cnt++;
    answer = max(cnt,answer);
}

void dfs(vector<vector<int>>& matrix,int x,int y,int wall)
{
    if(wall == 3) 
    {
        bfs(matrix);
        return;
    }

    for(int i=0; i<matrix.size(); i++)
        for(int j=0; j<matrix[i].size(); j++)
        {
            if(matrix[i][j] == 0)
            {
                matrix[i][j] = 1;
                dfs(matrix,i,j,wall + 1);
                matrix[i][j] = 0;
            }
        }
}

int main(void)
{
    int n,m;
    cin >> n >> m;

    vector<vector<int>> matrix (n,vector<int>(m,0));
    for(int i=0 ;i < n ; i++)
        for(int j=0; j< m ; j++)
            cin >> matrix[i][j];
    for(int i=0; i< n; i++)
        for(int j=0; j< m; j++)
            if(matrix[i][j] == 0)
            {
                matrix[i][j] = 1;
                dfs(matrix,i,j,1);
                matrix[i][j] = 0;
            }
    cout << answer;
}