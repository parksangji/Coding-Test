# Coding-Test

## DFS(깊이 우선 탐색)

한 시작점 노드(v)에서 연결된 모든 노드 (w1,w2,w3)들 중 w1부터 탐색하는데 한번 w1를 탐색하면 해당 노드(w1)에 연결된 노드들을 우선적으로 찾아 계속 연결된 노드를 탐색한다. w1의 탐색이 완료되면 다시 v기준으로 w2를 탐색하고 이를 반복한다.

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
