/**
https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/description
You are given an integer array nums. In one operation, you can replace any element in nums with any integer.

nums is considered continuous if both of the following conditions are fulfilled:

All elements in nums are unique.
The difference between the maximum element and the minimum element in nums equals nums.length - 1.
For example, nums = [4, 2, 5, 3] is continuous, but nums = [1, 2, 3, 5, 6] is not continuous.

Return the minimum number of operations to make nums continuous.



Example 1:

Input: nums = [4,2,5,3]
Output: 0
Explanation: nums is already continuous.
Example 2:

Input: nums = [1,2,3,5,6]
Output: 1
Explanation: One possible solution is to change the last element to 4.
The resulting array is [1,2,3,5,4], which is continuous.
Example 3:

Input: nums = [1,10,100,1000]
Output: 3
Explanation: One possible solution is to:
- Change the second element to 2.
- Change the third element to 3.
- Change the fourth element to 4.
The resulting array is [1,2,3,4], which is continuous.


Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
*/
#include "lib/stdc++.h"
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int size = nums.size(), res = size;

        int dup = 0;
        int i = 0, j = 1;
        while (i < size)
        {
            int target = nums[i] + size - 1;
            while (j < size && nums[j] <= target)
            {
                if (nums[j] == nums[j - 1])
                    ++dup;
                ++j;
            }

            res = min(res, i + size - j + dup);

            // increase i
            ++i;
            if (i < size && nums[i] == nums[i - 1])
                --dup;
        }

        return res == size ? 0 : res;
    }
};

int main()
{
    ifstream input("input.txt");

    int size;
    input >> size;
    vector<int> arr(size, 0);
    for (int i = 0; i < size; ++i)
        input >> arr[i];
    input.close();

    Solution s;
    cout << s.minOperations(arr);
}