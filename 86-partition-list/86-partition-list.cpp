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
    ListNode* partition(ListNode* head, int x) {
        
        if(head == NULL){
            return head;
        }
        
        ListNode* mark = head, *prevMark = NULL;
        while(mark!=NULL && mark->val < x){
            prevMark = mark;
            mark = mark->next;
        }
        
        ListNode *curr = mark, *currPrev = NULL;
        while(curr!=NULL && curr->next!=NULL){
            currPrev = curr;
            curr = curr->next;
            
            if(curr->val < x){
                currPrev->next = curr->next;
                if(!(prevMark == NULL)){
                    prevMark->next = curr;   
                }
                else{
                    head = curr;
                }
                prevMark = curr;
                prevMark->next = mark;
                curr = currPrev;
            }
        }
        
        return head;
    }
};