#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string binary(int number)
{
    string r;
    while(number != 0)
    {
        r += (number % 2 == 0) ? "0" : "1";
        number /= 2;
    }
    return r;
}

vector<int> solution(string s) {
    vector<int> answer;
    int binary_count = 0, delete_zero_count = 0;
    while(s.length() != 1)
    {
        int count_zero = count(s.begin(),s.end(), '0');
        s = binary(s.length()- count_zero);
        binary_count++;
        delete_zero_count += count_zero;
    }
    answer.push_back(binary_count);
    answer.push_back(delete_zero_count);
    return answer;
}