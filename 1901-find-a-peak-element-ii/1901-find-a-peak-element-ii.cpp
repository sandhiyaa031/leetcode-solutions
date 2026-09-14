class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int low = 0;
        int high = n - 1;

        while(low <= high){
            int mid = low + (high - low)/2;
            int maxrow = 0;
            for(int i = 1; i < m; i++){
                if(mat[i][mid] > mat[maxrow][mid]){
                    maxrow = i;
                }
            }

            int current = mat[maxrow][mid];

            int left = (mid == 0) ? -1 : mat[maxrow][mid - 1];
            int right = (mid == n - 1) ? -1 : mat[maxrow][mid + 1];

            if(current > right && current > left){
                return {maxrow, mid};
            }
            else if(right > current){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    return {-1, -1};
    }
};