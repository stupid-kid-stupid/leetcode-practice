#include <string>
#include <vector>

class Solution1 {
public:
    std::string removeDuplicates(std::string s)
    {
        std::string stk;

        for (char c : s)
        {
            if (!stk.empty() && stk.back() == c)
            {
                stk.pop_back();
            }
            else
            {
                stk.push_back(c);
            }
        }

        return stk;
    }
};

class Solution2 {
public:
    std::string removeDuplicates(std::string s)
    {
        std::vector<char> store;

        for (const char& c : s)
        {
            if (store.empty() || store.back() != c)
            {
                store.push_back(c);
            }
            else
            {
                store.pop_back();
            }
        }

        return std::string(store.begin(), store.end());
    }
};