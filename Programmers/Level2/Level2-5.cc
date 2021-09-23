using namespace std;

long long gcd(long long W,long long H)
{
    long long c;
    while(H !=0)
    {
        c = W % H ;
        W = H;
        H = c;
    }
    return W;
}

long long solution(int w,int h) {
    long long answer = 1;
    long long W =w ;
    long long H =h ;
    answer = W * H - (W + H - gcd(W,H));
    return answer;
}