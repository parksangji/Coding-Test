#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<pair<int,int>> vp;
    for(int i=0; i< n; i++)
    {
        int s,t;
        cin >> s >> t;
        vp.push_back({s,t});
    }
    sort(vp.begin(),vp.end());

    pq.push(vp[0].second);

    for(int i=1; i< n; i++)
    {
        if(pq.top() > vp[i].first) pq.push(vp[i].second);
        else
        {
            pq.pop();
            pq.push(vp[i].second);
        }
    }
    cout << pq.size();
}