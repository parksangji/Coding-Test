#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool queen(vector<vector<bool>>& visited,int x,int y)
{
    int xx,yy;
    xx = x-1;
    yy = y;
    while(xx >= 0)
    {
        if(visited[xx][yy]) return false;
        xx --;
    }
    xx = x - 1;
    yy = y - 1;
    while(xx >=0 and yy >=0)
    {
        if(visited[xx][yy]) return false;
        xx --;
        yy --;
    }
    xx = x - 1;
    yy = y + 1;
    while(xx >=0 and yy < visited.size())
    {
        if(visited[xx][yy]) return false;
        xx --;
        yy ++;
    }
    return true;
}

void dfs(vector<vector<bool>>& visited,int x,int& answer)
{
    if(x == visited.size())
    {
        answer++;
        return;
    }
    for(int i=0; i<visited.size(); i++)
    {
        visited[x][i] = true;
        if(queen(visited,x,i)) dfs(visited,x+1,answer);
        visited[x][i] = false;
    }
}

int main(void)
{
    int n,answer =0;
    cin >> n;
    vector<vector<bool>> visited(n,vector<bool>(n,false));

    dfs(visited,0,answer);
    cout << answer ;
}