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
        ListNode* ptr = head;
        int len = 0;
        while(ptr){
            ptr = ptr->next;
            len++;
        }
        ListNode* mid = head;
        for(int i = 0; i<len/2; i++)mid = mid->next;
        if(len%2)mid = mid->next;
        ListNode* reverseMid = reverse(mid);
        ListNode* front = head;
        
        while(reverseMid){
            if(front->val != reverseMid->val)
                return false;
            front = front->next;
            reverseMid = reverseMid->next;
        }
        
        return true;
    }
};