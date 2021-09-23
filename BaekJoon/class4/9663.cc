#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int dx[] = {0,1,1,1,0,-1,-1,-1};
int dy[] = {-1,-1,0,1,1,1,0,-1}; 


void dfs(vector<vector<bool>>& visited,int x,int y)
{
    for(int i=0; i<8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 and ny >= 0)
    }
}

int main(void)
{
    int n,answer =0;
    cin >> n;
    vector<vector<bool>> visited(n,vector<bool>(n,false));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(!visited[i][j])
            {
                visited[i][j] = true;
                answer++;

            }
        }
    }
}