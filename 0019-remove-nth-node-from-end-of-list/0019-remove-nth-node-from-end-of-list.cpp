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
        int size=0;
        ListNode* temp= head;
        while(temp){
            size++;
            temp=temp->next;
        }
        
        ListNode* ptr= head;
        if(n==size){
             return head->next;
        }
        else
        {
               
        for(int i=1; i< size-n; i++){
            ptr=ptr->next;
        }
        
        ListNode* nxt= ptr->next;
        ptr->next=nxt->next;
        
        }
        return head;
    }
};