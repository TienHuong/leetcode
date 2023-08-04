// https://leetcode.com/problems/concatenated-words/
//472. Concatenated Words
//
//Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.
//
//A concatenated word is defined as a string that is comprised entirely of at least two shorter words (not necesssarily distinct) in the given array.
//
//
//
//Example 1:
//
//Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
//Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
//Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";
//"dogcatsdog" can be concatenated by "dog", "cats" and "dog";
//"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
//Example 2:
//
//Input: words = ["cat","dog","catdog"]
//Output: ["catdog"]
//
//
//Constraints:
//
//1 <= words.length <= 104
//1 <= words[i].length <= 30
//words[i] consists of only lowercase English letters.
//All the strings of words are unique.
//1 <= sum(words[i].length) <= 105
#include "../lib/stdlib.h"
#include "../lib/lib.h"

class Solution {
private:
    unordered_set<string> us;
    int maxLength = 0;
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {

        for(auto& w: words) {
            maxLength = maxLength > w.size() ? maxLength : w.size();
            us.insert(w);
        }

        vector<string> res;
        for(auto& w: words) {
            int c = findWordCount(w, words);
            if (c >= 2) res.push_back(w);
        }

        return res;
    }

    int findWordCount(string& s, vector<string>& words) {
        vector<int> ok(s.size() + 1, -1);
        ok[0] = 0;
        for(int i = 0; i < s.size(); ++i) {
            int j = i - maxLength;
            if (j < 0) {
                j = s.size() == i + 1 ? 1 : 0;
            }

            for(; j <= i; ++j) {
                if (us.find(s.substr(j, i - j + 1)) != us.end() && ok[j] >= 0) {
                    ok[i+1] = ok[j] + 1;
                    break;
                }
            }
        }
        return ok[s.size()];
    }
};
