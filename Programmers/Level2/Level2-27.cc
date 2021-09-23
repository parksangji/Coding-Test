#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
// Summer/Winter Coding(~2018) 영어 끝말잇기

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> test;
    int number =1, turn = 1;
    char remember_last_alpha = words[0][words[0].length()-1];
    for(int i=1 ; i<=words.size(); i++)
    {

        if(test.size() != 0 and test[test.size()-1][test[test.size()-1].length()-1] != words[i-1][0])
        {
            answer.push_back(number);
            answer.push_back(turn);
            break;   
        }
        if(test.size()!= 0 and find(test.begin(),test.end(),words[i-1]) != test.end())
        {
            answer.push_back(number);
            answer.push_back(turn);
            break; 
        }
        test.push_back(words[i-1]);
        remember_last_alpha = words[i-1][words[i-1].length()-1];
        number++;
        if(number == n+1) number = 1;
        if(i % n == 0) turn++;  
    }
    if(answer.size() == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}