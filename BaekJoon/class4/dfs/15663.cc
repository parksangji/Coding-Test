#include<iostream>
#include<algorithm>
#include<vector>
#include<set>


using namespace std;

set<vector<int>> s;

void dfs(vector<int> arr,vector<int>& arr2,vector<bool>& visited,int cnt,int target)
{
    if(cnt == target)
    {
        vector<int> v;
        for(int i=0; i<target; i++) v.push_back(arr2[i]);
        s.insert(v);
        return;
    }
    for(int i=0; i< arr.size(); i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            arr2[cnt] = arr[i];
            dfs(arr,arr2,visited,cnt+1,target);
            visited[i] = false;
        }
    }
}

int main(void)
{
    int n,m,input;
    cin >> n >> m;
    vector<int> arr,arr1(n,0);
    vector<bool> visited(n,false);
    for(int i=0; i<n ;i++)
    {
        cin >> input;
        arr.push_back(input);
    } 

    sort(arr.begin(),arr.end());
    dfs(arr,arr1,visited,0,m);
    for(auto ss : s)
    {
        for(auto vv : ss) cout << vv << " ";
        cout << "\n";
    }
}