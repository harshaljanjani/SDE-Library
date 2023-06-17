#include <bits/stdc++.h>
using namespace std;
// class Node:
// 1) create a class to encapsulate the attributes of a node in the linked list
// 2) create a constructor to initialize the start node / head node
template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node(T data)
    {
        next = NULL;
        this->data = data;
    }
    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

// optimized approach
// idea: try to find a 'b' from linked list 2, that can be inserted between curr(which is 'a') and curr->next(which is 'c'), otherwise move to the next node (curr = curr->next)
//     b
// a       c
// edge case optimization
// 1) (if head1 == NULL) => return head2
// 2) (if head2 == NULL) => return head1
Node<int> *solve(Node<int> *first, Node<int> *second)
{
    // edge case optimization: if only one element is present in the first list
    if (first->next == NULL)
    {
        // attach the second list to the first (we know that first->data <= second->data)
        first->next = second;
        return first;
    }
    // we need three nodes to execute this function
    //          b (curr2)
    // a (curr1)      c (next1)
    Node<int> *curr1 = first;
    Node<int> *next1 = first->next;
    Node<int> *curr2 = second;
    Node<int> *next2 = curr2->next;
    // loop condition: next1->data should not be checked if next1 == NULL
    while (next1 != NULL && curr2 != NULL)
    {
        if (curr2->data >= curr1->data && curr2->data <= next1->data)
        {
            next2 = curr2->next;
            curr1->next = curr2;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1->next;
            // null checks
            if (next1 == NULL)
            {
                // append the rest of the linked list to curr1 as it is
                curr1->next = curr2;
            }
        }
    }
    return first;
}

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    // edge case optimization
    if (first == NULL)
    {
        return second;
    }
    if (second == NULL)
    {
        return first;
    }
    // imp: if the value of second->data < first->data, we have to swap first and second lists (for insertion between the nodes in the future)
    // so we create a function to swap heads if necessary
    if (first->data <= second->data)
    {
        return solve(first, second);
    }
    else
    {
        return solve(second, first);
    }
}
// time complexity: O(n)
// space complexity: O(1)