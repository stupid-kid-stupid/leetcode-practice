#include <unordered_map>
#include <vector>

class Solution {
public:
    int fourSumCount(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, std::vector<int>& nums4)
    {
        std::unordered_map<int, int> countAB;    //countAB: nums1[i] + nums2[j]

        for (int u : nums1)
        {
            for (int v : nums2)
            {
                countAB[u + v]++;
            }
        }

        int ans = 0;
        for (int u : nums3)
        {
            for (int v : nums4)
            {
                auto it = countAB.find(-u - v);
                if (it != countAB.end())
                {
                    ans += it->second;
                }
            }
        }

        return ans;
    }
};