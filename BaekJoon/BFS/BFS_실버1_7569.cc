#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>

using namespace std;

struct pos
{
    int x;
    int y;
    int z;
    int count;
};

int dx[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {0,0,0,0,1,-1};

int main(void)
{
    ios::sync_with_stdio(NULL);
	cin.tie(NULL);
    int N,M,H,answer = 0;
    cin >> N >> M >> H;
    vector<vector<vector<bool>>> visited(M,vector<vector<bool>>(N,vector<bool>(H,false)));
    queue<pos> q;
    for(int k = 0; k< H; k++)
        for(int i=0; i< M ; i++)
            for(int j=0,input; j<N; j++)
            {
                cin >> input;
                if(input == 1)  
                {
                    visited[i][j][k] = true;
                    q.push({i,j,k,0});
                }
                if(input == -1) visited[i][j][k] = true;
            }
    if(q.empty())
    {
        cout << -1;
        return 0;
    }
    while(!q.empty())
    {
        pos p = q.front();
        q.pop();
        answer = max(answer,p.count);
        for(int i=0; i<6; i++)
        {
            int x = p.x + dx[i];
            int y = p.y + dy[i];
            int z = p.z + dz[i];
            if(x >= 0 and y >= 0 and z >= 0 and x < M and y < N and z < H and !visited[x][y][z])
            {
                visited[x][y][z] = true;
                q.push({x,y,z,p.count + 1});
            }
        }
    }
    for(int k=0; k<H; k++)
        for(int i=0; i<M; i++)
            for(int j=0; j<N; j++)
                if(!visited[i][j][k]) 
                {
                    cout << -1;
                    return 0;
                }
    cout << answer ;
    return 0;
}