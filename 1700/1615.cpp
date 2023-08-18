//https://leetcode.com/problems/maximal-network-rank/description/
//There is an infrastructure of n cities with some number of roads connecting these cities. Each roads[i] = [ai, bi] indicates that there is a bidirectional road between cities ai and bi.
//
//The network rank of two different cities is defined as the total number of directly connected roads to either city. If a road is directly connected to both cities, it is only counted once.
//
//The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities.
//
//Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.
//
//
//
//Example 1:
//
//
//
//Input: n = 4, roads = [[0,1],[0,3],[1,2],[1,3]]
//Output: 4
//Explanation: The network rank of cities 0 and 1 is 4 as there are 4 roads that are connected to either 0 or 1. The road between 0 and 1 is only counted once.
//Example 2:
//
//
//
//Input: n = 5, roads = [[0,1],[0,3],[1,2],[1,3],[2,3],[2,4]]
//Output: 5
//Explanation: There are 5 roads that are connected to cities 1 or 2.
//Example 3:
//
//Input: n = 8, roads = [[0,1],[1,2],[2,3],[2,4],[5,6],[5,7]]
//Output: 5
//Explanation: The network rank of 2 and 5 is 5. Notice that all the cities do not have to be connected.
//
//
//Constraints:
//
//2 <= n <= 100
//0 <= roads.length <= n * (n - 1) / 2
//roads[i].length == 2
//0 <= ai, bi <= n-1
//ai != bi
//        Each pair of cities has at most one road connecting them.

#include "../lib/stdlib.h"

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> s(n+1, vector<int>(n+1, 0));
        vector<int> count(n+1, 0);
        for(auto& road: roads) {
            s[road[0]][road[1]] = 1;
            s[road[1]][road[0]] = 1;
            count[road[0]] += 1;
            count[road[1]] += 1;
        }
        int res = 0;
        for(int i = 0; i <= n; ++i) {
            for(int j = i +1; j <= n; ++j) {
                res = max(count[i] + count[j] - s[i][j], res);
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> v  {{11,8},{0,1},{10,16},{5,1},{14,6},{5,3},{8,1},{5,6},{6,2},{6,15},{6,8},{11,7},{13,5},{5,7},{7,4},{3,15},{11,16},{8,9},{11,3},{12,15},{13,6},{12,6},{15,8},{0,13},{11,9},{0,5},{8,14},{16,1},{2,0},{15,11},{16,2},{11,2},{16,12},{8,4},{15,16},{16,6},{2,1},{10,11},{12,7},{9,12},{1,12},{15,14},{8,3},{0,8},{10,13},{4,0},{11,1},{6,7},{9,0},{3,16},{0,11},{2,8},{12,5},{16,5},{12,0},{9,5},{4,15},{15,0},{0,3},{15,7},{16,9},{16,8},{3,13},{12,3},{14,3},{1,13},{10,8},{8,13},{7,14},{14,1},{7,2},{1,7},{5,15},{3,10},{4,1},{0,14},{1,9},{14,13},{7,0},{6,0},{16,4},{12,11},{4,9},{13,15},{2,3},{10,15},{11,6},{5,4},{7,16},{6,9},{14,10},{5,10},{10,2},{10,7},{10,9}};
    Solution s;
    cout << s.maximalNetworkRank(17, v);
}