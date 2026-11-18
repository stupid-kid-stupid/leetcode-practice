#include <string>
#include <unordered_map>

class Solution1 {
public:
    bool canConstruct(std::string ransomNote, std::string magazine)
    {
        std::unordered_map<char, int> count;

        for (char c : magazine)
        {
            count[c]++;
        }

        for (char c : ransomNote)
        {
            if (count[c] == 0)   return false;
            count[c]--;
        }

        return true;
    }
};

class Solution2 {
public:
    bool canConstruct(std::string ransomNote, std::string magazine)
    {
        int count[26] = { 0 };

        for (char c : magazine)
        {
            count[c - 'a']++;
        }

        for (char c : ransomNote)
        {
            if (count[c - 'a'] == 0) return false;
            count[c - 'a']--;
        }

        return true;
    }
};

class Solution3 {
public:
    bool canConstruct(std::string ransomNote, std::string magazine)
    {
        int count[26] = { 0 };
        for (char c : magazine) count[c - 'a']++;
        for (char c : ransomNote) {
            if (--count[c - 'a'] < 0) return false;
        }
        return true;
    }
};