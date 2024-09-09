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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> nodes;
        if(!root)return nodes;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while(!q.empty()){
            int size = q.size();
            
            int idx = 0;
            vector<int> temp(size);
             for(int i = 0; i<size; i++){
                TreeNode* cur = q.front();
                q.pop();
                int idx = (flag)?(size-i-1) : i;
                temp[idx] = cur->val;
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            
            nodes.push_back(temp);
            flag = !flag;
        }
        
        return nodes;
    }
};