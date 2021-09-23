#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> Map;
    
    for(auto c : completion)
    {
        Map[c] += 1;
    }
    for(auto p : participant)
    {
        Map[p] -= 1;
        if(Map[p] < 0)
        {
            return p;
        }
    }
}