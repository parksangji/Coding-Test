#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct info
{
    int x,y,mass,speed,dir;
};

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(void)
{
    int n,m,k;
    cin >> n >> m >> k;

    vector<info> fireball;
    vector<info> matrix[n+1][n+1];
    for(int i=0; i< m; i++)
    {
        int R,C,M,S,D;
        cin >> R >> C >> M >> S >> D;
        fireball.push_back({R,C,M,S,D});
    }
    while(k--)
    {
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n ; j++) matrix[i][j].clear();

        for(auto f : fireball)
        {
            int nx = (f.x + dx[f.dir] * f.speed) % n;
            int ny = (f.y + dy[f.dir] * f.speed) % n;
            if(nx <1) nx += n;
            if(ny <1) ny += n;
            matrix[nx][ny].push_back({nx,ny,f.mass,f.speed,f.dir});
        }
        fireball.clear();
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                if(matrix[i][j].size() == 1) 
                    fireball.push_back(matrix[i][j].front());
                else if(matrix[i][j].size() >= 2)
                {
                    int mass = 0,speed = 0;
                    bool odd = true,even = true;
                    for(auto f : matrix[i][j])
                    {
                        mass += f.mass;
                        speed += f.speed;

                        if(f.dir % 2 == 0 ) odd = false;
                        else even = false;
                    }

                    mass /= 5;
                    speed /= matrix[i][j].size();

                    if(mass == 0) continue;

                    if(odd or even) for(int t=0; t<4; t++) fireball.push_back({i,j,mass,speed,t*2});
                    else for(int t=0; t<4; t++) fireball.push_back({i,j,mass,speed,t*2 + 1});
                }
            }
    }
    int answer = 0;
    for(auto f : fireball) answer += f.mass;
    cout << answer;
}