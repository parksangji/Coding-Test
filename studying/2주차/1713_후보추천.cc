#include<iostream>
#include<map>
using namespace std;

int main(void)
{
    int n,total;
    cin >> n >> total;
    map<int,pair<int,int>> command;
    for(int i=1,input; i<=total; i++)
    {
        cin >> input;
        if(command.find(input) == command.end())
        {
            if(command.size() < n)
            {
                command[input].first = 1;
                command[input].second = i;
            }
            else
            {
                int erase = command.begin()->first;
                pair<int,int> info = command.begin()->second;

                for(auto c : command)
                {
                    if(c.second < info)
                    {
                        info = c.second;
                        erase = c.first;
                    }
                }
                command.erase(erase);
                command[input].first = 1;
                command[input].second = i;
            }
        }
        else command[input].first++;
    }

    for(auto c : command) cout << c.first << " ";
}