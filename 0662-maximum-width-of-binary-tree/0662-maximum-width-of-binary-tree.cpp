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
    int widthOfBinaryTree(TreeNode* root) {
        long long maxWidht = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            int size = q.size();
            long long last = q.front().second;
            long long firstIdx, lastIdx;
            for(int i = 0; i<size; i++){
                long long cur_id = q.front().second-last;
                TreeNode* cur = q.front().first;
                q.pop();
                
                if(i == 0)firstIdx = cur_id;
                if(i == size-1)lastIdx = cur_id;
                
                if(cur->left)q.push({cur->left, 2*cur_id+1});
                if(cur->right)q.push({cur->right, 2*cur_id+2});
            }
            
            maxWidht = max(maxWidht, lastIdx-firstIdx+1);
        }
        
        return maxWidht;
    }
};