#include <string>
#include <vector>
#include <string>
using namespace std;

bool solution(int x)
{
    bool answer = true;

    string str = to_string(x);

    int sum = 0;

    for(int i=0; i<str.length(); i++)
    {
        sum += str[i] - '0';
    }

    if((x % sum) != 0)
    {
        answer = false;
    }

    return answer;
}