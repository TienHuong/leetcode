/**
https://leetcode.com/problems/number-of-flowers-in-full-bloom/description
You are given a 0-indexed 2D integer array flowers, where flowers[i] = [starti,
endi] means the ith flower will be in full bloom from starti to endi
(inclusive). You are also given a 0-indexed integer array people of size n,
where people[i] is the time that the ith person will arrive to see the flowers.

Return an integer array answer of size n, where answer[i] is the number of
flowers that are in full bloom when the ith person arrives. Constraints:

1 <= flowers.length <= 5 * 10^4
flowers[i].length == 2
1 <= starti <= endi <= 10^9
1 <= people.length <= 5 * 10^4
1 <= people[i] <= 10^9
a1 b1
a2 b2
a3 b3
a4 b4

*/

#include "lib/lib.h"
#include "lib/stdc++.h"
using namespace std;
class Solution {
 public:
  int upperBound(vector<int> &v, int target) {
    int from = 0, to = v.size(), mid;
    while (from < to) {
      mid = (from + to) >> 1;
      if (v[mid] <= target) {
        from = mid + 1;
      } else {
        to = mid;
      }
    }
    return from;
  }

  vector<int> fullBloomFlowers(vector<vector<int>> &flowers,
                               vector<int> &people) {
    int fs = flowers.size();
    vector<int> start(fs), end(fs);
    for (int i = 0; i < fs; ++i) {
      start[i] = flowers[i][0];
      end[i] = flowers[i][1];
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    vector<int> res(people.size());
    for (int i = 0; i < people.size(); ++i) {
      int startCnt = upperBound(start, people[i]);
      int endCount = upperBound(end, people[i] - 1);
      res[i] = (startCnt - endCount);
    }

    return res;
  }
};

int main() {
  ifstream input("input.txt");
  int size;
  input >> size;
  vector<vector<int>> v;
  int a, b;
  for (int i = 0; i < size; ++i) {
    input >> a >> b;
    v.push_back({a, b});
  }
  int pn;
  input >> pn;
  vector<int> people;
  for (int i = 0; i < pn; ++i) {
    input >> a;
    people.push_back(a);
  }
  input.close();

  Solution s;

  auto res = s.fullBloomFlowers(v, people);
  printVector<int>(res);
}
