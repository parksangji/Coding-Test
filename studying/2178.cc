#include<iostream>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

char matrix[101][101] = {0,};
int answer[101][101] = {0,};
bool visited[101][101] = {false,};
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main(void)
{
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n ;i++)
    {
        string a;
        cin >> a;
        for(int j=1; j<=m ;j++) 
        {
            matrix[i][j] = a[j] - '0';
        }
    }
    visited[1][1] = true;
    queue<pair<int,int>> q;
    q.push({1,1});

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x == n and y == m) break;
        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 and ny >= 0 and nx <= n and nx <= m and !visited[nx][ny] and matrix[nx][ny] == 1)
            {
                visited[nx][ny] = true;
                answer[nx][ny] = answer[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }
    cout << answer[n][m];
}