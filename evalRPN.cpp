#include <string>
#include <stack>
#include <vector>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens)
    {
        std::stack<int> stk;

        for (const std::string& t : tokens)
        {
            if (t == "+" || t == "-" || t == "*" || t == "/")
            {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();

                if (t == "+")    stk.push(a + b);
                else if (t == "-")    stk.push(a - b);
                else if (t == "*")    stk.push(a * b);
                else     stk.push(a / b);
            }
            else
            {
                stk.push(stoi(t));
            }
        }
        return stk.top();
    }
};