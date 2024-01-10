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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return NULL;
        int sz=0;
        ListNode* ptr=head;
        while(ptr){
            sz++;
            ptr=ptr->next;
        }
        ListNode* ptr2=head;
        while(ptr2->next){
            ptr2=ptr2->next;
        }
        
        int diff= k%sz;
        int pos=sz-diff;
        
        ListNode* temp=head;
        ListNode* temp2;
        
        for(int i=0; i<pos-1; i++){
            temp=temp->next;
        }
        
        if(k==0 || k==sz || pos==0 || pos==sz){
           return head; 
        }
         
        else{
            temp2=temp->next;
            temp->next=NULL;
        }
        
        ptr2->next=head; 
        return temp2;
            
        
    }
};