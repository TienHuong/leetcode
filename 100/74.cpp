//https://leetcode.com/problems/search-a-2d-matrix/description/
//74. Search a 2D Matrix
//        You are given an m x n integer matrix matrix with the following two properties:
//
//Each row is sorted in non-decreasing order.
//The first integer of each row is greater than the last integer of the previous row.
//Given an integer target, return true if target is in matrix or false otherwise.
//
//You must write a solution in O(log(m * n)) time complexity.
//Constraints:
//
//m == matrix.length
//        n == matrix[i].length
//1 <= m, n <= 100
//-104 <= matrix[i][j], target <= 104

#include "../lib//stdlib.h"

class Solution {
private:
    int m;
    int n;
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        m = matrix.size();
        n = matrix[0].size();
        return find(matrix, 0, m * n - 1, target);
    }

    bool find(vector<vector<int>> &matrix, int from, int to, int &target) {
        if (from > to) return false;
        int middle = (from + to) / 2;
        int val = getVal(matrix, middle);
        if (val == target) return true;
        return val > target ? find(matrix, from, middle - 1, target) : find(matrix, middle + 1, to, target);
    }

    int getVal(vector<vector<int>> &matrix, int idx) {
        int r = idx / n;
        int c = idx % n;
        return matrix[r][c];
    }
};