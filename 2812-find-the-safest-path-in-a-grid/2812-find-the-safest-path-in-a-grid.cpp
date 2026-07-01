#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return 0;
        vector<vector<int>> d(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    d[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && d[nx][ny] == -1) {
                    d[nx][ny] = d[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> mx(n, vector<int>(n, -1));
        pq.push({d[0][0], {0, 0}});
        mx[0][0] = d[0][0];
        while(!pq.empty()) {
            auto [v, p] = pq.top();
            auto [x, y] = p;
            pq.pop();
            if(x == n - 1 && y == n - 1) return v;
            if(v < mx[x][y]) continue;
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    int nv = min(v, d[nx][ny]);
                    if(nv > mx[nx][ny]) {
                        mx[nx][ny] = nv;
                        pq.push({nv, {nx, ny}});
                    }
                }
            }
        }
        return 0;
    }
};