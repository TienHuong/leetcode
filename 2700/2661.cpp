#include "lib/lib.h"
#include "lib/stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-genetic-difference-query/description/
// There is a rooted tree consisting of n nodes numbered 0 to n - 1. Each node's
// number denotes its unique genetic value (i.e. the genetic value of node x is
// x). The genetic difference between two genetic values is defined as the
// bitwise-XOR of their values. You are given the integer array parents, where
// parents[i] is the parent for node i. If node x is the root of the tree, then
// parents[x] == -1.

// You are also given the array queries where queries[i] = [nodei, vali]. For
// each query i, find the maximum genetic difference between vali and pi, where
// pi is the genetic value of any node that is on the path between nodei and the
// root (including nodei and the root). More formally, you want to maximize vali
// XOR pi.

// Return an array ans where ans[i] is the answer to the ith query.

// 0
// 1    2
// 3
// 11110111

// 1 -- 2
// |
// 2

// 2 <= parents.length <= 105
// 0 <= parents[i] <= parents.length - 1 for every node i that is not the root.
// parents[root] == -1
// 1 <= queries.length <= 3 * 104
// 0 <= nodei <= parents.length - 1
// 0 <= vali <= 2 * 105

class Solution {
 public:
  int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    const int rowSize = mat.size();
    const int colSize = mat[0].size();
    const int size = rowSize * colSize * 2 + 2;
    int* v = (int*)calloc(size, sizeof(int));
    int* rCount = (int*)calloc(rowSize, sizeof(int));
    int* cCount = (int*)calloc(colSize, sizeof(int));
    for (int i = 0; i < rowSize; ++i) {
      for (int j = 0; j < colSize; ++j) {
        int tmp = mat[i][j] << 1;
        v[tmp] = i;
        v[tmp | 1] = j;
      }
    }
    for (int i = 0; i < arr.size(); ++i) {
      int tmp = arr[i] << 1;
      if (++rCount[v[tmp]] == colSize) return i;
      if (++cCount[v[tmp | 1]] == rowSize) return i;
    }
    free(v);
    free(rCount);
    free(cCount);
    return -1;
  }
};

// 0001 1100
// 0011
int main() {
  Solution s;
  vector<vector<int>> mat{{4, 3, 5}, {1, 2, 6}};
  vector<int> arr{1, 4, 5, 2, 6, 3};
  cout << s.firstCompleteIndex(arr, mat);
} /*  */
