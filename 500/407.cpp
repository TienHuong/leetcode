#include "lib/lib.h"
#include "lib/stdc++.h"
using namespace std;

const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

typedef vector<vector<int>> vvi;

class Comparison {
 public:
  bool operator()(const array<int, 3>& lhs, const array<int, 3>& rhs) const {
    return lhs[2] > rhs[2];
  }
};

typedef priority_queue<array<int, 3>, vector<array<int, 3>>, Comparison> pq;

class Solution {
 private:
  vvi directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

 public:
  int trapRainWater(vector<vector<int>>& heightMap) {
    const int rowSize = heightMap.size();
    const int colSize = heightMap[0].size();
    if (rowSize <= 2 || colSize <= 2) return 0;
    Comparison comp;
    pq myQueue(comp);
    int* visited = (int*)calloc(rowSize * colSize, sizeof(int));
    for (int i = 0; i < rowSize; ++i) {
      myQueue.push({i, 0, heightMap[i][0]});
      visited[i * colSize] = 1;
      myQueue.push({i, colSize - 1, heightMap[i][colSize - 1]});
      visited[i * colSize + colSize - 1] = 1;
    }
    for (int j = 1; j < colSize - 1; ++j) {
      myQueue.push({0, j, heightMap[0][j]});
      visited[j] = 1;
      myQueue.push({rowSize - 1, j, heightMap[rowSize - 1][j]});
      visited[(rowSize - 1) * colSize + j] = 1;
    }
    int res = 0;
    while (myQueue.size() > 0) {
      auto lowest = myQueue.top();
      myQueue.pop();
      // bfs(heightMap, lowest, res, visited, myQueue, colSize, rowSize);
      for (int i = 0; i < 4; ++i) {
        int x = lowest[0] + directions[i][0];
        int y = lowest[1] + directions[i][1];
        if (x >= 0 && x < rowSize && y >= 0 && y < colSize) {
          if (visited[x * colSize + y] == 1) continue;
          visited[x * colSize + y] = 1;
          if (heightMap[x][y] <= lowest[2]) {
            res += lowest[2] - heightMap[x][y];
            myQueue.push({x, y, lowest[2]});
          } else {
            myQueue.push({x, y, heightMap[x][y]});
          }
        }
      }
    }
    return res;
  }
};