#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int BFS(int start,vector<int> matrix[])
{
    vector<bool> visited(10001,false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int cnt = 1;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(int i=0; i<matrix[cur].size() ; i++)
            if(!visited[matrix[cur][i]])
            {
                visited[matrix[cur][i]] = true;
                q.push(matrix[cur][i]);
                cnt ++;
            }
    }
    return cnt;
}

int main(void)
{
    int n,m,mv=0;
    cin >> n >> m;
    vector<int> matrix[10001];
    vector<pair<int,int>> answer;
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin >> a >> b;
        matrix[b].push_back(a);
    }
    for(int i=1 ; i <=n; i++)
    {
        int cnt = BFS(i,matrix);
        answer.push_back({i,cnt});
        mv = max(cnt,mv);
    }
    for(int i=0; i<answer.size(); i++) if(mv == answer[i].second) cout << answer[i].first << " ";
}