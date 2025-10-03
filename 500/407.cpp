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
  int trapRainWater(vector<vector<int>>& heightMap) {
    int x = heightMap.size();
    int y = heightMap[0].size();
    vector<vector<bool>> visited(x, vector<bool>(y, false));
    vector<pair<int, int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    auto comp = [&heightMap](pair<int, int>& a, pair<int, int>& b) {
      return heightMap[a.first][a.second] > heightMap[b.first][b.second];
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(
        comp);

    for (int i = 0; i < x; ++i) {
      pq.push({i, 0});
      visited[i][0] = true;
      if (y > 1) {
        pq.push({i, y - 1});
        visited[i][y - 1] = true;
      }
    }
    for (int j = 1; j < y - 1; ++j) {
      pq.push({0, j});
      visited[0][j] = true;
      if (x > 1) {
        pq.push({x - 1, j});
        visited[x - 1][j] = true;
      }
    }

    int res = 0;

    while (pq.size() > 0) {
      auto top = pq.top();
      pq.pop();
      vector<pair<int, int>> l;
      l.push_back(top);
      while (l.size() > 0) {
        auto back = l.back();
        l.pop_back();
        res += heightMap[top.first][top.second] -
        heightMap[back.first][back.second];
        for (auto& dir : direction) {
          int newX = back.first + dir.first;
          int newY = back.second + dir.second;
          if (newX >= 0 && newX < x && newY >= 0 && newY < y &&
              !visited[newX][newY]) {
            visited[newX][newY] = true;
            if (heightMap[newX][newY] <= heightMap[top.first][top.second]) {
              l.push_back({newX, newY});
            } else {
              pq.push({newX, newY});
            }
          }
        }
      }
    }

    return res;
  }
};

int main() {
  vector<vector<int>> v {
    {1,3,3,1,3,2},
    {3,2,1,3,2,3},
    {3,3,3,2,3,1}
  };
  Solution s;
  s.trapRainWater(v);
  return 0;
}

// 2 10 11 11