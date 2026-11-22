#include <string>
#include <algorithm>

class Solution1 {
public:
    std::string reverseStr(std::string s, int k)
    {
        int num = s.size();
        for (int i = 0; i < num; i += 2 * k)
        {
            int a = num - i;
            int start = i;
            int end = 0;

            if (a >= k)
            {
                end = i + k;
            }
            else
            {
                end = num;
            }

            while (start < (end - 1))
            {
                std::swap(s[start], s[end - 1]);
                start++;
                end--;
            }

        }

        return s;
    }
};

class Solution2 {
public:
    std::string reverseStr(std::string s, int k)
    {
        int num = (int) s.size();
        for (int i = 0; i < num; i += 2 * k)
        {
            std::reverse(s.begin() + i, s.begin() + std::min(i + k, num));
        }

        return s;
    }
};