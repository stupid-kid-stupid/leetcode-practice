#include <vector>
#include <iostream>


class Solution {
public:
    void reverseString(std::vector<char>& s)
    {
        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {
            std::swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

class Solution1 {
public:
    void reverseString(std::vector<char>& s)
    {
        for (int i = 0; i < (s.size() / 2); i++)
        {
            std::swap(s[i], s[s.size() - i - 1]);
        }
    }
};

int main()
{
    Solution sol;

    // 方式 1：直接构造 vector<char>
    std::vector<char> s1 = { 'h', 'e', 'l', 'l', 'o' };
    sol.reverseString(s1);

    for (char c :s1) std::cout << c << " ";
    std::cout << std::endl;   // 输出: o l l e h

    // 方式 2：从字符串构造
    std::string str = "Hannah";
    std::vector<char> s2(str.begin(), str.end());
    sol.reverseString(s2);

    for (char c : s2) std::cout << c << " ";
    std::cout << std::endl;   // 输出: h a n n a H

    return 0;
}