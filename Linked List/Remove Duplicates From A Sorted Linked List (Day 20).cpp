#include <bits/stdc++.h>
// type 1: from a sorted linked list
// class Node:
// 1) create a class to encapsulate the attributes of a node in the linked list
// 2) create a constructor to initialize the start node / head node
class Node
{
public:
    int data;
    Node *link;
    Node(int value)
    {
        this->data = value;
        this->link = NULL;
    }
};

// idea: 1) if (curr->data == curr->next->data) -> delete node
// 2) intuitively, (curr->next = curr->next->next) and free (curr->next)
// 3) if (curr->data != curr->next->data), only then curr = curr->next
Node *uniqueSortedList(Node *head)
{
    // edge case optimization: empty linked list
    if (head == NULL)
    {
        return head;
    }
    // non-empty linked list
    Node *curr = head;
    while (curr != NULL)
    {
        // short circuit evaluation: check if curr->next != NULL before trying to access curr->next->data, to avoid SIGSEGV
        if (curr->next != NULL && curr->data == curr->next->data)
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else
        {
            if (curr != NULL)
            {
                curr = curr->next;
            }
        }
    }
    return head;
}
