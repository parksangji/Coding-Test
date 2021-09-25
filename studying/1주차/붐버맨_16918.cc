#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};

int main(void)
{
    int r,c,n;
    cin >> r >> c >> n;
    vector<vector<char>> boom(r,vector<char>(c));
    queue<pair<int,int>> q;

    for(int i=0; i< r; i++)
    {
        string s; 
        cin >> s;
        for(int j=0; j<s.length(); j++) boom[i][j] = s[j];
    }
    int time = 1;
    while(time < n)
    {
        for(int i=0; i< r; i ++)
        {
            for(int j=0; j< c ; j++)
            {
                if(boom[i][j] == 'O') q.push({i,j});
                else boom[i][j] = 'O';
            }
        }
        time ++;
        if(time == n) break;
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            boom[x][y] = '.';
            for(int i=0; i<4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >=0 and nx < r and ny >= 0 and ny < c and boom[nx][ny] == 'O') boom[nx][ny] = '.';
            }
        }
        time++;
    }
    for(int i=0; i< r; i ++)
    {  
        for(int j=0; j< c ; j++) cout << boom[i][j];
        cout << "\n";
    }
}