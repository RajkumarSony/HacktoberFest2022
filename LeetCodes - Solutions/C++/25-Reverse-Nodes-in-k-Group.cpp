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
    int length(ListNode *node)
    {
        int count = 0;
        while (node)
        {
            count++;
            node = node->next;
        }
        return count;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (length(head) < k)
            return head;
        if (head == NULL)
            return NULL;

        ListNode *n = NULL;
        ListNode *c = head;
        ListNode *p = NULL;
        int cnt = 0;
        while (c != NULL && cnt < k)
        {
            n = c->next;
            c->next = p;
            p = c;
            c = n;
            cnt++;
        }
        if (n != NULL)
        {
            head->next = reverseKGroup(n, k);
        }
        return p;
    }
};