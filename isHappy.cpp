class Solution {
public:
    bool isHappy(int n)
    {
        int slow = n;
        int fast = n;

        do {
            slow = getSum(slow);
            fast = getSum(fast);
            fast = getSum(fast);
        } while (slow != fast);

        return slow == 1;
    }

    int getSum(int n)
    {
        int sum = 0;

        while (n > 0)
        {
            int k = n % 10;
            sum = sum + k * k;
            n = n / 10;
        }

        return sum;
    }
};