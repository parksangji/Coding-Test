#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int prev_l = 10, prev_r = 12;
    for(int i=0; i< numbers.size(); i++)
    {
        if(numbers[i] == 1 or numbers[i] == 4 or numbers[i] == 7)
        {
            prev_l = numbers[i];
            answer += "L";
        }
        else if(numbers[i]== 3 or numbers[i] == 6 or numbers[i] ==9)
        {
            prev_r = numbers[i];
            answer += "R";
        }
        else
        {
            if(numbers[i] == 0) numbers[i] = 11;            
            int left_d = (abs(prev_l - numbers[i])/3) + (abs(prev_l - numbers[i])%3);
            int right_d = (abs(prev_r- numbers[i])/3) + (abs(prev_r - numbers[i])%3);
            
            if(left_d == right_d) 
            {
                if(hand == "left")
                {
                    prev_l = numbers[i];
                    answer += "L";
                }
                else
                {
                    prev_r = numbers[i];
                    answer += "R";
                }
            }
            else if(left_d < right_d)
            {
                answer += "L";
                prev_l = numbers[i];
            }
            else
            {
                answer += "R";
                prev_r = numbers[i];
            }
            
        }
    }
    return answer;
}