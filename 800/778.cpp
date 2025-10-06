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


class UnionFind {
private:
    int size;
    int *component;
    int *count;

public:
    UnionFind(int size) : size(size), component(new int[size]), count(new int[size]) {
        for (int i = 0; i < this->size; ++i) {
            this->component[i] = i;
            this->count[i] = 1;
        }
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    void join(int p, int q) {
        auto rp = find(p);
        auto rq = find(q);
        if (rp == rq) return;
        if (count[rp] > count[rq]) {
            this->count[rp] += count[rq];
            component[rq] = rp;
        } else {
            count[rq] += count[rp];
            component[rp] = rq;
        }
    }

    int find(int p) {
        if (p == component[p]) return p;
        return component[p] = find(component[p]);
    }

    void toString() {
        for (int i = 0; i < size; ++i) {
            cout << i << ": " << component[i] << " | ";
        }
        cout << endl;
    }
};

class Solution {
public:
    int getComp(int& x, int& y, int& colNum) {
        return x * colNum + y;
    }

    int swimInWater(vector<vector<int>>& grid) {

        vector<pair<int, int>> vp;

        vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int x = grid.size();
        int y = grid[0].size();
        for(int i = 0; i < x; ++i) {
            for(int j = 0; j < y; ++j) {
                vp.push_back({i, j});
            }
        }

        sort(vp.begin(), vp.end(), [&grid](const pair<int, int>& p1, const pair<int, int>& p2) {
            return grid[p1.first][p1.second] < grid[p2.first][p2.second];
        });
        int waterLevel = 0;
        UnionFind uf(x * y);

        int start = 0, end = x * y - 1;
        vector<bool> visited(x * y, false);
        for(int i = 0; i < vp.size(); ++i) {
            int comp = getComp(vp[i].first, vp[i].second, y);
            visited[comp] = true;
            for(auto& dir: directions) {
                int newX = vp[i].first + dir.first;
                int newY = vp[i].second + dir.second;

               
                if (newX >= 0 && newX < x && newY >= 0 && newY < y) {
                    int rComp = getComp(newX, newY, y);
                    if (visited[rComp]) uf.join(comp, rComp);
                }
            }
            if (uf.connected(start, end)) break;
            ++waterLevel;
        }
        return waterLevel;
    }
};

int main() {
  Solution s;
  vector<vector<int>> v {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
  cout << s.swimInWater(v);
  return 0;
}

// 2 10 11 11