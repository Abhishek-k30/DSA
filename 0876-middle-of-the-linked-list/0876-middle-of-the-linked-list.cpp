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
    ListNode* middleNode(ListNode* head) {
        int size=0;
        ListNode* temp= head;
        while(temp){
            size++;
            temp=temp->next;
        }
        size= ceil(size/2);
        ListNode* ans=head;
        for(int i=0; i<size; i++){
            ans=ans->next;
        }
        
        return ans;
    }
};

//TC=O(n), SC=O(1)