#include <string>
#include <algorithm>
#include <unordered_map>

class Solution1 {
public:
    bool isAnagram(std::string s, std::string t)
    {
        if (s.size() != t.size()) return false;
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        return s == t;
    }
};

class Solution2 {
public:
    bool isAnagram(std::string s, std::string t)
    {
        if (s.size() != t.size())    return false;

        int count[26] = { 0 };

        for (char c : s) { count[c - 'a']++; }
        for (char c : t)
        {
            if (--count[c - 'a'] < 0)    return false;
        }
        return true;
    }
};

class Solution3 {
public:
    bool isAnagram(std::string s, std::string t)
    {
        if (s.size() != t.size())    return false;

        std::unordered_map<char, int> count;
        for (int i = 0; i < s.size(); i++)
        {
            count[s[i]]++;
            count[t[i]]--;
        }

        for (auto& [ch, v] : count)
        {
            if (v != 0)      return false;
        }

        return true;
    }
};
