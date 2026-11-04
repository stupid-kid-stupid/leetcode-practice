#include <vector>
#include <unordered_map>

class Solution1 {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return { i, j };
                }
            }
        }
        return {};
    }
};

class Solution2 {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++)
        {
            int need = target - nums[i];
            if (seen.count(need) != 0)
            {
                return { i, seen[need] };
            }
            seen[nums[i]] = i;
        }

        return {};
    }
};