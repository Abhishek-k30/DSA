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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head->next)return head;
        ListNode* elem1 = head;
        ListNode* elem2 = head->next;
        
        while(elem2){
            int val1 = elem1->val;
            int val2 = elem2->val;
            
            int gcd = __gcd(val1, val2);
            ListNode* cur = new ListNode(gcd);
            elem1->next = cur;
            cur->next = elem2;
            elem1 = elem2;
            elem2 = elem2->next;
        }
        
        return head;
    }
};