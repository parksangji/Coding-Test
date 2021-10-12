#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
    int n,answer=0;
    cin >> n;
    if(n == 0)
    {
        cout << "0";
        return 0;
    }
    for(int i=2; i<=n; i++) 
    {
        if(i % 5 == 0)  answer++;
        if(i % 25 == 0) answer++;
        if(i % 125 == 0) answer++;
    }
    cout << answer ;

}