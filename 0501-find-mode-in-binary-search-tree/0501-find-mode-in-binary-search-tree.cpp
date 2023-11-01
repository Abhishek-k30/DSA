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
    int maxfreq=0, currfreq=0, pre=INT_MIN;
    vector<int> result;
    vector<int> findMode(TreeNode* root) {
        inorderedTraversal(root);
        return result;
    }
    
    // Inordered Traversal. As inorder traversal of bst gives ans in ascending order.
    void inorderedTraversal(TreeNode * root){
        
        if(root==NULL)return;
        inorderedTraversal(root->left);
        if(pre==root->val)currfreq++;
        else currfreq=1;
        
        if(currfreq>maxfreq){
            result.clear();
            maxfreq=currfreq;
            result.push_back(root->val);
        }
        else if(currfreq==maxfreq){
           result.push_back(root->val);
        }
        
        pre=root->val;
        inorderedTraversal(root->right);
        
    }
};

//TC=O(N), SC=O(1)