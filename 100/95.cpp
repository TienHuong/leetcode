//https://leetcode.com/problems/unique-binary-search-trees-ii/description/
//95. Unique Binary Search Trees II
//
//Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.
//
//
//
//Example 1:
//
//
//Input: n = 3
//Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
//Example 2:
//
//Input: n = 1
//Output: [[1]]
//
//
//Constraints:
//
//1 <= n <= 8

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include "../lib/stdlib.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    map<pair<int, int>, vector<TreeNode *>> m;
public:
    vector<TreeNode *> generateTrees(int n) {
        return gen(1, n);
    }

    vector<TreeNode *> gen(int from, int to) {
        if (from > to) return {NULL};
        auto pair = make_pair(from, to);
        if (m.find(pair) != m.end()) {
            return m[pair];
        }
        vector<TreeNode *> v;
        for (int i = from; i <= to; ++i) {
            auto left = gen(from, i - 1);
            auto right = gen(i + 1, to);
            for (auto &il: left) {
                for (auto &ir: right) {
                    TreeNode *n = new TreeNode(i);
                    n->left = il;
                    n->right = ir;
                    v.push_back(n);
                }
            }
        }
        m[pair] = v;
        return v;
    }
};