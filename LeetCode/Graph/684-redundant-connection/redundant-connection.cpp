class Solution {
public:
    struct DSU {
        vector<int> parent, componentSize;

        DSU() {}
        DSU(int n) {
            init(n);
        }

        void init(int n) {
            parent.resize(n + 1);
            iota(parent.begin(), parent.end(), 0);
            componentSize.assign(n + 1, 1);
        }

        int find(int x) {
            while(x != parent[x]) {
                x = parent[x] = parent[parent[x]];
            }
            return x;
        }

        bool same(int x, int y) {
            return find(x) == find(y);
        }

        bool merge(int x, int y) {
            x = find(x);
            y = find(y);
            if(x == y) {
                return false;
            }
            componentSize[x] += componentSize[y];
            parent[y] = x;
            return true;
        }

        int size(int x) {
            return componentSize[find(x)];
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        vector<int> ans;
        for(int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            if(!dsu.merge(a, b)) {
                ans = {a, b};
                break;
            }
        }

        return ans;
    }
};