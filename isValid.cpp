#include <stack>
#include <string>
#include <unordered_map>

class Solution1 {
public:
    bool isValid(std::string s)
    {
        std::stack<char> st;

        for (char c : s)
        {
            switch (c)
            {
            case '(': st.push(')'); break;
            case '[': st.push(']'); break;
            case '{': st.push('}'); break;
            default:
                if (st.empty() || st.top() != c)     return false;
                st.pop();
            }
        }

        return st.empty();
    }
};

class Solution2 {
public:
    bool isValid(std::string s)
    {
        int n = s.size();
        if (n % 2 != 0)  return false;

        std::stack<char> st;
        std::unordered_map<char, char> match = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s)
        {
            if (match.count(c))
            {
                if (st.empty() || st.top() != match[c])  return false;
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }

        return st.empty();
    }
};