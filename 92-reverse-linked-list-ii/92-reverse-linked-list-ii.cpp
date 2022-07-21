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
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        
        int i=1;
        ListNode* curr = head, *prev = NULL;
        
        while(i<l){
            prev = curr;
            curr = curr->next;
            i++;
        }
        
        ListNode* rtail = curr;
        ListNode* rhead = NULL;
        
        while(i<=r){
            ListNode* temp = curr->next;
            curr->next = rhead;
            rhead = curr;
            curr = temp;
            i++;
        }
        
        if(prev != NULL){
            prev->next = rhead;
        }
        else{
            head = rhead;
        }
        
        rtail->next = curr;
        
        return head;
        
    }
};