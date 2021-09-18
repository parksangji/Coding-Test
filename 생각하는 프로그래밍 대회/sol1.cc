#include<iostream>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int n = N;
    for(int i=1; i<= N; i++,n--)
    {
        for(int j=1; j<= N; j++)
        {
            if(i == 1 or i == N) 
            {
                cout << "*";
                continue;
            }
            if(j == 1 or j == N)
            {
                cout << "*";
                continue;
            }
            if(i == j or n== j) cout << "*";
            else cout << " ";
        }
        cout << "\n";
    }
}