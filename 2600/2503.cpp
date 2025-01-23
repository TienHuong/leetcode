#include "lib/lib.h"
#include "lib/stdc++.h"
using namespace std;

/**
 * We will build threshold t1, t2, ..., tn, count c1, c2, ..., cn
 * if t1 < query value =< t2, answer is c2
 *
 */

typedef vector<vector<int>> vvi;

class Comparison {
  vvi* grid;

 public:
  Comparison(vvi* gridParam) { grid = gridParam; }
  bool operator()(const array<int, 2>& lhs, const array<int, 2>& rhs) const {
    return (*grid)[lhs[0]][lhs[1]] > (*grid)[rhs[0]][rhs[1]];
  }
};

class Solution {
 private:
  vvi directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

 public:
  vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
    vector<pair<int, int>> mQueries;
    for (int i = 0; i < queries.size(); ++i) {
      mQueries.push_back({queries[i], i});
    }
    sort(mQueries.begin(), mQueries.end(), less());

    const int rSize = grid.size();
    const int cSize = grid[0].size();
    vector<vector<bool>> visited(rSize, vector<bool>(cSize, false));
    Comparison comp(&grid);
    priority_queue<array<int, 2>, vector<array<int, 2>>, Comparison> pq(comp);
    int threshold = grid[0][0];
    int count = 0;
    pq.push({0, 0});
    visited[0][0] = true;
    vector<int> answer(queries.size(), 0);
    int qIdx = 0;
    updateAnswer(answer, mQueries, qIdx, threshold, count);
    while (pq.size() > 0) {
      auto top = pq.top();
      pq.pop();
      int x = top[0];
      int y = top[1];
      if (grid[x][y] > threshold) {
        threshold = grid[x][y];
        updateAnswer(answer, mQueries, qIdx, threshold, count);
      }
      ++count;
      for (int i = 0; i < 4; ++i) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];

        if (newX >= 0 && newX < rSize) {
          if (newY >= 0 && newY < cSize) {
            if (visited[newX][newY]) continue;
            visited[newX][newY] = true;
            pq.push({newX, newY});
          }
        }
      }
    }
    updateAnswer(answer, mQueries, qIdx, 10000001, count);
    return answer;
  }

  void updateAnswer(vector<int>& answer, vector<pair<int, int>>& mQueries,
                    int& idx, int threshold, int& count) {
    while (idx < answer.size() && mQueries[idx].first <= threshold) {
      answer[mQueries[idx].second] = count;
      ++idx;
    }
  }
};
// 1 2 3
// 3 4 5
// 8 2 1
// 0001 1100
// 0011
int main() {
  Solution s;
  vvi grid{{1, 2, 3}, {2, 5, 7}, {3, 5, 1}};

  vector<int> queries{0, 5, 6, 2, 10};
  auto a = s.maxPoints(grid, queries);
  printVector(a);
} /*  */
