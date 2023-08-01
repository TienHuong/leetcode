//Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
//
//You may return the answer in any order.
//
//
//
//Example 1:
//
//Input: n = 4, k = 2
//Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
//Explanation: There are 4 choose 2 = 6 total combinations.
//Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
//Example 2:
//
//Input: n = 1, k = 1
//Output: [[1]]
//Explanation: There is 1 choose 1 = 1 total combination.
//
//
//Constraints:
//
//1 <= n <= 20
//1 <= k <= n

#include "vector"

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> v(k + 1, 0);
        v[k] = n + 1;
        for (int i = 0; i < k; ++i) {
            v[i] = i + 1;
        }

        bool loop;
        do {
            loop = false;
            vector<int> cp(v.begin(), v.end() - 1);
            res.push_back(cp);
            for (int i = v.size() - 2; i >= 0; --i) {
                if ((v[i] + 1) < v[i + 1]) {
                    v[i] += 1;
                    for (int j = i + 1; j < v.size() - 1; ++j) {
                        v[j] = v[j - 1] + 1;
                    }
                    loop = true;
                    break;
                }
            }
        } while (loop);

        return res;
    }
};