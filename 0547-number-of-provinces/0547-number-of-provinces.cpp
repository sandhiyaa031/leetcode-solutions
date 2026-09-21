class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjL, vector<int> &vis){
            vis[node] = 1;
            for(auto it : adjL[node]){
                if(!vis[it]){
                    dfs(it, adjL, vis);
                }
            }
        }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adjL(V);

        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(isConnected[i][j] == 1 && i!= j){
                    adjL[i].push_back(j);
                    adjL[j].push_back(i);
                }
            }
        }

        vector <int> vis(V, 0);
        int cnt = 0;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, adjL, vis);
            }
        }
    return cnt;
    }
};