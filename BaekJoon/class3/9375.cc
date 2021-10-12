#include<iostream>
#include<vector>
#include<map>

using namespace std;


int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while(T--)
    {
        int n,answer = 1;
        cin >> n;
        map<string,int> hash;
        for(int i=0; i<n; i++)
        {
            string s1,s2;
            cin >> s1 >> s2;
            hash[s2]++;
        }
        for(auto h : hash) answer *= h.second + 1;
        cout << answer -1 << '\n';
    }
}