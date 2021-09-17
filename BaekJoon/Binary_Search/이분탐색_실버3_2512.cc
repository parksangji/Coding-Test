#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main(void)
{
    int N,total_price;
    cin >> N;
    vector<int> v(N);
    for(int i=0; i<N ;i++) cin >> v[i];
    cin >> total_price;
    sort(v.begin(),v.end());
    int start = 0,end = v.back(),mid,answer;
    while(start <= end)
    {
        mid = (start + end) / 2;
        int sum = 0;
        for(auto vv : v) sum += min(vv,mid); 
        if(total_price >= sum)
        {
            start = mid + 1;
            answer = mid;
        }
        else end = mid - 1;
    }
    cout << answer;
}
