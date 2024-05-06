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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=head;
        while(curr){
            next=next->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            
        }
        
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode* temp=head;
        temp=reverseList(temp);
        int mx=temp->val;
        ListNode* temp2=temp->next;
        ListNode* prev= temp;
        while(temp2!=NULL){
            if(temp2->val<mx){
                if(temp2->next){
                 prev->next=temp2->next;
                    
               
                    
                }
                else prev->next=NULL;
                
                // cout<<temp2->val<<" ";
            }
            else{ mx=max(mx, temp2->val);
                 prev->next=temp2;
                 prev=prev->next;
                 
                }
            
            
             
            //cout<<prev->val<<" ";
           // prev=temp2;
            temp2=temp2->next;
             
        }
        
       // cout<<endl;
        
        return  reverseList(temp);
    }
};