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
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> parent(n);
        vector<int> rank(n,0);
        for(int i = 0; i<n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            Union(u, v, parent, rank);
        }
        return find(source, parent) == find(destination, parent);
    }


};