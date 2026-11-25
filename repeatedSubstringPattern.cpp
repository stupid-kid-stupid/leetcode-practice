#include <string>

class Solution1 {
public:
    bool repeatedSubstringPattern(std::string s)
    {
        int n = s.size();

        for (int len = 1; len <= (n / 2); len++)
        {
            if (n % len != 0)    continue;

            bool isHave = true;
            for (int i = len; i < n; i++)
            {
                if (s[i] != s[i - len])
                {
                    isHave = false;
                    break;
                }
            }

            if (isHave) return true;
        }

        return false;
    }
};

class Solution2 {
public:
    bool repeatedSubstringPattern(std::string s)
    {
        std::string ss = s + s;
        std::string trimmed = ss.substr(1, ss.size() - 2);
        return trimmed.find(s) != std::string::npos;
    }
};