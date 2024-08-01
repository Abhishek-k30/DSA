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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * temp = head;
        int len = 0;
        while(temp){
            temp = temp->next;
            len++;
        }
        
        int nodeNum = len- n;
        if(nodeNum == 0){
            return head->next;
        }
        else{
        ListNode* cur = head;
        for(int i = 0; i<nodeNum-1; i++){
            cur = cur->next;
        }
         
        cur->next = cur->next->next;
         
        return head;
        }
        
    }
};