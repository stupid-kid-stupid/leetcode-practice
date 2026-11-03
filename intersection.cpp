#include <vector>
#include <algorithm>

class Solution1 {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        std::vector<int> nums;

        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j])
                {
                    //在nums中找不到
                    if (std::find(nums.begin(), nums.end(), nums2[j]) == nums.end())
                    {
                        nums.push_back(nums2[j]);
                    }

                }
            }
        }

        return nums;
    }
};

class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        std::vector<int> nums;
        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j]) { i++; }
            else if (nums1[i] > nums2[j]) { j++; }
            else
            {
                nums.push_back(nums1[i]);
                //Skip duplicate elements
                while (i < nums1.size() - 1 && nums1[i] == nums1[i + 1]) i++;
                while (j < nums2.size() - 1 && nums2[j] == nums2[j + 1]) j++;
                i++;
                j++;
            }
        }

        return nums;
    }
};