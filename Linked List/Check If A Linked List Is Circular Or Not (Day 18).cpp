#include <bits/stdc++.h>
using namespace std;

// idea: isCircular(head) -> checks whether it loops around back to head or it reaches NULL after iterative linked list traversal (temp = temp->next)
bool isCircular(Node *head)
{
    // edge case optimization: one node (where head->next != head)
    if (head == NULL)
    {
        return (false);
    }
    // for (length >= 1)
    Node *temp = head->next;
    while (temp != head && temp != NULL)
    {
        temp = temp->next;
    }
    return (temp == head);
}

// time complexity: O(n)
// space complexity: O(1)