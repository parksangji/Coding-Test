#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(string a, string b)
{
    if(a.length() == b.length()) return a < b;
    return a.length() < b.length();
}

int main(void)
{
    int N,M;
    cin >> N >> M;

    vector<vector<string>> v(N+1);
    
    while(1)
    {
        int num;
        string name;
        cin >> num >> name;
        if(num == 0 and name == "0") break;
        if(v[num].size() != M) v[num].push_back(name);
    }
    for(int i=1 ; i<= N; i++) sort(v[i].begin(),v[i].end(),cmp);

    for(int i= 1; i<= N; i += 2)
    {
        for(int j=0; j < v[i].size(); j++)
        {
            cout << i << " " << v[i][j] << "\n";
        }
    }
    for(int i= 2; i<= N; i += 2)
    {
        for(int j=0; j< v[i].size(); j++)
        {
            cout << i << " " << v[i][j] << "\n";
        }
    }
}