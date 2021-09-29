#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void)
{
    int v,e,start;
    cin >> v >> e >> start;

    vector<pair<int,int>> map[v+1];
    vector<int> dist(v+1,INT32_MAX);
    for(int i=0; i< e; i++)
    {
        int from,to,weight;
        cin >> from >> to >> weight;
        map[from].push_back({to,weight});
    }

    priority_queue<pair<int,int>> pq;
    pq.push({0,start});
    dist[start] = 0;

    while(!pq.empty())
    {
        int cur = pq.top().second;
        int w = -1 * pq.top().first;
        
        pq.pop();

        if(dist[cur] < w) continue;

        for(int i=0; i<map[cur].size(); i++)
        {
            int cost = w + map[cur][i].second;
            if(cost < dist[map[cur][i].first])
            {
                dist[map[cur][i].first] = cost;
                pq.push({-1 * cost,map[cur][i].first});
            }
        }
    }
    for(int i=1; i<=v;i++) 
    {
        if(dist[i] == INT32_MAX) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}