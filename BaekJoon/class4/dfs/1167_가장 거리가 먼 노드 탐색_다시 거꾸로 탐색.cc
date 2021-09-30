#include<iostream>
#include<vector>

using namespace std;

vector<pair<int,int>> matrix[100001];
vector<bool> visited(100001);

int answer = 0,last;

void dfs(int start,int w)
{
    if(visited[start]) return;
    visited[start] = true;
    if(answer < w)
    {
        answer =w;
        last = start;
    }
    for(int i=0; i<matrix[start].size(); i++)
        dfs(matrix[start][i].first,matrix[start][i].second + w);
}

int main(void)
{
    int n;
    cin >> n;
    while(n)
    {
        int to;
        cin >> to;
        for(;;)
        {
            int from,weight;
            cin >> from;
            if(from == -1) break;
            else cin >> weight;
            matrix[to].push_back({from,weight});
            matrix[from].push_back({to,weight});
        }
        n--;
    }

    dfs(1,0);
    visited.assign(100001,false);
    dfs(last,0);
    cout << answer;
}