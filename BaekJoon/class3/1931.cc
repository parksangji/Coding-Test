#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool cmp(pair<int,int> p1, pair<int,int> p2)
{
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}

int main(void)
{
    int n,answer= 1;
    cin >> n;
    vector<pair<int,int>> v;
    for(int i=0; i< n; i++)
    {
        int x,y;
        cin >> x >> y ;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),cmp);

    int cur = v.front().second;
    for(int i= 1; i< n; i++)
    {
        int start = v[i].first;
        int end = v[i].second;

        if(start >= cur)
        {
            answer++;
            cur = end;
        }
    }
    cout << answer << '\n';
}