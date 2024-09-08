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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* ptr = head;
        int len = 0;
        while(ptr){
            len++;
            ptr = ptr->next;
        }
        
        int sz = len/k;
        int rem = len%k;

        vector<ListNode*> ans;
        ptr = head;
        int idx = 1;
        ListNode* ahead = NULL;
        ListNode* prev = head;
        int cnt = (rem>0? 1: 0);
        for(int i = 0; i<k; i++){
            if(rem<=0)cnt = 0;
            for(int j = 0; j<sz+cnt-1; j++){
                if(ptr)ptr = ptr->next;
            }
            rem--;
            ans.push_back(prev);
            if(ptr && ptr->next)ahead = ptr->next;
            else ahead = NULL;
            if(ptr)ptr->next = NULL;
            ptr = ahead;
            prev = ahead;
        }
        
        return ans;
    }
};