#include<iostream>
#include <cstdlib>
#include<string>
#include<map>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); 
    int N,M;
    string input;
    cin >> N >> M;
    map<string,int> pocketmon1;
    map<int,string> pocketmon2;
    for(int i = 0; i<N; i++) 
    {
        cin >> input;
        pocketmon1[input] = i+1,pocketmon2[i+1] = input;
    }
    for(int i=0; i<M; i++)
    {
        cin >> input;
        if( input[0]>= '0' and input[0] <= '9') cout << pocketmon2[stoi(input)] << "\n";
        else cout << pocketmon1[input] << "\n";
    }
}