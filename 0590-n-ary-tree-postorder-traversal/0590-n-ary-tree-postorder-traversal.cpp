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
private:
    void solve(Node* root, vector<int>&traversalRecords){
        if(!root){
            return;
        }
        for(int i = 0 ; i<root->children.size(); i++){
            if(root->children[i])solve(root->children[i], traversalRecords);
        }
        traversalRecords.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> traversalRecords;
        solve(root,traversalRecords);
        return traversalRecords;
    }
};