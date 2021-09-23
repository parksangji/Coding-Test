#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;

    for(auto str : clothes) m[str[1]]++;

    for(auto num : m) answer *= (num.second + 1);

    return --answer;
}
