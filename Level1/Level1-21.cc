#include <string>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string s1 = to_string(n);
    
    reverse(s1.begin(),s1.end());
    
    for(int i=0; i<s1.size(); i++) answer.push_back(s1[i] - '0');
    
    return answer;
}