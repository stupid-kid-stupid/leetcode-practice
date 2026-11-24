#include <string>
#include <vector>

class Solution1 {
public:
    int strStr(std::string haystack, std::string needle)
    {
        int n_haystack = haystack.size();
        int n_needle = needle.size();

        if (n_needle == 0) return 0;

        for (int i = 0; (i + n_needle) <= n_haystack; i++)
        {
            int j = 0;
            while (j < n_needle && haystack[i + j] == needle[j])
            {
                j++;
            }
            if (j == n_needle) return i;
        }

        return -1;
    }
};

class Solution2 {
public:
    int strStr(std::string haystack, std::string needle)
    {
        int n_haystack = haystack.size();
        int n_needle = needle.size();

        if (n_needle == 0) return 0;

        std::vector<int> next(n_needle, 0);
        for (int i = 1, j = 0; i < n_needle; i++)
        {
            while (j > 0 && needle[i] != needle[j])
            {
                j = next[j - 1];
            }
            if (needle[i] == needle[j])  j++;

            next[i] = j;
        }

        for (int i = 0, j = 0; i < n_haystack; i++)
        {
            while (j > 0 && haystack[i] != needle[j])
            {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j])     j++;
            if (j == n_needle)   return i - n_needle + 1;

        }

        return -1;
    }
};