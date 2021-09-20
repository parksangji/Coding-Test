#include<iostream>

using namespace std;

long long pow(long long A,long long B,long long C)
{
    A %= C;
    if(B == 0) return 1;
    else if(B == 1) return A;
    else if(B % 2 == 0)
    {
        long long tmp = pow(A,B/2,C);
        return tmp * tmp % C;
    }
    else return A * pow(A,B-1,C) % C;
}

int main(void)
{
    long long A,B,C;
    cin >> A >> B >> C;
    cout << pow(A,B,C);
}