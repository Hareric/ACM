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
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        // write your code here
        if (s==NULL){
            return false;
        }
        if(s==t){
            return true;
        }
        if(s->neighbors.size()>0){
            for(int i=0; i<s->neighbors.size(); i++){
                if(hasRoute(graph, s->neighbors[i], t)){
                    return true;
                    break;
                }
                else{
                    s->neighbors[i] = NULL;
                    continue;
                }
            }
        }
        return false;

    }
};

