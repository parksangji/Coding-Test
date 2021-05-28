#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool right_Cond(char a, char dif, char num)
{
    if(a == '=') return dif == num;
    else if(a == '>') return dif > num;
    else if(a == '<') return dif < num;
}

// {A, C, F, J, M, N, R, T}
int solution(int n, vector<string> data) {
    int answer = 0;
    string friends = "ACFJMNRT";

    do
    {
        bool flag = true;
        for(auto v : data)
        {
            char first = v[0];
            char second = v[2];
            char compare = v[3];
            int num = v[4] - '0';
            int dist = friends.find(first) - friends.find(second);
            dist = abs(dist) - 1;
            if(right_Cond(compare,dist,num)) continue;
            flag = false;
            break;
        }
        if(flag) answer++;
    }while(next_permutation(friends.begin(),friends.end()));
    return answer;
}
