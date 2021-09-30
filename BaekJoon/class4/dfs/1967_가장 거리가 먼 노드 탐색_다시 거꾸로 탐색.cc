#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int answer =0,last;
vector<pair<int,int>> matrix[10001];

void dfs(vector<bool>& visited, int start,int cnt)
{
    if(visited[start]) return;
    if(cnt > answer)
    {
        answer = cnt;
        last = start;
    }
    visited[start] = true;
    for(int i=0; i<matrix[start].size(); i++)
    {
        dfs(visited,matrix[start][i].first,cnt+matrix[start][i].second);
    }
}

int main(void)
{
    int n;
    cin >> n;
    vector<bool> visited(n+1,false);
    for(int i=0; i<n-1; i++)
    {
        int to,from,weight;
        cin >> to >> from >> weight;
        matrix[to].push_back({from,weight});
        matrix[from].push_back({to,weight});
    }
    dfs(visited,1,0);
    visited.assign(n+1,false);
    dfs(visited,last,0);
    cout << answer;
}