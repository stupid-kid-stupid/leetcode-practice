#include <vector>
#include <climits>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) 
    {
        int lenNums = nums.size();
        int minLength = INT_MAX ;   // Initialize minLength to a large value (infinity)
        int sum = 0;
        int left = 0;

        for(int right = 0; right < lenNums; right++)
        {
            sum += nums[right];
            while(sum >= target)
            {
                if(minLength > (right-left+1))
                {
                    minLength = right-left+1;
                }
                //minLength = min(minLength, right-left+1);
                sum -= nums[left];
                left++;
            }
        }

        return minLength == INT_MAX? 0: minLength;  // If minLength is still infinity, it means no valid subarray was found, so return 0
    }