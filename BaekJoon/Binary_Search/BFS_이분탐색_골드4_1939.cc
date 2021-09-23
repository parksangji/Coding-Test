#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool BFS(int cost,int start ,int end,vector<vector<pair<int,int>>>& matrix,vector<bool>& visited)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        if(cur == end) return true;
        for(int i=0; i< matrix[cur].size(); i++)
        {
            int next = matrix[cur][i].first;
            int nextCost = matrix[cur][i].second;

            if(!visited[next] and cost <= nextCost)
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return false;
}

int main()
{
    int N,M,start=0,end = 0,mid;
    cin >> N >> M;
    vector<vector<pair<int,int>>> cost(N);
    vector<bool> visited(N,false);
    for(int i=0,A,B,C; i<M; i++)
    {
        cin >> A >> B >> C;
        cost[A-1].push_back({B-1,C});
        cost[B-1].push_back({A-1,C});
        end = max(C,end);
    }
    int A,B;
    cin >> A >> B;
    while(start <= end)
    {
        visited.assign(N,false);
        mid = (start+end)/2;
        if(BFS(mid,A-1,B-1,cost,visited)) start = mid + 1;
        else end = mid - 1;
    }
    cout << end;
}