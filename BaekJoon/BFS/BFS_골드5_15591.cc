#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
struct info
{
    int to;
    int value;
};
int main(void)
{
    int N,Q;
    cin >> N >> Q;
    vector<vector<info>> mootue(N+1);
    vector<bool> visited(N+1,false);
    vector<int> answer;
    for(int i=0,p,q,r; i<N-1; i++)
    {
        cin >> p >> q >> r;
        mootue[p].push_back({q,r});
        mootue[q].push_back({p,r});
    }

    for(int i=0,k,v,cnt=0; i<Q;cnt=0, i++)
    {
        cin >> k >> v;
        visited.assign(N,false);
        queue<int> q;
        q.push(v);
        visited[v] = true;
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            for(int i=0; i<mootue[cur].size(); i++)
            {
                int to = mootue[cur][i].to;
                int value = mootue[cur][i].value;
                if(k <= value and !visited[to])
                {
                    visited[to] = true;
                    q.push(to);
                    cnt++;
                }                
            }
        }
        answer.push_back(cnt);
    }
    for(auto ans : answer) cout << ans << "\n";
}