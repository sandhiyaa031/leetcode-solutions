class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        int bestRow = 0;
        int maxOnes = 0;

        for(int i = 0; i < m; i++) {

            int ones = 0;

            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1)
                    ones++;
            }

            if(ones > maxOnes) {
                maxOnes = ones;
                bestRow = i;
            }
        }

        return {bestRow, maxOnes};
    }
};