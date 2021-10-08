#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 실행속도 향상

    int N,K;
    long long answer=0;
    cin >> N >> K;

    vector<pair<int,int>> vp;
    multiset<int> backpack;

    for(int i=0,m,v; i<N; i++)
    {
        cin >> m >> v;
        vp.push_back({m,v});
    }
    for(int i=0,c; i<K; i++)
    {
        cin >> c;
        backpack.insert(c);
    }
    sort(vp.begin(),vp.end(),[](pair<int,int>& p1,pair<int,int>&p2)
    {
        return p1.second > p2.second;
    });

    for(auto ms : vp)
    {
        auto back = backpack.lower_bound(ms.first);

        if(back != backpack.end())
        {
            answer += ms.second;
            backpack.erase(back);
        }
    }
    cout << answer;
}