class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector <int> &pathvis){
        vis[node] = 1;
        pathvis[node] = 1;
        for(auto neighbour : adj[node]){
            if(!vis[neighbour]){
                if(dfs(neighbour, adj, vis, pathvis)){
                    return true;
                }
            }
            else if(pathvis[neighbour]){
                return true;
            }
        }
        pathvis[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto p : prerequisites) {

            int course = p[0];
            int prerequisite = p[1];

            adj[prerequisite].push_back(course);
    }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for(int i = 0; i < numCourses; i++) {

            if(!vis[i]) {

                if(dfs(i, adj, vis, pathVis)) {
                    return false;
            }
        }
    }

    return true;
    }
};