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
private:
    ListNode* middleNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* next = head;
        
        while(cur){
            next = next->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* middle = middleNode(head);
        middle = reverse(middle->next);
        
        ListNode* ptr = head;
        while(middle){
            if(middle->val!=ptr->val){
                return false;
            }
            
            middle = middle->next;
            ptr = ptr->next;
        }
        
        return true;
    }
};