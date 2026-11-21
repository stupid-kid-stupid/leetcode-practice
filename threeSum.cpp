#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> result;
        if (nums.size() < 3)    return result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < (nums.size() - 2); i++)
        {
            if (nums[i] > 0) break;

            if (i > 0 && nums[i] == nums[i - 1])    continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0)
                {
                    result.push_back({ nums[i], nums[left], nums[right] });

                    // 跳过重复的第二个数
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // 跳过重复的第三个数
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }
                else if (sum < 0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }

        return result;
    }
};