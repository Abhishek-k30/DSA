/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> cur;
            for(int i = 0; i<size; i++){
                Node* curNode = q.front();
                q.pop();
                cur.push_back(curNode->val);
                for(int j = 0; j<curNode->children.size(); j++){
                    if(curNode->children[j])q.push(curNode->children[j]);
                }
            }
            ans.push_back(cur);
        }
        
        return ans;
    }
};