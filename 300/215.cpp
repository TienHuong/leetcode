//https://leetcode.com/problems/kth-largest-element-in-an-array/
//Given an integer array nums and an integer k, return the kth largest element in the array.
//
//Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
//Can you solve it without sorting?
//
//
//
//Example 1:
//
//Input: nums = [3,2,1,5,6,4], k = 2
//Output: 5
//Example 2:
//
//Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
//Output: 4
//
//
//Constraints:
//
//1 <= k <= nums.length <= 105
//-104 <= nums[i] <= 104

#include "../lib/stdlib.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int heapSize = nums.size() - k + 1;
        vector<int> heap(nums.begin(), nums.begin() + heapSize);
        make_heap(heap.begin(), heap.end());

        int res = INT_MAX;
        int i = heapSize;
        do {
            if (heap.back() < res) {
                res = heap.back();
            }
            pop_heap(heap.begin(), heap.end());
            if (i < nums.size()) {
                heap.push_back(nums[i++]);
                push_heap(heap.begin(), heap.end());
            }
        } while (i < nums.size());

        return res;
    }
};