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
    unordered_map<long, int> m;
    int ans=0;
    void dfs(TreeNode* root, int target, long long sum){
        if(!root)return;
        
        sum+= root->val;
        if(sum==target)ans++;
        if(m.find(sum-target)!=m.end())ans+= m[sum-target];
        m[sum]++;
        if(root->left)dfs(root->left, target, sum);
        if(root->right)dfs(root->right, target, sum);
        m[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        long long st=0;
         dfs(root, targetSum, st);
         return ans;
    }
};