#include <string>
#include <vector>

using namespace std;
/*N개의 최소공배수*/
int gcd(int n,int m)
{
    int c;
    while( m != 0)
    {
        c = n % m;
        n = m;
        m = c;
    }
    return n;
}

int lcm(int n, int m)
{
    return n * m / gcd(n,m);   
}

int solution(vector<int> arr) {
    int answer = 1;
    
    for(int i=0; i< arr.size(); i++)
    {
        answer = lcm(answer,arr[i]);
    }
    return answer;
}

