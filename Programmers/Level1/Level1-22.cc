#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    vector<long long> arr;
    string s = to_string(n);
    
    for(int i=0; i<s.length(); i++) arr.push_back(s[i] - '0');
    s.clear();
    s = "";
    sort(arr.begin(),arr.end(),greater<int>());
    
    for(int i=0; i<arr.size(); i++) s += to_string(arr[i]);
    
    answer = stoll(s);
    
    return answer;
}