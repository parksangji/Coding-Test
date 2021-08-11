#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int n;

int main(void)
{
    cin >> n;
    vector<long long> v(n+1,0);
    for(long long i=2; i<= n ; i++)
    {
        v[i] = v[i-1] + 1;
        if(i % 2 == 0) v[i] = min(v[i],v[i/2] + 1);
        if(i % 3 == 0) v[i] = min(v[i],v[i/3] + 1);
    }

    cout << v[n];
}
