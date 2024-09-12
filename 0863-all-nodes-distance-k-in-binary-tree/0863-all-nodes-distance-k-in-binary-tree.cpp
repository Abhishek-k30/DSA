/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        //Step-1 mark parent
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            
            if(cur->left){
                parent[cur->left] = cur;
                q.push(cur->left);
            }
            if(cur->right){
                parent[cur->right] = cur;
                q.push(cur->right);
            }
        }
        
        //Step-2 
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*>qe;
        int level = 0;
        qe.push(target);
        visited[target] = true;
        
        while(!qe.empty()){
            if(level++ == k)break;
            int size = qe.size();
            for(int i = 0; i<size; i++){
            TreeNode* cur = qe.front();
            qe.pop();
            
            //left
            if(cur->left && !visited[cur->left]){
                qe.push(cur->left);
                visited[cur->left] = true;
            }
                
            // right
            if(cur->right && !visited[cur->right]){
                qe.push(cur->right);
                visited[cur->right] = true;
            }
                
            // top
            if(parent[cur] && !visited[parent[cur]]){
                qe.push(parent[cur]);
                visited[parent[cur]] = true;
            }
        }
      }
        
      vector<int> nodes;
      while(!qe.empty()){
          nodes.push_back(qe.front()->val);
          qe.pop();
      }
        
      return nodes;
    }
};