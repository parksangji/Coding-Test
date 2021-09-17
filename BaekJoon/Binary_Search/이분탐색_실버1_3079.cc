#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    long long N,M;
    cin >> N >> M;

    vector<int> v(N);

    for(int i=0; i< N; i++) cin >> v[i];
    sort(v.begin(),v.end());
    long long start = 1,end = (long long)v.back() * M,answer;
    
    while(start <= end)
    {
        long long mid = (start + end) / 2;
        long long sum = 0;
        for(auto vv : v) sum += (mid / vv) ;

        if(sum < M) start = mid + 1;
        else
        {
            answer = mid;
            end = mid -1;
        }
    }
    cout << answer;
}