/*탐욕법(Greedy)
큰 수 만들기
*/

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int index = 0;
    for(int i=0; i<number.length()-k; i++){
        char max = number[index];
        int maxi = index;
        for(int j=index; j<=k+i; j++){
            if(max < number[j]){
                max = number[j];
                maxi = j;
            }
        }
        index = maxi +1;
        answer+= max;
    }
    return answer;
}