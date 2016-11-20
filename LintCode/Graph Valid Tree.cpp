class Solution {
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    
    void DFS(int i, vector<vector<int>>& edges, vector<bool>& used){
        if(used[i]==true){
            return;
        }
        used[i] = true;
        for(int e=0; e<edges.size(); e++){
            if(edges[e][0]==i){
                DFS(edges[e][1], edges, used);
            }
            else if(edges[e][1]==i){
                DFS(edges[e][0], edges, used);
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        // Write your code here
        if (edges.size()+1==n){
            vector<bool> used(n, false);
            DFS(0, edges, used);
            for(int i=0; i<n; i++){
                if(used[i]==false){
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};
