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
    vector<pair<ll, int>> solve(TreeNode* root){
         vector<pair<ll, int>> pathSum;
         
         queue<TreeNode*> q;
         q.push(root);
         
         int level = 1;
         
         while(!q.empty()){
             ll sum = 0;
             
             int sz = q.size();
             
             while(sz--){
                 TreeNode* curNode = q.front();
                 q.pop();
                 
                 
                 sum+= curNode->val;
                 
                 if(curNode->left!=NULL){
                    q.push(curNode->left);
                 }
                 
                 if(curNode->right!=NULL){
                    q.push(curNode->right);
                 }
             }
             
             pathSum.push_back({sum, level++});
         }
         
         return pathSum;
    }
public:
    int maxLevelSum(TreeNode* root) {
        
        vector<pair<ll, int>> pathSum = solve(root);
        
        sort(pathSum.begin(), pathSum.end(), [&](pair<ll, int>&a, pair<ll,int>&b){
            if(a.first == b.first){
                return a.second>b.second;
            }
            return a.first < b.first;
        });
        
        return pathSum.back().second;
    }
};