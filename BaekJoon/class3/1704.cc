#include<map>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(void)
{
    int n,m;
    cin >> n >> m;
    map<string,int> ListenAndSee;
    vector<string> answer;
    for(int i=0; i<n ;i++)
    {
        string tmp;
        cin >> tmp;
        ListenAndSee[tmp]++;
    }
    for(int i=0; i<m; i++)
    {
        string tmp;
        cin >> tmp;
        if(ListenAndSee[tmp]) answer.push_back(tmp);
    }
    sort(answer.begin(),answer.end());
    cout << answer.size() << "\n";
    for(auto a : answer) cout << a << "\n";
}