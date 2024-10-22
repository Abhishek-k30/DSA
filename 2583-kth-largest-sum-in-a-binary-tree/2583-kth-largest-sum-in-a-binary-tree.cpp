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
#define ll long long
class Solution {
private:
    vector<ll> solve(TreeNode* root){
        vector<ll> pathSum;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            ll sum = 0;
            
            int sz = q.size();
            
            while(sz--){
                TreeNode* cur = q.front();
                ll curVal = q.front()->val;
                sum += curVal;
                
                if(cur->left!=NULL){
                    q.push(cur->left);
                }
                
                if(cur->right!=NULL){
                    q.push(cur->right);
                }
                
                q.pop();
            }
            
            pathSum.push_back(sum);
        }
        
        return pathSum;
    }
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<ll> pathSum = solve(root);
        
        if(pathSum.size()<k){
            return -1;
        }
        
        sort(pathSum.begin(), pathSum.end(), greater<ll>());
        
        return pathSum[k-1];
    }
};