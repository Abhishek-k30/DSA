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
    vector<long long> solve(TreeNode* root){
        vector<long long> sum;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            long long curSum = 0;
            
            int sz = q.size();
            
            while(sz--){
                
                TreeNode* curNode = q.front();
                q.pop();
                
                curSum+= curNode->val;
                
                if(curNode->left!=NULL){
                    q.push(curNode->left);
                }
                
                if(curNode->right!=NULL){
                    q.push(curNode->right);
                }
            }
            
            sum.push_back(curSum);
        }
        
        return sum;
    }
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<long long> levelSum = solve(root);
        int maxSize = levelSum.size();
        
        queue<TreeNode*> q;
        q.push(root);
        
        int idx = 1;
        while(!q.empty() && idx<maxSize){
            long long curLevelSum = levelSum[idx++];
            
            int sz = q.size();
            
            while(sz--){
                
                TreeNode* curNode = q.front();
                q.pop();
                
                long long siblingSum = (curNode->left!=NULL ? curNode->left->val : 0)
                    + (curNode->right!=NULL ? curNode->right->val : 0);
                
                long long reqSum = curLevelSum - siblingSum;
                
                if(curNode->left){
                    curNode->left->val = (int)reqSum;
                    q.push(curNode->left);
                }
                
                if(curNode->right){
                    curNode->right->val = (int)reqSum;
                    q.push(curNode->right);
                }
            }
            
        }
        
        root->val = 0;
        
        return root;
        
    }
};