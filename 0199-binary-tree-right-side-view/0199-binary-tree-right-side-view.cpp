/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void solve(TreeNode* root, int level, vector<int>&nodes){
        if(!root)return ;
        if(nodes.size() == level)nodes.push_back(root->val);
        solve(root->right, level+1, nodes);
        solve(root->left, level+1, nodes);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> nodes;
        solve(root, 0, nodes);
        return nodes;
    }
};