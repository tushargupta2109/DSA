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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* first = head;
        ListNode* second = head->next;
        
        while(second != NULL){
            while(second->val != 0){

                first->val += second->val;
                second = second ->next;
            }

            if(second->next == NULL){
                first->next = NULL;
                break;
            }
            first->next = second;
            first = second;
            second = second->next;
        }
        
        return head;
    }
};