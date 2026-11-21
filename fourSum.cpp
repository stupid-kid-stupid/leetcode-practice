#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
    {
        std::vector<std::vector<int>> result;
        if (nums.size() < 4)    return result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < (nums.size() - 3); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])    continue;
            if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)   break;
            if ((long)nums[i] + nums[nums.size() - 3] + nums[nums.size() - 2] + nums[nums.size() - 1] < target)
            {
                continue;
            }

            for (int j = i + 1; j < (nums.size() - 2); j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])    continue;
                if ((long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)   break;
                if ((long)nums[i] + nums[j] + nums[nums.size() - 2] + nums[nums.size() - 1] < target)
                {
                    continue;
                }

                int left = j + 1;
                int right = nums.size() - 1;

                while (left < right)
                {
                    long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target)
                    {
                        result.push_back({ nums[i], nums[j], nums[left], nums[right] });

                        // 跳过重复的第二个数
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        // 跳过重复的第三个数
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    }
                    else if (sum < target)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }

            }

        }

        return result;
    }
};