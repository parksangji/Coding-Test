# Coding-Test

## DFS(깊이 우선 탐색)

한 시작점 노드(v)에서 연결된 모든 노드 (w1,w2,w3)들 중 w1부터 탐색하는데 한번 w1를 탐색하면 해당 노드(w1)에 연결된 노드들을 우선적으로 찾아 계속 연결된 노드를 탐색한다. w1의 탐색이 완료되면 다시 v기준으로 w2를 탐색하고 이를 반복한다.

[[Level2] DFS/BFS - 타켓 넘버](https://github.com/parksangji/Coding-Test/commit/f3b8a9503231c3d4333907db31b66edf5877f62c)

```c
#include <string>
#include <vector>

using namespace std;

int answer = 0;

void DFS(vector<int> numbers,int target,int sum,int count)
{
    if(count == numbers.size())
    {
        if(sum == target) answer++;
        return;
    }
    DFS(numbers,target,sum+numbers[count],count+1);
    DFS(numbers,target,sum-numbers[count],count+1);
}

int solution(vector<int> numbers, int target)
{
    DFS(numbers,target,0,0);
    return answer;
}
```

## 최소 공배수 && 최대 공약수

```c
int gcd(int n,int m)
{
    int c;
    while( m != 0)
    {
        c = n % m;
        n = m;
        m = c;
    }
    return n;
}

int lcm(int n, int m)
{
    return n * m / gcd(n,m);   
}
```

## sstream

프로그래머스를 풀다가 문자열에서 정수들을 추출해야 하는 경우가 많이 발생한다. 문자열은 정말 지옥이다.
그러다가 string을 토큰으로 분리할 수 있는 stringstream에 대해 알게 되었다.

stringstream은 공백을 기준으로 string을 뽑아낼 수 있으며, 심지어 음수, 양수를 구분하여 뽑아낼수 있다.

stringstream은 오픈채팅방이라는 문제를 풀면서 알게된 클래스이며 헤드는 <sstream>을 갖는다.
문자열에서 실수와 정수를 추출할 때 'intBuff' 와 'doubleBuff' 으로 추출할 수 있다.
 
[[Level2] 2019 KAKAO BLIND RECRUITMENT - 오픈채팅방](https://github.com/parksangji/Coding-Test/commit/5e5a8ce723f92d0eb43d9adeb43e3781407753e8)

```c
#include <iostream>
#include <sstream>

using namespace std;

int main(void)
{
    int intBuff;
    double doubleBuff;
    
    stringstream ss;
    ss.str("123 56.7);
    ss >> intBuff >> doubleBuff; // intBuff= 123 doubleBuff=56.7
    
    ss.clear();
    
    ss.str("12+32-98+23");
    
    int buff;
    
    while(ss >> buff) // buff = 12 -> 32 -> -98 -> 89 -> 71
    return 0;
```
