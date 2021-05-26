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
## Greedy Algorithms(탐욕법, 탐욕 알고리즘)

greedy algorithm은 문제를 해결하는 과정에서 그 순간순간마다 최적이라고 생각되는 결정을 하는 방식으로 진행하여 최종 해답에 도달하는 문제 해결 방식이다.

[[Level2] 탐욕법 - 큰 수 만들기](https://github.com/parksangji/Coding-Test/blob/main/Level2/Level2-19.cc)

## DP (동적 계획법)

상당수의 분할 정복 기법(큰 문제를 작은 여러개의 문제로 나누어 푸는 기법으로 재귀적 성격을 띔)은 동일한 문제를 추후 다시 푼다는 단점을 가지고 있다.

동적 계획법을 사용할 수 있는 가정
큰 문제를 작은 문제로 나눌 수 있어야 한다. 마치 피보나치 수열처럼.
큰 문제들은 작은 문제들로 이루어진다. 작은 문제들로 분할이 가능.
단, 큰 문제와 작은 문제의 관계에서 사이클이 발생해선 안된다.작은 문제에서 구한 정답은 그것을 포함하는 큰 문제에서도 동일하다.
즉, 점화식을 세울 수 있어야 한다. 4 를 구하는 과정에서 구해서 저장했던 3 을, 5 를 구하는 과정에서도 그대로 쓸 수 있는 문제여야 한다. 동일하게.

[[Level2] 땅따먹기 ](https://github.com/parksangji/Coding-Test/blob/main/Level2/Level2-30.cc)

## 에스토스테네스의 체 (소수 판별)

소수를 판별하기 위해 에라토스테네스의 체를 이용한다. 에라토스테네스의 체를 간단히 설명하자면, 2부터 n까지의 수 중에 소수를 판별하기 위한 알고리즘이다. 소수를 찾으면 해당 수의 배수를 모두 지워나가는 방식이다.

![image](https://user-images.githubusercontent.com/59435705/119635635-db3f0900-be4e-11eb-8e45-bf076fa1e47c.png)


```c
bool isPrime(int n)
{
    if(n < 2) return false;
    
    for(int i = 2; i <= sqrt(n) ; i++) if(n % i == 0) return false;
    
    return true;
    
}
```

## 순열 

수학적으로 순열이란 서로 다른 n개의 원소에서 r개를 뽑아 한 줄로 세우는 경우의 수를 말한다. 원소를 한 줄로 세우기 때문에 원소의 조합이 같더라도 순서가 다르면 다른 방법으로 본다.

ex) {1, 2, 3}의 원소들의 모든 순열을 구한다면 {1, 2, 3}, {1, 3, 2} {2, 1, 3} {2, 3, 1} {3, 1, 2} {3 2 1} 으로 총 6가지가 나온다.

# next_permutation

c++ 의 <algorithm> 헤더에는 n개의 원소의 순열을 구할 수 있는 next_permutation이라는 함수가 있다. 기본적 문법은 다음과 같다.
    
```c
bool next_permutation(BidirectionalIterator first, BidirectionalIterator last};

bool next_permutation(BidirectionalIterator first, BidirectionalIterator last,compare comp};
```

next_permutaion을 사용할 때는 몇 가지 주의할 점

1. 오름차순으로 정렬된 값을 가진 컨테이너로만 사용가능하다.
2. defalut로 operator <를 사용해 순열을 생성한다.
3. 중복이 있는 원소들은 중복을 제외하고 순열을 만들어준다.

next_permutation 사용 예시

```c
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    vector<int> v{ 1, 2, 3};
 
    sort(v.begin(), v.end());
 
    do {
        for (auto it = v.begin(); it != v.end(); ++it)
            cout << *it << ' ';
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));
}

```

[[Level2] 소수 찾기](https://github.com/parksangji/Coding-Test/blob/main/Level2/Level2-33.cc)


## 해쉬 (map 과 unordered_map)

unordered_map

unordered_map은 hash_table 기반의 hash container입니다. 

hash_table을 통해 참조를 하기 때문에 각 node들을 정렬할 필요가 없습니다. 

따라서 충분한 hash_table의 크기만 주어진다면 데이터 양이 많아지더라도 Search / Insert / Delete 성능을 꾸준하게 보장할 수 있습니다. 

성능 비교 

map 과 hash_map 은 알고리즘 특성 상 키의 데이터 타입이 숫자일 때와 문자열일 때 현격한 차이를 보입니다. 

따라서 성능 비교도 숫자형 키를 사용할 때와 문자열 키를 사용할 때를 따로 비교해야 합니다. 

아래와 같이 container에 데이터를 insert 한 뒤 find를 반복적으로 수행한 시간을 기록합니다.

X 축은 데이터 크기 N, Y 축은 탐색 1회에 걸린 시간(마이크로초) 입니다.

map은 O(logN) 의 시간복잡도를 보이며 급격히 소요시간이 증가한 구간은 캐시 미스로 인해 발생한 것으로 추측됩니다. 

그에 반해 unordered_map 은 O(1) 의 시간 복잡도를 보여줍니다. 

이처럼 숫자형 키를 사용할 경우 데이터의 양이 많아질수록 unordered_map이 월등한 성능을 보여주게됩니다.
Key Type : const char*
 
문자열을 키로 사용할 경우는 조금 복잡합니다. 

map은 insert 할 때 key를 기반으로 정렬하게 되는데 문자열 비교 함수의 성능은 문자열 전체를 hashing 하는 것에 비해 우수합니다. 

그것은 문자열 전체를 비교하지 않고 앞에서부터 한글자씩 차례로 비교하여 크고 작음을 가려내기 때문에 문자열의 길이가 길어지더라도 민감하게 반응하지 않습니다. 

key value들의 분포가 고르게 형성되어 있어 앞의 몇 글자만 비교해서 우열이 가려질 가능성이 있기 때문이죠. 

예를 들어 문자열 key의 집합이 다음과 같다고 했을 때, 

black, blue, cyan, gray, green, lime, magenta, maroon,
navy, olive, purple, red, silver, teal, white, yellow
 

앞의 1~2글자만 비교하면 대부분의 문자열 비교가 끝나게 됩니다.

반면 문자열의 길이가 길어지면 key를 hashing 하는 unordered_map의 경우 성능에 영향을 상대적으로 많이 받게 됩니다. 

따라서 문자열의 길이를 4, 8, 12, 16 으로 측정을 했을 때 아래와 같은 결과를 확인할 수 있습니다.

X 축은 데이터 크기 N, Y 축은 탐색 1회에 걸린 시간(마이크로초) 입니다.
기본적으로 숫자형 key와 비슷한 양상을 보이며, 문자열 길이가 커짐에 따라 교차점이 달라짐을 확인할 수 있습니다.

물론 key의 집합이 다음과 같이 접두사가 비슷한 경우라면 map도 문자열 길이의 영향을 더 크게 받게 됩니다. 

abnormal, abnomality, abnomalities, abnormalization
 
그렇기 때문에 키 값을 timestamp를 이용해 만들어 사용하는 경우에 문자열의 앞부분이 같은 표본이 대량으로 생성되어

비교함수의 성능이 떨어지므로 지양해야 합니다. (실제 사례)

결론
데이터가 많은 경우에는 unordered_map 이 map 보다 성능면에서 유리합니다. 
문자열을 키로 사용하는 경우 문자열이 길어질 수록 unordered_map 이 map에 비해 더 성능이 떨어질 수 있습니다. 
유사도가 높은 문자열 집합을 키로 사용하는 경우에 map 의 성능이 떨어질 수 있습니다. 
 

결론적으로 key를 이용하여 정렬을 해야 하는 경우를 제외하고 대량의 데이터를 저장할 때는 unordered_map 을 사용하는걸 추천합니다.

[[Level2] 위장](https://github.com/parksangji/Coding-Test/blob/main/Level2/Level2-34.cc)
