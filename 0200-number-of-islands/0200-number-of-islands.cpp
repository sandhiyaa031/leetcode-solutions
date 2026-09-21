class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {

                if(grid[r][c] == '1') {
                    count++;

                    queue<pair<int,int>> q;
                    q.push({r, c});
                    grid[r][c] = '0';

                    while(!q.empty()) {
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();

                        for(int k = 0; k < 4; k++) {
                            int nr = row + dr[k];
                            int nc = col + dc[k];

                            if(nr >= 0 && nr < m &&
                               nc >= 0 && nc < n &&
                               grid[nr][nc] == '1') {

                                grid[nr][nc] = '0';
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};