//17. Letter Combinations of a Phone Number

//Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
//
//A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
//
//
//
//
//Example 1:
//
//Input: digits = "23"
//Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
//Example 2:
//
//Input: digits = ""
//Output: []
//Example 3:
//
//Input: digits = "2"
//Output: ["a","b","c"]
//
//
//Constraints:
//
//0 <= digits.length <= 4
//digits[i] is a digit in the range ['2', '9'].

#include "map"
#include "string"
#include "vector"

using namespace std;

const map<char, vector<char>> m = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}},
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size() == 0) return res;
        string cur = digits;
        gen(0, digits, res, cur);
        return res;
    }

    void gen(int idx, string &digits, vector<string> &res, string &cur) {
        for (auto &c: m.at(digits[idx])) {
            cur[idx] = c;
            if (idx == (digits.size() - 1)) {
                res.push_back(cur);
            } else {
                gen(idx + 1, digits, res, cur);
            }
        }
    }
};

class BtSolution {
private:
    vector<string> res;
    string tmp;
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return res;
        bt(0, digits);
        return res;
    }

    void bt(int idx, string &digits) {
        if (tmp.size() == digits.size()) {
            res.push_back(tmp);
        } else {
            for (auto &c: m.at(digits[idx])) {
                tmp.push_back(c);
                bt(idx + 1, digits);
                tmp.pop_back();
            }
        }
    }
};
