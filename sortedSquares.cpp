#include <vector>

std::vector<int> sortedSquares(std::vector<int>& nums) 
{
    int lenNums = nums.size();
    std::vector<int> res(lenNums);
    int left = 0;
    int right = lenNums - 1;
    int pos = lenNums - 1;

    while(left <= right)
    {
        int leftSquares = nums[left] * nums[left];
        int rightSquares = nums[right] * nums[right];

        if(leftSquares > rightSquares)
        {
            res[pos] = leftSquares;
            left++;
        }
        else
        {
            res[pos] = rightSquares;
            right--;
        }
        pos--;

    }

    return res;

}