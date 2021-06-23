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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = head, *prev = NULL;
        int count = 1;
        while(temp && count != left)
            prev = temp, temp = temp->next, count++;
        ListNode* next, *previous = NULL, *start = temp;
        while(temp && count <= right){
            next = temp->next;
            temp->next = previous;
            previous = temp;
            temp = next;
            count++;
        }
        if(!prev)
            head = previous;
        else
            prev->next = previous;
        start->next = temp;
        return head;
    }
};
