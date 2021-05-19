#include <string>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    int arr[11][11][11][11] = {0,};
    int cur_x = 5,cur_y = 5;

    for(int i=0; i<dirs.length(); i++)
    {
        if(dirs[i] == 'U')
        {
            if(cur_y-1 >=0)
            {
                if(arr[cur_x][cur_y][cur_x][cur_y-1] != 1)
                {
                    arr[cur_x][cur_y][cur_x][cur_y-1] = 1;
                    arr[cur_x][cur_y-1][cur_x][cur_y] = 1;
                    answer ++;
                }
                cur_y--;
            }
        }
        else if(dirs[i] == 'D')
        {
            if(cur_y+1 < 11)
            {
                if(arr[cur_x][cur_y][cur_x][cur_y+1] != 1)
                {
                    arr[cur_x][cur_y][cur_x][cur_y+1] = 1;
                    arr[cur_x][cur_y+1][cur_x][cur_y] = 1;
                    answer ++;
                }
                cur_y++;
            }
        }
        else if(dirs[i] == 'R')
        {
            if(cur_x+1 <11)
            {
                if(arr[cur_x][cur_y][cur_x+1][cur_y] != 1)
                {
                    arr[cur_x][cur_y][cur_x+1][cur_y] = 1;
                    arr[cur_x+1][cur_y][cur_x][cur_y] = 1;
                    answer++;
                }
                cur_x++;
            }
        }
        else if(dirs[i] == 'L')
        {
            if(cur_x-1 >=0)
            {
                if(arr[cur_x][cur_y][cur_x-1][cur_y] != 1)
                {
                    arr[cur_x][cur_y][cur_x-1][cur_y] = 1;
                    arr[cur_x-1][cur_y][cur_x][cur_y] = 1;
                    answer ++;
                }
                cur_x--;
            }
        }
    }
    return answer;
}