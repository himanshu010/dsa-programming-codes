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
class Solution
{
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = head;
        ListNode *root = head;
        while (n--)
        {
            if (temp->next == NULL)
            {
                return head->next;
            }
            temp = temp->next;
        }
        while (temp->next != NULL)
        {
            temp = temp->next;
            root = root->next;
        }

        root->next = root->next->next;
        return head;
    }
};