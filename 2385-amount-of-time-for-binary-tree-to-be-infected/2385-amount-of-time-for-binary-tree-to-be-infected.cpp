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
    TreeNode* startNode(TreeNode* root, int start){
        if(!root || root->val == start){
            return root;
        }
        
        TreeNode* left = startNode(root->left, start);
        if(left)return left;
        return startNode(root->right, start);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        //Step 1 mark parents
        unordered_map<TreeNode* , TreeNode*> parent;
        queue<TreeNode*> qe;
        qe.push(root);
        while(!qe.empty()){
            TreeNode* cur = qe.front();
            qe.pop();
            if(cur->left){
                parent[cur->left] = cur;
                qe.push(cur->left);
            }
            
            if(cur->right){
                parent[cur->right] = cur;
                qe.push(cur->right);
            }
        }
        
        //step 2 Time calculation
        
        unordered_map<TreeNode* , bool> visited;
        queue<pair<TreeNode*, int>> q;
        TreeNode* node = startNode(root, start);
        q.push({node,0});
        visited[node] = true;
        int time = 0;
        
        while(!q.empty()){
            TreeNode* cur = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            time = max(time, steps);
            
            //left
            if(cur->left && !visited[cur->left]){
                q.push({cur->left, steps+1});
                visited[cur->left] = true;
            }
            
            //right
            if(cur->right && !visited[cur->right]){
                q.push({cur->right, steps+1});
                visited[cur->right] = true;
            }
            
            // up
            if(parent[cur] && !visited[parent[cur]]){
                q.push({parent[cur], steps+1});
                visited[parent[cur]] = true;
            }
        }
        
        
        return time;
    }
};