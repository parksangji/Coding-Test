#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

long long N,M=0,cnt=0;
set<long long> answer;

void subset(vector<long long> v,int n)
{
    for(int i=0; i < (1 << n); ++i)
    {
        long long sum = 0;
        for(int j=0; j <n; ++j)
        {
            if(i & (1 << j)) sum += v[j];
        }
        answer.insert(sum);
    }
}
int main(void)
{
    cin >> N;
    vector<long long> v(N);
    for(int i=0; i<v.size() ; i++) 
    {
        cin >> v[i];
        M += v[i];
    }
    subset(v,N);
    answer.erase(0);
    cout << M - answer.size();
}