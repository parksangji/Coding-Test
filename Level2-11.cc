#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<long long> array;
    string number = "";
    int remember = 0;
    for(long long i=0; i<s.length(); i++)
    {
        if(s[i] == ' ')
        {
            array.push_back(stoll(number));
            number.clear();
        }
        else number += s[i];
    }
    array.push_back(stoll(number));
    sort(array.begin(),array.end());
    answer = to_string(array[0]) + " " + to_string(array[array.size()-1]);
    return answer;
}