#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(string numbers) {
    int answer = 0;
    vector<char> arr1;
    vector<int> arr2;
    for(int i=0; i<numbers.length() ; i++) arr1.push_back(numbers[i]);
    sort(arr1.begin(),arr1.end());
    do
    {
        string temp = "";
        for(int i=0; i<arr1.size(); i++)
        {
            temp.push_back(arr1[i]);
            arr2.push_back(stoi(temp));
        }
    }while(next_permutation(arr1.begin(),arr1.end()));

    sort(arr2.begin(),arr2.end());
    arr2.erase(unique(arr2.begin(),arr2.end()),arr2.end());

    for(int i=0; i<arr2.size(); i++)
    {
        bool flag = true;
        if(arr2[i] < 2 ) continue;

        for(int j= 2; j<= sqrt(arr2[i]);j++)
        {
            if(arr2[i] % j == 0) 
            {
                flag = false;
                break;
            }
        }

        if(flag) answer++;
    }
    return answer;
}