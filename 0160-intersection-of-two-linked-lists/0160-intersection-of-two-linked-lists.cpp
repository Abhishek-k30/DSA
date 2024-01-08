/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, int> mpp;
        while(headA){
            mpp[headA]++;
            headA=headA->next;
        }
         while(headB){
            mpp[headB]++;
            headB=headB->next;
        }
        
        for(auto it: mpp){
            if(it.second==2){
                return it.first;
            }
        }
        
        return NULL;
    }
};