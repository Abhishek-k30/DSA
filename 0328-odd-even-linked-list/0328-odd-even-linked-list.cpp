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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)return head;
        
        ListNode* odd = head;
        ListNode* even = head->next;
        
        ListNode* oddptr = odd;
        ListNode* evenptr = even;
        
        while((oddptr && oddptr->next) || (evenptr && evenptr->next)){
            if(oddptr->next)oddptr->next = oddptr->next->next;
            if(evenptr->next)evenptr->next = evenptr->next->next;
            
            odd = oddptr;
            if(oddptr->next)oddptr = oddptr->next;
            if(evenptr->next)evenptr = evenptr->next;
            
        }
        
        oddptr->next = even;
        return head;
        
    }
};