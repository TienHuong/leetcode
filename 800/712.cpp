//712. Minimum ASCII Delete Sum for Two Strings
//Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.
//
//Ex1:
//Input: s1 = "sea", s2 = "eat"
//Output: 231
//Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
//Deleting "t" from "eat" adds 116 to the sum.
//At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
//Ex2:
//Input: s1 = "delete", s2 = "leet"
//Output: 403
//Explanation: Deleting "dee" from "delete" to turn the string into "let",
//adds 100[d] + 101[e] + 101[e] to the sum.
//Deleting "e" from "leet" adds 101[e] to the sum.
//At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
//If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
//
//Constraints:
//1 <= s1.length, s2.length <= 1000
//s1 and s2 consist of lowercase English letters.
#include "string"
#include "algorithm"
#include "vector"

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<int> res(s1.size() + 1, 0);

        for (int i = 1; i <= s1.size(); ++i) {
            res[i] = res[i - 1] + s1[i - 1];
        }

        for (int i = 0; i < s2.size(); ++i) {
            int prev = res[0];
            res[0] += s2[i];
            for (int j = 0; j < s1.size(); ++j) {
                int tmp = res[j + 1];
                if (s2[i] == s1[j]) {
                    res[j + 1] = prev;
                } else {
                    res[j + 1] = min(res[j] + s1[j], res[j + 1] + s2[i]);
                }
                prev = tmp;
            }
        }
        return res[s1.size()];
    }
};