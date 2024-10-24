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
    void solve(TreeNode* root, vector<vector<int>> &v){
        if(!root){
            return;
        }
        solve(root->left, v);
        if(root->left)v[root->val][0] = root->left->val;
        if(root->right)v[root->val][1] = root->right->val;
        solve(root->right, v);
    }
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 || !root2 ){
            if(!root1 && !root2)return true;
            return false;
        }
        vector<vector<int>> v1(102, vector<int>(2,-1)), v2(102,vector<int>(2, -1));
        
        solve(root1, v1);
        solve(root2, v2);
        v1[0][0] = root1->val;
        v2[0][0] = root2->val;
        v1[0][1] = root1->val;
        v2[0][1] = root2->val;
        for(int i = 1; i<=100; i++){
            vector<int> t1 = v1[i];
            vector<int> t2 = v2[i];
            
            sort(t1.begin(), t1.end());
            sort(t2.begin(), t2.end());
            
            if(t1!=t2){
                return false;
            }
        }
        
        return true;
    }
};