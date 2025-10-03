#include "lib/lib.h"
#include "lib/stdc++.h"
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};


#define ll long long
class Solution {
public:
    ll gcd(ll a, ll b) {
        if (a == b) return a;
        return a > b ? gcd(a-b, b) : gcd(a, b-a);
    }

    int subNthMagicalNumber(ll n, ll a, ll b, ll from, ll to) {
        if (n == 0) return 0;
        if (from > to) return from;
        ll mid = (from + to)/2;
        ll cnt = mid /a  + mid / b;
        if (n > cnt) return subNthMagicalNumber(n, a, b, mid + 1, to);
        else return subNthMagicalNumber(n, a, b, from, mid - 1);
    } 

    int nthMagicalNumber(int n, int a, int b) {
        ll mod = 1e9 + 7;
        ll g = gcd(a, b);
        ll lcd = a * (b/g); 
        // count from 1 -> lcd
        ll count = lcd / a + lcd / b - 1;

        ll repeat = n / count;

        ll remain = n % count;

        return ((repeat * lcd) + subNthMagicalNumber(remain, a, b, 1, lcd)) %mod;
    }
};

int main() {
  Solution s;
  cout << s.nthMagicalNumber(1, 2, 3);
  return 0;
}

// 2 10 11 11