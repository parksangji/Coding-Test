#include <string>
#include <vector>
#include <stack>

/*크레인 인형 뽑기*/

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> array;
    for(int i=0; i<moves.size(); i++)
    {
        moves[i] -= 1;
    }
    for(int i=0; i<moves.size(); i++)
    {
        int number = moves[i];
        
        for(int j=0; j<board.size(); j++)
        {
            if(board[j][number] != 0)
            {
                if(array.empty() != 1)
                {
                	if(board[j][number] == array.top())
                    {
                        array.pop();
                		answer += 2;
                    }
                    else
                    {
                      	array.push(board[j][number]);
                    }
                }
                else
                {
                    array.push(board[j][number]);
                }
                board[j][number] = 0;
                break;
            }
            else
            {
                continue;
            }
        }
    }
    return answer;
}