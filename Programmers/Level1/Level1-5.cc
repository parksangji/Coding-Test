#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    for (int count1 = 0; count1 < numbers.size(); count1++) {
        for (int count2 = (count1+1); count2 < numbers.size(); count2++) {
            answer.push_back(numbers[count1] + numbers[count2]);
        }
    }
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    return answer;
}