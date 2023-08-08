//https://leetcode.com/problems/search-in-rotated-sorted-array/description/
//33. Search in Rotated Sorted Array
//        There is an integer array nums sorted in ascending order (with distinct values).
//
//Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
//
//Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
//
//You must write an algorithm with O(log n) runtime complexity.
//
//
//
//Example 1:
//
//Input: nums = [4,5,6,7,0,1,2], target = 0
//Output: 4
//Example 2:
//
//Input: nums = [4,5,6,7,0,1,2], target = 3
//Output: -1
//Example 3:
//
//Input: nums = [1], target = 0
//Output: -1
//
//
//Constraints:
//
//1 <= nums.length <= 5000
//-104 <= nums[i] <= 104
//All values of nums are unique.
//nums is an ascending array that is possibly rotated.
//-104 <= target <= 104

#include "../lib/stdlib.h"


class Solution {
public:
    int search(vector<int> &nums, int target) {
        return find(nums, 0, nums.size() - 1, target);
    }

    int find(vector<int> &nums, int from, int to, int &target) {
        if (from > to) return -1;
        int middle = (from + to) / 2;
        if (nums[middle] == target) return middle;
        if (nums[from] <= nums[to]) {
            return nums[middle] > target ? find(nums, from, middle - 1, target) : find(nums, middle + 1, to, target);
        } else if (nums[to] >= nums[middle]) {
            return (nums[middle] < target && target <= nums[to]) ?
                   find(nums, middle + 1, to, target) : find(nums, from, middle - 1, target);
        } else {
            return (nums[from] <= target && target < nums[middle]) ?
                   find(nums, from, middle - 1, target) : find(nums, middle + 1, to, target);
        }
    }
};