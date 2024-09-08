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
    ListNode* findMiddle(ListNode* head){
        if(!head || !head->next )return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* sortedLL(ListNode* list1, ListNode* list2){
        ListNode* dummyNode = new ListNode(-1e6);
        ListNode* temp = dummyNode;
        
        while(list1 && list2){
            if(list1->val<=list2->val){
                temp->next = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;
            }
            
            temp = temp->next;
        }
        
        if(list1){
            temp->next = list1;
        }
        else if(list2){
            temp->next = list2;
        }
        
        return dummyNode->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        
        ListNode* middle = findMiddle(head);
        ListNode* right = middle->next;
        middle->next = NULL;
        ListNode* left = head;
        
        left = sortList(left);
        right = sortList(right);
        
        return sortedLL(left, right);
    }
};