#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    long long N,k;
    cin >> N >> k;
    long long start = 1, end = N * N, answer = 0;
    while(start <= end)
    {
        long long mid = (start + end) / 2;
        long long cnt = 0;
        for(long long i = 1 ; i<= N; i ++) cnt += min(N,mid/i);
        if(cnt >= k) answer = mid, end = mid - 1;
        else start = mid + 1;
    }
    cout << answer ;
}