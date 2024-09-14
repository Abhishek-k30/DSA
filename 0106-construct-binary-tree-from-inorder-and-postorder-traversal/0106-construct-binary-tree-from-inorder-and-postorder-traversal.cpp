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
    TreeNode* build(vector<int>&inorder, int is, int ie, vector<int>&postorder, 
                   int ps, int pe, map<int, int>&iMap){
        if(is>ie || ps>pe)return NULL;
        
        TreeNode* root = new TreeNode(postorder[pe]);
        
        int inRoot = iMap[postorder[pe]];
        int numsLeft = inRoot-is;
        
        root->left = build(inorder, is, inRoot-1, 
                          postorder, ps, ps+numsLeft-1, iMap);
        root->right = build(inorder, inRoot+1, ie,
                            postorder,ps+numsLeft,pe-1,iMap);
        
        return root;
        
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> iMap;
        for(int i = 0; i<inorder.size(); i++){
            iMap[inorder[i]] = i;
        }
        
        return build(inorder,0,inorder.size()-1,postorder, 0, postorder.size()-1,
                     iMap);
    }
};