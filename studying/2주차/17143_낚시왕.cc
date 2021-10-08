#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct shark
{
    int speed;
    int dir;
    int size;
};

struct info
{
    int x,y,speed,dir,size;
};

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

vector<shark> board[101][101];

int main(void)
{
    int r,c,m;
    cin >> r >> c >> m;
    for(int i=0; i<m; i++)
    {
        int r,c,s,d,z;
        cin >> r >> c >> s >> d >> z;
        shark tmp = {s,d-1,z};
        board[r][c].push_back(tmp);
    }
    int time =0;
    int answer = 0;

    for(int t=0; t<c; t++)
    {
        time++;

        for(int i=1; i<=r; i++)
        {
            if(board[i][time].empty()) continue;

            answer += board[i][time].front().size;
            board[i][time].clear();
            break;
        }

        queue<info> q;

        for(int i=1; i<=r; i++)
        {
            for(int j=1; j<=c; j++)
            {
                if(!board[i][j].empty())
                {
                    int x= i;
                    int y =j;
                    int s = board[i][j].front().speed;
                    int z = board[i][j].front().size;
                    int d = board[i][j].front().dir;
                    q.push({x,y,s,d,z});
                    board[i][j].clear();
                }
            }
        }
        while(!q.empty())
        {
            int x = q.front().x;
            int y = q.front().y;
            int s = q.front().speed;
            int z = q.front().size;
            int d = q.front().dir;
            q.pop();

            for(int i=0; i<s; i++)
            {
                if(d == 0 or d == 1)
                {
                    int nx = x + dx[d];
                    if(!(nx>=1 and nx <=r)) d = 1- d;
                    x += dx[d];
                }
                else
                {
                    int ny = y + dy[d];
                    if(!(ny>=1 and ny<=c)) d = 5 - d;
                    y += dy[d];
                }
            }

            if(!board[x][y].empty())
            {
                if(board[x][y].front().size < z)
                {
                    board[x][y].clear();
                    board[x][y].push_back({s,d,z});
                }
            }
            else board[x][y].push_back({s,d,z});
        }
    }
    cout << answer;
}