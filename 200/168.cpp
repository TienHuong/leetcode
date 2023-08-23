//https://leetcode.com/problems/excel-sheet-column-title/
//Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.
//
//For example:
//
//A -> 1
//B -> 2
//C -> 3
//...
//Z -> 26
//AA -> 27
//AB -> 28
//...
//
//
//Example 1:
//
//Input: columnNumber = 1
//Output: "A"
//Example 2:
//
//Input: columnNumber = 28
//Output: "AB"
//Example 3:
//
//Input: columnNumber = 701
//Output: "ZY"
//
//
//Constraints:
//
//1 <= columnNumber <= 2^31 - 1

#include "../lib/stdlib.h"

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s;
        vector<char> v { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
        while(columnNumber > 0) {
            int tmp = columnNumber / 26;
            int remain = columnNumber - tmp * 26;
            if (remain == 0) {
                remain = 26;
                columnNumber = tmp - 1;
            } else {
                columnNumber = tmp;
            }
            s.push_back(v[remain - 1]);
        }
        std::reverse(s.begin(), s.end());
        return s;
    }
};


class ShortSolution {
public:
    string convertToTitle(int columnNumber) {
        string s;
        vector<char> v { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
        while(columnNumber > 0) {
            columnNumber -= 1;
            s.push_back(v[columnNumber % 26]);
            columnNumber /= 26;
        }
        std::reverse(s.begin(), s.end());
        return s;
    }
};
