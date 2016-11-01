/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> sortVec;
    set<int> s;
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        for (int i=0; i<graph.size(); i++){
            if(s.find(graph[i]->label)!=s.end()){
                continue;
            }
            
            s.insert(graph[i]->label);
            topSort(graph[i]->neighbors);
            sortVec.insert(sortVec.begin(),graph[i]);
        }
        return sortVec;
        
    }
};
