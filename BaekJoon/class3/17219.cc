#include<iostream>
#include<string>
#include<map>

using namespace std;

int main(void)
{
    int n,m;

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    map<string,string> db;
    
    for(int i=0; i<n; i++)
    {
        string page,pw;
        cin >> page  >> pw;
        db[page] = pw;
    }
    for(int i=0; i<m; i++)
    {
        string query;
        cin >> query;
        cout << db[query] <<'\n';
    }
}