//Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
//
//
//
//Example 1:
//
//Input: nums = [1,2,3]
//Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
//Example 2:
//
//Input: nums = [0,1]
//Output: [[0,1],[1,0]]
//Example 3:
//
//Input: nums = [1]
//Output: [[1]]
//
//
//Constraints:
//
//1 <= nums.length <= 6
//-10 <= nums[i] <= 10
//All the integers of nums are unique.
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        int s = nums.size() - 1;
        bool loop;
        do {
            loop = false;
            vector<int> cp(nums);
            res.push_back(cp);
            for (int i = s; i > 0; --i) {
                if (nums[i] > nums[i - 1]) {
                    int j = i;
                    while (j + 1 <= s && nums[j + 1] > nums[i - 1]) j += 1;
                    nums[i - 1] ^= nums[j];
                    nums[j] ^= nums[i - 1];
                    nums[i - 1] ^= nums[j];
                    reverse(nums.begin() + i, nums.end());
                    loop = true;
                    break;
                }
            }
        } while (loop);

        return res;
    }
};