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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(),nums.end());
        ListNode* prev = new ListNode(-1);
        prev->next = head;
        ListNode* ptr = prev;
        ListNode* cur = head;
        while(cur){
            int val = cur->val;
            if(st.find(val)!=st.end()){
                if(cur->next==NULL){
                    prev->next = NULL;
                    break;
                }
                else{
                    cur = cur->next;
                    prev->next = cur;
                }
            }
            else{
                prev = prev->next;
                cur = cur->next;
            }
        }
        
        ptr=ptr->next;
        return ptr;
    }
};