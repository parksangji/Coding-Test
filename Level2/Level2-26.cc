#include <iostream>
using namespace std;
int solution(int n)
{
    int cnt = 0;
    while(n){
        if(n%2==0)n/=2;
        else {
            n--;
            cnt++;
        }
    }
    return cnt;
}