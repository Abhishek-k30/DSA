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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* ptr1=l1;
        ListNode* ptr2=l2;
        ListNode* prev;
        ListNode* head;
        bool flag=true;
        
        while(ptr1 || ptr2){
            int a=0;
            int b=0;
            
            if(ptr1)a=ptr1->val;
            if(ptr2)b=ptr2->val;
            
            int sum=a+b;
            
            sum+=carry;
            if(sum>9){
                carry=1;
                sum=sum%10;
            }
            else carry=0;
            
            ListNode* curr= new ListNode();
            curr->val=sum;
            if(flag){
                head=curr;
                flag=false;
                
            }
            else{
                prev->next=curr;
            }
            
            prev=curr;
            
            if(ptr1)ptr1=ptr1->next;
            if(ptr2)ptr2=ptr2->next;
            
            
            
        }
        ListNode* end= new ListNode();
        if(carry==1){
            
            end->val=carry;
            end->next=NULL;
             
        
        
        prev->next=end;
        }
        
        return head;
    }
};