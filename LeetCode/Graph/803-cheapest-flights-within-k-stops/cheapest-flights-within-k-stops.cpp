class Solution {
public:
    void bellman_ford(int s, vector<vector<int>>& edges, vector<long long>& dist, int k) {
        dist[s] = 0;

        for(int i = 1; i <= k + 1; i++) {
            vector<long long> temp_dist = dist;
            for(auto edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                if(dist[u] != 1e18 && dist[u] + w < temp_dist[v]) {
                    temp_dist[v] = dist[u] + w;
                }
            }
            dist = temp_dist;
        }
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<long long> dist(n, 1e18);
        bellman_ford(src, flights, dist, k);
        return dist[dst] == 1e18 ? -1 : dist[dst];
    }
};