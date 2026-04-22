class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[2000];
        vector<int> indegree(2000);
        for(auto vec : prerequisites) {
            adj[vec[1]].push_back(vec[0]);
            indegree[vec[0]]++;
        }
        vector<int> ans;
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for(auto v : adj[u]) {
                if(--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        if(ans.size() == numCourses) {
            return ans;
        } else {
            return vector<int>{};
        }
    }
};