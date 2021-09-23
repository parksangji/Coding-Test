#include<iostream>
#include<cmath>

using namespace std;

int cnt = 0;

void devide(int n,int x, int y,int xx, int yy)
{
    if(x == xx and y == yy)
    {
        cout << cnt ;
        exit(0);
    }

    if(xx > x + n -1 or yy > y + n -1) 
    {
        cnt += n*n;
        return ;
    }
    
    devide(n/2, x, y, xx, yy);
    devide(n/2, x, y+ n/2, xx, yy);
    devide(n/2, x+ n/2, y, xx, yy);
    devide(n/2, x+ n/2, y+ n/2,xx,yy);
}

int main(void)
{
    int n,x,y;
    cin >> n >> x >> y;
    devide(pow(2,n),0,0,x,y);
}