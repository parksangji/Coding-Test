#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main(void)
{
    char L,R;
    string s;
    cin >> L >> R >> s;
    vector<string> board;
    board.push_back("qwertyuiop");
    board.push_back("asdfghjkl");
    board.push_back("zxcvbnm");

    pair<int,int> left,right;

    for(int i=0; i<board.size(); i++)
        for(int j=0; j<board[i].length(); j++)
        {
            if(L == board[i][j]) left = {i,j};
            if(R == board[i][j]) right = {i,j};
        }
    int time = 0;
    string mo = "yuiophjklbnm";
    for(int j=0; j<s.length(); j++)
    {
        char find_s = s[j];

        if(find(mo.begin(),mo.end(),find_s) != mo.end())
        {
            for(int i=0; i<board.size(); i++)
            {
                int idx = find(board[i].begin(),board[i].end(),find_s) - board[i].begin();
                if(idx != board[i].size())
                {
                    time += abs(right.first-i) + abs(right.second - idx) + 1;
                    right = {i,idx};
                    break;
                }
            }
        }
        else
        {
            for(int i=0; i<board.size(); i++)
            {
                int idx = find(board[i].begin(),board[i].end(),find_s) - board[i].begin();
                if(idx != board[i].size())
                {
                    time += abs(left.first-i) + abs(left.second - idx) + 1;
                    left = {i,idx};
                    break;
                }
            }
        }
    }
    cout << time;
}