/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool solve(ListNode* head ,ListNode* cur, TreeNode* root){
        if(!cur)return true;
        if(!root  )return false;
        
        if(root->val == cur->val){
            cur = cur->next;
        }
        else if(root->val == head->val){
            head = head->next;
        }
        else cur = head;
        return solve(head, cur,root->left) || solve(head,cur, root->right);
         
        
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return solve(head,head, root);
    }
};