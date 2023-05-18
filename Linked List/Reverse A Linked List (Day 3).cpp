#include <bits/stdc++.h>
using namespace std;
// idea: move head until nextptr != NULL, but at the same time change ptr->next if not NULL to the previous node in the linked list
class Solution
{
public:
    struct Node *reverseList(struct Node *head)
    {
        struct Node *ptr = head;
        struct Node *nextptr = head->next;
        ptr->next = NULL;
        while (nextptr != NULL)
        {
            // save the pointer since we know we're going to lose connection to that node if we don't save its reference
            struct Node *temp = nextptr->next;
            nextptr->next = ptr;
            ptr = nextptr;
            nextptr = temp;
        }
        head = ptr;
        return (head);
    }
};