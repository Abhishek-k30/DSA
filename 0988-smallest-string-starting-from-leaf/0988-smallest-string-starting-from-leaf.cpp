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
public:
    string ans="";
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
    
    void dfs(TreeNode* root, string s){
        if(root->left==NULL && root->right==NULL){
            s+='a'+ (root->val);
            reverse(s.begin(), s.end());
            if(ans=="")ans=s;
            else if(ans>s)ans=s;
            //else if(ans.size()>s.size())ans=s;
            return;
        }
        if(root->left)dfs(root->left, s+char('a'+(root->val)));
        if(root->right)dfs(root->right, s+char('a'+(root->val)));
    }
};