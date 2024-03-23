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
    void reorderList(ListNode* head) {
        vector<int> v;
        ListNode* ptr=head;
        while(ptr){
            int value= ptr->val;
            v.push_back(value);
            ptr=ptr->next;
        }
        
        ListNode* ptr2=head;
        int j=0;
        int n= v.size();
        if(n%2==0){
             while( ptr2 ){
            ptr2->val=v[j];
            ptr2=ptr2->next;
            ptr2->val=v[n-j-1];
            j++;
            ptr2=ptr2->next;
        }
        }
        else{
            
        
        while( ptr2->next!=NULL && ptr2->next->next!=NULL ){
            ptr2->val=v[j];
            ptr2=ptr2->next;
            ptr2->val=v[n-j-1];
            j++;
            ptr2=ptr2->next;
        }
          ptr2->val=v[n-j-1];  
        }
         
    }
};