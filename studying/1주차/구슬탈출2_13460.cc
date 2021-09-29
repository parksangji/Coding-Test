#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

struct redblue
{
    int rx,ry,bx,by;
    int d;
};

const int dx[] = {0,-1,1,0};
const int dy[] = {-1,0,-0,1};

void move(vector<vector<char>> matrix,int& x,int& y,int& c,int i)
{
    while(matrix[x+dx[i]][y+dy[i]] != '#' and matrix[x][y] != 'O')
    {
        x+= dx[i];
        y+= dy[i];
        c += 1;
    }
}

int main(void)
{
    int n,m;
    cin >> n >> m;
    vector<vector<char>> matrix(n+1,vector<char>(m+1,0));
    pair<int,int> red,blue;
    for(int i=0; i<n; i++)
    {
        string input;
        cin >> input;
        for(int j=0; j<input.length(); j++) 
        {
            matrix[i][j] = input[j];
            if(matrix[i][j] == 'R') red = {i,j};
            if(matrix[i][j] == 'B') blue = {i,j};
        }
    }
    queue<redblue> q;
    bool visited[n+1][m+1][n+1][m+1];
    q.push({red.first,red.second,blue.first,blue.second,0});
    visited[red.first][red.second][blue.first][blue.second] = true;
    while(!q.empty())
    {
        int rx = q.front().rx;
        int ry = q.front().ry;
        int bx = q.front().bx;
        int by = q.front().by;
        int d= q.front().d;
        q.pop();

        if(d >= 10) break;

        for(int i=0; i<4; i++)
        {
            int nrx = rx,nry = ry,nbx = bx,nby = by,nd = d+1;
            int rc =0,bc = 0;

            move(matrix,nrx,nry,rc,i);
            move(matrix,nbx,nby,bc,i);

            if(matrix[nbx][nby] == 'O') continue;
            if(matrix[nrx][nry] == 'O') 
            {
                cout << nd;
                return 0;
            }

            if(nrx == nbx and nry == nby)
            {
                if(rc > bc) nrx -= dx[i],nry -= dy[i];
                else nbx -= dx[i], nby -=dy[i];
            }
            
            if(!visited[nrx][nry][nbx][nby])
            {
                visited[nrx][nry][nbx][nby] = true;
                q.push({nrx,nry,nbx,nby,nd});
            } 
        }
    }
    cout << -1;
    return 0;
}