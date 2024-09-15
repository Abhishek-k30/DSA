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
    bool search(TreeNode* root, int tar){
        if(!root){
            return false;
        }
        
        if(root->val == tar){
            return true;
        }
        
        if(root->val<tar){
            return search(root->right, tar);
        }
        else {
            return search(root->left, tar);
        }
    }
    void inorderTraversal(TreeNode* root, vector<int>&val){
        if(!root)return ;
        inorderTraversal(root->left, val);
        val.push_back(root->val);
        inorderTraversal(root->right, val);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        
        int i = 0, j = inorder.size()-1;
        
        while(i<j){
            int sum = inorder[i] + inorder[j];
            if(sum == k){
                return true;
            }
            else if(sum > k){
                j--;
            }
            else i++;
        }
        return false;
    }
};