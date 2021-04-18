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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ptr1 = head, *ptr2 = head, *prev = head;
        while(n--)
            ptr2 = ptr2->next;
        while(ptr2!=NULL){
            prev = ptr1;
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
        }
        if(ptr1 == head)
            return ptr1->next;
        prev->next = ptr1->next;
        return head;
    }
};
