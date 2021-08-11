#include<iostream>
#include<vector>

using namespace std;


int main(void)
{
    long long n;
    cin >> n;
    vector<long long> v(n+1);

    v[0] = 0;
    v[1] = 1;

    for(long long i= 2; i<= n; i++) v[i] = v[i-1] + v[i-2]; 

    cout << v[n];
}

