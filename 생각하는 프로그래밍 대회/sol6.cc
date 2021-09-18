#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int dx[] = {-2,-1,1,2,-2,-1,1,2};
int dy[] = {1,2,2,1,-1,-2,-2,-1};

queue<pair<int,int>> back;

void dfs(vector<vector<bool>>& visited,int x,int y,int depth)
{
    if(depth >= 2 *visited.size()*visited.size()) return;

    for(int i=0; i<8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >=1 and ny >=1 and nx < visited.size() and ny < visited.size() and !visited[nx][ny])
        {
            visited[nx][ny] = true;
            back.push({nx,ny});
            dfs(visited,nx,ny,depth+1);
        }
    }
}

int main(void)
{
    int n,x,y;
    cin >> n >> x >> y;
    vector<vector<bool>> visited(n+1,vector<bool>(n+1,false));
    visited[x][y] = true;
    back.push({x,y});
    dfs(visited,x,y,0);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(visited[i][j] == false) 
            {
                cout << -1;
                return 0;
            }
    
    cout << back.size() << "\n";
    while(!back.empty())
    {
        cout << back.front().first << " " << back.front().second  << "\n";
        back.pop();
    }
}