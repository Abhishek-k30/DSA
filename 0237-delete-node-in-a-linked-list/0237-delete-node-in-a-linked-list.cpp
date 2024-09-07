/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // swap the value of ahead node and delete the ahead node
        node->val = node->next->val;
        node->next = node->next->next;
        
    }
};
//TC=O(1), SC=O(1)