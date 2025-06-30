class Solution {
public:

    int find(int x, vector<int>& parent){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = find(parent[x], parent);
    }

    bool Union(int x, int y, vector<int>& parent, vector<int>& rank){
        int parent_x = find(x, parent);
        int parent_y = find(y, parent);

        if(parent_x == parent_y)
            return false;

        int rank_x = rank[parent_x];
        int rank_y = rank[parent_y];

        if(rank_x > rank_y){
            parent[parent_y] = parent_x;
        }else if(rank_x < rank_y){
            parent[parent_x] = parent_y;
        }else{
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        vector<int> rank(n + 1, 0);

        // Initialize each node to be its own parent
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for(auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if(!Union(u, v, parent, rank)) {
                return edge; // found the redundant connection
            }
        }

        return {}; // shouldn't reach here if input is valid
    }
};