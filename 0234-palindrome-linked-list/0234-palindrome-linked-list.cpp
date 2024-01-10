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
   ListNode* reverse(ListNode* head){
        ListNode* temp=head;
        ListNode* prev=NULL;
        
        while(temp!=NULL){
            ListNode* front= temp->next;
            temp->next = prev;
            prev = temp;
            temp= front;
        }
        
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        int sz=0;
        ListNode* ptr= head;
        while(ptr){
            sz++;
            ptr=ptr->next;
        }
        
        ListNode* mid=head;
        for(int i=0; i<sz/2; i++){
            mid=mid->next;
        }
        if(sz%2!=0)
            mid=mid->next;
        
        ListNode* ptr1= reverse(mid);
        
        while(ptr1){
            if(ptr1->val!=head->val)
                return false;
            
            ptr1=ptr1->next;
            head=head->next;
        }
        
         
        
        
        return true;
    }
};