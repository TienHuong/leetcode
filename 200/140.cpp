//140. Word Break II
//        Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.
//
//Note that the same word in the dictionary may be reused multiple times in the segmentation.
//
//
//
//Example 1:
//
//Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
//Output: ["cats and dog","cat sand dog"]
//Example 2:
//
//Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
//Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
//Explanation: Note that you are allowed to reuse a dictionary word.
//Example 3:
//
//Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
//Output: []
//
//
//Constraints:
//
//1 <= s.length <= 20
//1 <= wordDict.length <= 1000
//1 <= wordDict[i].length <= 10
//s and wordDict[i] consist of only lowercase English letters.
//All the strings of wordDict are unique.
//Input is generated in a way that the length of the answer doesn't exceed 105.

#include "../lib/stdlib.h"

class Solution {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> us;
        unordered_map<int, vector<string>> um;
        int maxLength = 0;
        for (auto &w: wordDict) {
            maxLength = maxLength < w.size() ? w.size() : maxLength;
            us.insert(w);
        }

        um[-1] = {""};
        for(int i = 0; i < s.size(); ++i) {
            int j = j - maxLength + 1;
            if (j < 0) j = 0;
            um[i] = {};
            for(; j <= i; ++j) {
                vector<string> prev = um.at(j-1);
                if (prev.size() == 0) continue;

                string sub = s.substr(j, i - j + 1);
                if (us.find(sub) != us.end()) {
                    if ( j == 0) {
                        um[i].push_back(sub);
                    } else {
                        for(auto& it: prev) {
                            um[i].push_back(it + " " + sub);
                        }
                    }

                }
            }
        }

        return um[s.size() - 1];
    }
};
