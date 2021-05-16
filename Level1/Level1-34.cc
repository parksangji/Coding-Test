#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int prev_number =0;
    vector <int> array ;
    for(int i=0; i<dartResult.length();i++)
    {
        if(dartResult[i] >= '0' and dartResult[i] <= '9')
        {
            if(dartResult[i] == '1' and dartResult[i+1] =='0')
            {
                i++;
                array.push_back(10);
            }
            else
            {
                array.push_back(dartResult[i] - '0');
            }
        }
        else if(dartResult[i] == 'S')
        {
            array[array.size()-1] = pow(array[array.size()-1],1);
        }
        else if(dartResult[i] == 'D')
        {
            array[array.size()-1] = pow(array[array.size()-1],2);
        }
        else if(dartResult[i] == 'T')
        {
            array[array.size()-1] = pow(array[array.size()-1],3);
        }
        else if(dartResult[i] == '*')
        {
            array[array.size()-1] = array[array.size()-1] * 2;
            array[array.size()-2] = array[array.size()-2] * 2;
        }
        else if(dartResult[i] == '#')
        {
            array[array.size()-1] = array[array.size()-1] * (-1);
        }
    }
    for(int i=0; i<array.size(); i++)
    {
        answer += array[i];
    }
    return answer;
}