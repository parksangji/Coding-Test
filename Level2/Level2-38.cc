#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int temp = sqrt(pow((brown+4),2) / 4 - 4 * (brown + yellow));
    int w = ((brown+4) / 2 +temp) / 2;
    int h = ((brown+4) / 2 -temp) / 2;

    answer.push_back(w);
    answer.push_back(h);
    return answer;
}
