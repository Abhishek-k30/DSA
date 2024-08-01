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
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* prev = NULL;
        ListNode* head = NULL;
        bool isItFirstNode = true;
        
        int  carry = 0;
        while(ptr1 || ptr2){
            int  a = 0, b = 0;
            if(ptr1)a= ptr1->val;
            if(ptr2)b= ptr2->val;
            
           int sum = a + b + carry;
            
            if(sum> 9){
                carry = 1;
                sum%=10;
            }
            else carry = 0;
            
            ListNode* cur = new ListNode();
            cur ->val = sum;
            
            if(isItFirstNode){
                head = cur;
                isItFirstNode = false;
            }
            else {
                prev->next = cur;
            }
            
            prev = cur;
            
            if(ptr1)ptr1 = ptr1->next;
            if(ptr2)ptr2 = ptr2->next;
        }
        
        if(carry == 1){
            ListNode* endNode = new ListNode(carry);
            endNode ->next = NULL;
            prev->next = endNode;
        }
        
        return head;
    }
};