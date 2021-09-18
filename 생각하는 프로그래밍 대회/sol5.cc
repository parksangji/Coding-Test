#include<iostream>
#include<vector>
#include<map>

using namespace std;


int main(void)
{
    int n;
    cin >> n;
    map<string,vector<pair<string,bool>>> parent;
    vector<string> child;
    for(int i=0 ;i< n; i++)
    {
        string A,B;
        cin >> A >> B;
        parent[B].push_back({A,false});
        child.push_back(B);
    }

    for(int i=0; i<child.size(); i++)
    {
        string search = child[i];
        
    }
}

