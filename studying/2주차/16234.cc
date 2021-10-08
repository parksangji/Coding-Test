#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int n,l,r;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};

void bfs(vector<vector<int>>& map,vector<vector<bool>>& visited,int x, int y)
{
    queue<pair<int,int>> q,total_city;
    q.push({x,y});
    total_city.push({x,y});
    visited[x][y] = true;
    int sum = 0, cnt = 0;
    while(!q.empty())
    {
        pair<int,int> city = q.front();
        q.pop();
        sum += map[city.first][city.second];
        cnt ++;

        for(int i=0; i<4; i++)
        {
            int nx = city.first + dx[i];
            int ny = city.second + dy[i];
            if(nx >0 and ny >0 and nx <= n and ny <= n and !visited[nx][ny])
                if(l <= abs(map[nx][ny]-map[city.first][city.second]) and r >= abs(map[nx][ny] - map[city.first][city.second]))
                {
                    visited[nx][ny] = true;
                    q.push({nx,ny});
                    total_city.push({nx,ny});
                }
        }
    }
    int value = sum / cnt;
    while(!total_city.empty())
    {
        map[total_city.front().first][total_city.front().second] = value;
        total_city.pop();
    }
}

int main(void)
{

    cin >> n >> l >> r;
    queue<pair<int,int>> q;
    vector<vector<int>> map (n+1,vector<int>(n+1));
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            cin >> map[i][j];
        }
    int day = 0;
    bool flag = true;
    while(flag)
    {
        vector<vector<bool>> visited(n+1,vector<bool>(n+1));
        flag = false;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n ; j++)
                if(!visited[i][j])
                    for(int k=0; k<4; k++)
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        if(nx >0 and ny >0 and nx <= n and ny <= n)
                            if(l <= abs(map[nx][ny]-map[i][j]) and r >= abs(map[nx][ny] - map[i][j]))
                            {
                                flag = true;
                                bfs(map,visited,i,j);
                                break;
                            }
                    }
        if(flag == true) day++;
    }

    cout << day;
}