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
    int height[100001];
    int level[100001];
    int levelMxHt[100001];
    int levelSecondMxHt[100001];
    
    int findHeight(TreeNode* root, int l){
        if(!root){
            return 0;
        }
        
        level[root->val] = l;
        height[root->val] = 1 + 
            max(findHeight(root->left, l+1), findHeight(root->right, l+1));
        
        if(height[root->val]> levelMxHt[l]){
            levelSecondMxHt[l] = levelMxHt[l];
            levelMxHt[l] = height[root->val];
        }
        else if(height[root->val]> levelSecondMxHt[l]){
            levelSecondMxHt[l] = height[root->val];
        }
        
        return height[root->val];
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
         findHeight(root, 0);
        
        vector<int> ans;
        
        for(auto &node : queries){
            int L = level[node];
            int H = (levelMxHt[L] == height[node] ? levelSecondMxHt[L] : levelMxHt[L]);
            
            int res = L + H - 1;
            ans.push_back(res);
        }
        
        return ans;
    }
};