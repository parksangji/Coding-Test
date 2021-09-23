#include<iostream>
#include<algorithm>
#include<vector>
#include<set>


using namespace std;

set<vector<int>> s;

void dfs(vector<int> arr,vector<int>& arr2,int cnt,int idx,int target)
{
    if(cnt == target)
    {
        vector<int> v;
        for(int i=0; i<target; i++) v.push_back(arr2[i]);
        s.insert(v);
        return;
    }
    for(int i=idx; i< arr.size(); i++)
    {
        arr2[cnt] = arr[i];
        dfs(arr,arr2,cnt+1,i,target);
    }
}

int main(void)
{
    int n,m,input;
    cin >> n >> m;
    vector<int> arr,arr1(n,0);
    for(int i=0; i<n ;i++)
    {
        cin >> input;
        arr.push_back(input);
    } 

    sort(arr.begin(),arr.end());
    dfs(arr,arr1,0,0,m);
    for(auto ss : s)
    {
        for(auto vv : ss) cout << vv << " ";
        cout << "\n";
    }
}