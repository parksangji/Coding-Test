#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int size = nums.size() / 2;

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());    

    if(nums.size() >= size)
        return size;
    else
        return nums.size();
}