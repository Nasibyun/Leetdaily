class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        vector<vector<int>> id(m, vector<int>(n, -1));

        int sx, sy, cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                } else if (classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        if (cnt == 0) return 0;

        int fullMask = (1 << cnt) - 1;

        vector<vector<vector<vector<bool>>>> vis(
            m, vector<vector<vector<bool>>>(
                n, vector<vector<bool>>(
                    energy + 1, vector<bool>(1 << cnt, false)
                )
            )
        );

        queue<tuple<int,int,int,int>> q;
        q.push({sx, sy, energy, fullMask});
        vis[sx][sy][energy][fullMask] = true;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [x, y, e, mask] = q.front();
                q.pop();

                if (mask == 0) return moves;
                if (e == 0) continue;

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;

                    if (classroom[nx][ny] == 'X')
                        continue;

                    int ne = classroom[nx][ny] == 'R' ? energy : e - 1;
                    int nm = mask;

                    if (classroom[nx][ny] == 'L')
                        nm &= ~(1 << id[nx][ny]);

                    if (!vis[nx][ny][ne][nm]) {
                        vis[nx][ny][ne][nm] = true;
                        q.push({nx, ny, ne, nm});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};