#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    for (size_t i = 0; i < seoul.size(); i++) {
        if (seoul[i] == "Kim") {
            answer.append(to_string(i));
            break;
        }
    }
    answer.append("에 있다");
    return answer;
}