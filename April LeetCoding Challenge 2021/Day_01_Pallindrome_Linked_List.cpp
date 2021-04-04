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
    bool isPalindrome(ListNode* head) {
        
        ListNode *p = head,*q = head;
        
        //Finding middle point of the linked list
        while(q->next!=NULL && (q->next)->next!=NULL){
            p = p->next;
            q = (q->next)->next;
        }
        
        //Linked list diving into two parts. Second part head is p
        p = p->next;
        
        //Reversing second divided part of linked list
        ListNode *current = p, *next, *prev = NULL;
        while(current!=NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
       
        //new head of second part
        q = prev;
        //head of first part
        p = head;
            
        while(q!=NULL){
            if(p->val != q->val)
                return false;
            p = p->next;
            q = q->next;
        }
        return true;
    }
};
