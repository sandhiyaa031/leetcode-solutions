class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int color, int dr[], int dc[], int inicolor){
        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        for(int i = 0; i < 4; i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == inicolor && ans[nrow][ncol]!= color){
                dfs(nrow, ncol, ans, image, color, dr, dc, inicolor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor = image[sr][sc];
        vector <vector<int>> ans = image;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        dfs(sr, sc, ans, image, color, dr, dc, inicolor);
        return ans;

    }
};