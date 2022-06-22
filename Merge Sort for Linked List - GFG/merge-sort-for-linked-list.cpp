// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
  
    Node* findmid(Node* head){
        Node* fast = head->next;
        Node* slow = head;
        
        while(fast!= NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    Node* merge(Node* right, Node* left){
        if(left == NULL){
            return right;
        }
        
        if(right == NULL){
            return left;
        }
        
        Node *ans = new Node(-1);
        Node *temp = ans;
        
        while(left!=NULL && right!=NULL){
            if(left->data<right->data){
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else{
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }
        
        while(left!=NULL){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        
        while(right!=NULL){
            temp->next = right;
            temp = right;
            right = right->next;
        }
        
        ans = ans->next;
        return ans;
    }
    
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        Node* mid = findmid(head);
        
        Node* right = mid->next;
        Node* left = head;
        mid->next = NULL;
        
        left = mergeSort(left);
        right = mergeSort(right);
        
        Node* result = merge(left, right);
        return result;
    }
};
// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends