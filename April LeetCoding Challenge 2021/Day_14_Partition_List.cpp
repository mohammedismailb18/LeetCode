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
        ListNode *first, *second, *temp = head, *tmp1, *tmp2;
        first = (ListNode*)malloc(sizeof(ListNode));
        second = (ListNode*)malloc(sizeof(ListNode));
        tmp1 = first;
        tmp2 = second;
        while(temp!=NULL){
            if(temp->val < x){
                tmp1->next = temp;
                tmp1 = tmp1->next;
            }
            else{
                tmp2->next = temp;
                tmp2 = tmp2->next;
            }
            temp = temp->next;
        }
        tmp2->next = NULL;
        tmp1->next = second->next;
        head = first->next;
        free(first);
        free(second);
        
        return head;
    }
};
