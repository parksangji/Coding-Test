#include<iostream>

using namespace std;

int main(void)
{
    long long  n,m,child = 1,parent = 1;
    cin >> n >> m;
    
    while(m>=1)
    {
        child *= n;
        parent *= m;
        if(child % parent == 0)
        {
            child /= parent;
            parent = 1;
        }
        n--;
        m--;
    }
    cout << child/parent;
}