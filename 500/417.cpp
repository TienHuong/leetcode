#include "lib/lib.h"
#include "lib/stdc++.h"
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};


class Solution {
public:
    void check(vector<vector<int>>& heights, vector<vector<int>>& flag, vector<pair<int, int>>& q, int& x, int& y, int flagValue) {
        vector<pair<int, int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(q.size()) {
            auto top = q.back();
            q.pop_back();
            for(auto& dir: directions) {
                int newX = top.first + dir.first;
                int newY = top.second + dir.second;
                if (newX >= 0 && newX < x && newY >= 0 && newY < y) {
                    if ((flag[newX][newY] & flagValue) == 0 && heights[newX][newY] >= heights[top.first][top.second]) {
                        q.push_back({newX, newY});
                        flag[newX][newY] |= flagValue;
                    }
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int x = heights.size();
        int y = heights[0].size();
        vector<vector<int>> flag(x, vector<int>(y, 0));
        vector<pair<int, int>> q;
        for(int i = 0; i < x; ++i) {
            flag[i][0] |= 1;
            q.push_back({i, 0});
        }
        for(int j = 0; j < y; ++j) {
            flag[0][j] |= 1;
            q.push_back({0, j});
        }
        check(heights, flag, q, x, y, 1);

        for(int i = 0; i < x; ++i) {
            flag[i][y-1] |= 2;
            q.push_back({i, y-1});
        }
        for(int j = 0; j < y; ++j) {
            flag[x-1][j] |= 2;
            q.push_back({x-1, j});
        }
        check(heights, flag, q, x, y, 2);

        printMatrix(flag);
        vector<vector<int>> res;
        for(int i = 0; i < x; ++i) {
            for(int j = 0; j < y; ++j) {
                if (flag[i][j] ==3) {
                    res.push_back({i, j});
                }
            }
        }
        return res;

    }
};

int main() {
  Solution s;
  vector<vector<int>> v {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
  auto res = s.pacificAtlantic(v);
  printMatrix(res);
  return 0;
}

// 2 10 11 11