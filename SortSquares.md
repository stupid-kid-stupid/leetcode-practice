**Solution1:**

class Solution 

{

public:

&#x20;   vector<int> sortedSquares(vector<int>\& nums) 

&#x20;   {

&#x20;       int lenNums = nums.size();

&#x20;       vector<int> res(lenNums);	// 创建一个名为res的vector<int>,包含n个元素，每个元素默认初始值为0

&#x20;       int left = 0;

&#x20;       int right = lenNums - 1;

&#x20;       int pos = lenNums - 1;



&#x20;       while(left <= right)

&#x20;       {

&#x20;           int leftSquares = nums\[left] \* nums\[left];

&#x20;           int rightSquares = nums\[right] \* nums\[right];



&#x20;           if(leftSquares > rightSquares)

&#x20;           {

&#x20;               res\[pos] = leftSquares;

&#x20;               left++;

&#x20;           }

&#x20;           else

&#x20;           {

&#x20;               res\[pos] = rightSquares;

&#x20;               right--;

&#x20;           }

&#x20;           pos--;



&#x20;       }



&#x20;       return res;



&#x20;   }

}; 



Solution2:

class Solution 

{

public:

&#x20;   vector<int> sortedSquares(vector<int>\& nums) {

&#x20;       int lenNums = nums.size();

&#x20;       for(int n = 0; n < lenNums; n++)

&#x09;{

&#x20;           nums\[n] = nums\[n] \* nums\[n];

&#x20;       }

&#x20;       sort(nums.begin(), nums.end());		// 对 nums 中的所有元素进行升序排序

&#x20;       return nums;

&#x20;   }

};









