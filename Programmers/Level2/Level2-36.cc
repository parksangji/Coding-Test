#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    vector<pair<int,int>> table[51];
    vector<int> dist(51,INF); /*최단거리를 갱신해주는 배열 , dist 값을 무한대로 초기화*/
    priority_queue<pair<int,int>> pq;
    
    for(auto v : road)
    {
        table[v[0]].push_back({v[1],v[2]}); /*from, to, value*/
        table[v[1]].push_back({v[0],v[2]}); /*from, to, value*/
    }
    
    pq.push({0,1});/*우선 순위 큐에 시작점과 cost 삽입*/
    dist[1] = 0; /*시작점의 최단거리를 갱신*/
    
    while(!pq.empty())
    {
        int cost = pq.top().first; /*cost는 다음 방문할 점의 dist*/
        int cur = pq.top().second; /*cur을 방문할 점의 번호*/
        
        pq.pop();
        
        for(int i=0; i< table[cur].size(); i++)
        {
            int next = table[cur][i].first;
            int next_cost = table[cur][i].second;
            
            if(dist[next] > dist[cur] + next_cost)
            {
                dist[next] = dist[cur] + next_cost;
                pq.push({-dist[next],next});
            }
        }
    }
    for(int i=1; i<=N; i++) /*문제 조건 대입*/
    {
        if(dist[i] <= K) answer++;
    }
    return answer;
}
