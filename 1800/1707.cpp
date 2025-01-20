#include "lib/lib.h"
#include "lib/stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-xor-with-an-element-from-array/description/
// You are given an array nums consisting of non-negative integers. You are also
// given a queries array, where queries[i] = [xi, mi].

// The answer to the ith query is the maximum bitwise XOR value of xi and any
// element of nums that does not exceed mi. In other words, the answer is
// max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in
// nums are larger than mi, then the answer is -1.

// Return an integer array answer where answer.length == queries.length and
// answer[i] is the answer to the ith query.

// 1 <= nums.length, queries.length <= 105
// queries[i].length == 2
// 0 <= nums[j], xi, mi <= 109

// x[i] 11110001110011

class Solution {
 public:
  vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    sort(nums.begin(), nums.end());
    vector<int> res(queries.size(), 0);
    for (int i = 0; i < queries.size(); ++i) {
      int x = queries[i][0];
      int m = queries[i][1];
      int bitLength = sizeof(int) * 8 - 2;
      int best = 0;
      auto begin = nums.begin();
      auto upper = upper_bound(nums.begin(), nums.end(), m);
      if (upper == begin) {
        res[i] = -1;
        continue;
      }
      find(begin, upper, bitLength, x, best);
      res[i] = best ^ x;
    }
    return res;
  }

  void find(vector<int>::iterator& start, vector<int>::iterator& end,
            int bitIdx, int& x, int& best) {
    cout << best << "  " << bitIdx << endl;
    if (bitIdx < 0 || start == end) {

    };
    int lower, upper;
    if (((1 << bitIdx) & x) == 0) {
      // zero bit
      // find bound from [best + 1<< bitIdx to best + 1 << (bitIdx + 1) )
      int lower = best + (1 << bitIdx);
      int upper = best + getOneBitLength(bitIdx + 1);
      if (*start <= upper && lower <= *(end - 1)) {
        start = lower_bound(start, end, lower);
        end = upper_bound(start, end, upper);
        best += 1 << bitIdx;
      }
      find(start, end, bitIdx - 1, x, best);
    } else {
      // one bit
      int lower = best;
      int upper = best + (1 << bitIdx) - 1;
      if (*start <= upper && lower <= *(end - 1)) {
        start = lower_bound(start, end, lower);
        end = upper_bound(start, end, upper);
      } else {
        best += 1 << bitIdx;
      }
      find(start, end, bitIdx - 1, x, best);
    }
  }

  int getOneBitLength(int length) {
    int a = 1 << (length - 1);
    return a | (a - 1);
  }
};

// 0001 1100
// 0011
int main() {
  Solution s;
  vector<int> nums{5, 2, 4, 6, 6, 3};
  vector<vector<int>> queries{{12, 4}, {8, 1}, {6, 3}};
  auto res = s.maximizeXor(nums, queries);
  printVector(res);
}
