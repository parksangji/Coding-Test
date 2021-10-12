#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int dx[] = {0,-1,1,0};
const int dy[] = {-1,0,0,1};
int min_dist = INT32_MAX;

struct  shark
{       
    int x;
    int y;
    int time;
};

void bfs(vector<vector<int>>& map,shark s,vector<shark>& v)
{
    queue<pair<int,int>> q;
    min_dist = INT32_MAX;
    v.clear();
    vector<vector<int>> visited(map.size(),vector<int>(map.size()));
    q.push({s.x,s.y});

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >=0 and ny >= 0 and nx < map.size() and ny < map.size() and !visited[nx][ny])
            {
                visited[nx][ny] = visited[nx][ny] + 1;
                if(map[nx][ny] > 0 and map[nx][ny] < s.time)
                {
                    if(min_dist >= visited[nx][ny])
                    {
                        min_dist = visited[nx][ny];
                        v.push_back({nx,ny,min_dist});
                    }
                }
                q.push({nx,ny});
            }
        }
    }
}


int main(void)
{
    int n;
    cin >> n;
    vector<vector<int>> map(n,vector<int>(n,0));
    shark s;
    for(int i=0; i<n; i++) 
        for(int j=0; j<n ;j++) 
        {
            cin >> map[i][j];
            if(map[i][j] == 9)
            {
                s = {i,j,0};
                map[i][j] = 0;
            }
        }

    vector<shark> v;
    int answer =0;
    while(1)
    {
        bfs(map,s,v);
        if(v.empty()) break;
        else
        {
            sort(v.begin(),v.end());
            answer++;
        }
    }
    
}