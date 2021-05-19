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


    void  makeList(ListNode* l1, ListNode* l2, ListNode* cur, int c) {

        if (l1 == NULL and l2 == NULL and c == 0) {
            return;
        }

        int sum = c;
        if (l1 != NULL) {
            sum += l1->val;
        }
        if (l2 != NULL) {
            sum += l2->val;
        }
        c = 0;
        string t;
        while (sum > 0) {
            t += (char)((sum % 10) + '0');
            sum /= 10;
        }
        sum = t[0] - '0';
        reverse(t.begin(), t.end());
        if (t.size() == 1) {
            c = 0;
        }
        else if (t.size() == 0) {
            c = 0;
            sum = 0;
        }
        else {

            c = stoll(t.substr(0, t.size() - 1), nullptr, 10);
        }
        ListNode* nex = new ListNode(sum);
        cur->next = nex;
        cur = cur->next;
        if (l1 != NULL) {
            l1 = l1->next;
        }
        if (l2 != NULL) {
            l2 = l2->next;
        }

        makeList(l1, l2, cur, c);


    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* ans = new ListNode(-1);
        makeList(l1, l2, ans, 0);
        return ans->next;
    }
};