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
    void inorderTraversal(TreeNode* root, vector<int>&val){
        if(!root)return;
        inorderTraversal(root->left, val);
        val.push_back(root->val);
        inorderTraversal(root->right, val);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> elem1;
        vector<int> elem2;
        
        inorderTraversal(root1, elem1);
        inorderTraversal(root2, elem2);
        
        vector<int> ans;
        int i = 0, j = 0;
        while(i<elem1.size() && j<elem2.size()){
            if(elem1[i]<=elem2[j]){
                ans.push_back(elem1[i]);
                i++;
            }
            else{
                ans.push_back(elem2[j]);
                j++;
            }
        }
        
        while(i<elem1.size()){
            ans.push_back(elem1[i++]);
        }
        
        while(j<elem2.size()){
            ans.push_back(elem2[j++]);
        }
        
        return ans;
    }
};
// TC = O(3*N) , SC = O(3N)