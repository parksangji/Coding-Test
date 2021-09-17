#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
    int A_size;
    cin >> A_size;
    vector<int> A(1);

    for(int i=0,num; i<A_size; i++)
    {
        cin >> num;
        if(A.back() < num) A.push_back(num);
        else A[lower_bound(A.begin(),A.end(),num) - A.begin()] = num;
    }
    cout << A.size() -1 ;
}