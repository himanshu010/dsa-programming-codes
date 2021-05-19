/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* head1 = headA;
        ListNode* head2 = headB;
        unordered_map<ListNode*, bool>mp;
        while (head1 != NULL) {
            mp[head1] = 1;
            head1 = head1->next;
        }
        while (head2 != NULL) {
            if (mp.count(head2) != 0) {
                return head2;
            }
            head2 = head2->next;
        }

        return NULL;
    }
};