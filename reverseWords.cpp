#include <string>
#include <vector>
#include <sstream>
#include <algorithm>


class Solution1 {
public:
    std::string reverseWords(std::string s)
    {
        std::stringstream ss(s);
        std::string word;
        std::vector<std::string> words;
        while (ss >> word)
        {
            words.push_back(word);
        }

        reverse(words.begin(), words.end());

        std::string result;
        for (int i = 0; i < words.size(); i++)
        {
            if (i > 0)  result += ' ';
            result += words[i];
        }

        return result;
    }
};

class Solution2 {
public:
    std::string reverseWords(std::string s)
    {
        int n = s.size();
        int write = 0;
        for (int read = 0; read < n; read++)
        {
            if (s[read] != ' ')
            {
                if (write > 0)   s[write++] = ' ';
                while (read < n && s[read] != ' ')
                {
                    s[write++] = s[read++];
                }
            }
        }

        s.resize(write);
        reverse(s.begin(), s.end());

        int start = 0;
        for (int i = 0; i <= (int)s.size(); i++)
        {
            if (i == (int)s.size() || s[i] == ' ')
            {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        return s;
    }
};