class Solution {
public:
    int minMoves(vector<string>& grid, int energy) {
        int m = grid.size(), n = grid[0].size();

        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        int sr = -1, sc = -1;
        map<pair<int,int>, int> litterIndex;
        int idx = 0;

        // locate start + assign index to each L
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'S') {
                    sr = i; sc = j;
                }
                if (grid[i][j] == 'L') {
                    litterIndex[{i,j}] = idx++;
                }
            }
        }

        int totalMask = (1 << idx) - 1;

        // BFS queue: r, c, energy_left, mask, steps
        queue<tuple<int,int,int,int,int>> q;
        q.push({sr, sc, energy, 0, 0});

        // best[r][c][mask] = max energy seen
        vector<vector<vector<int>>> best(
            m, vector<vector<int>>(n, vector<int>(1 << idx, -1))
        );

        best[sr][sc][0] = energy;

        while (!q.empty()) {
            auto [r, c, e, mask, steps] = q.front();
            q.pop();

            if (mask == totalMask) return steps;

            // 🚫 If energy is 0 and not on R → cannot move further
            if (e == 0 && grid[r][c] != 'R') continue;

            for (auto &[dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;

                if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
                if (grid[nr][nc] == 'X') continue;

                int ne = e - 1;
                if (ne < 0) continue;

                // reset energy if stepping on R
                if (grid[nr][nc] == 'R') {
                    ne = energy;
                }

                int nmask = mask;

                // collect litter
                if (grid[nr][nc] == 'L') {
                    nmask |= (1 << litterIndex[{nr,nc}]);
                }

                // pruning
                if (best[nr][nc][nmask] >= ne) continue;

                best[nr][nc][nmask] = ne;
                q.push({nr, nc, ne, nmask, steps + 1});
            }
        }

        return -1;
    }
};