#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    queue<pair<int,int>> q;
    priority_queue<int,vector<int>,less<int>> pq;
    
    for(int i=0; i< priorities.size();i++)
    {
        q.push({i,priorities[i]});
        pq.push(priorities[i]);
    }
    while(!q.empty())
    {
        pair<int,int> compare = q.front();
        q.pop();
        if(pq.top()==compare.second)
        {
            if(compare.first == location) return answer;
            pq.pop();
            answer++;
        }
        else q.push(compare);
    }
    return answer;
}