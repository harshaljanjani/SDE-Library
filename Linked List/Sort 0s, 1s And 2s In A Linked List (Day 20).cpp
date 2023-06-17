#include <bits/stdc++.h>
using namespace std;
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

// approach 1 (naive)
// idea: 1) traverse the entire linked list
// 2) count the number of 0s, 1s and 2s
// 3) insert the 0s first, 1s second and 2s third according to their number of occurences
Node *sortList(Node *head)
{
    int zeroCount = 0, oneCount = 0, twoCount = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zeroCount++;
        }
        else if (temp->data == 1)
        {
            oneCount++;
        }
        else if (temp->data == 2)
        {
            twoCount++;
        }
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (zeroCount)
        {
            temp->data = 0;
            zeroCount--;
        }
        else if (oneCount)
        {

            temp->data = 1;
            oneCount--;
        }
        else if (twoCount)
        {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }
    return head;
}
// time complexity: O(n)
// space complexity: O(1)

// approach 2 -> data replacement is not allowed
// idea: change links between nodes
// 1) make three shorter linked lists (one for 0s, one for 1s, one for 2s), and merge the three linked lists in order, one after the other
// catch: dummy node in each of the smaller linked lists must be excluded when merging

// function to set zeroTail->link = newNode(value)
void insertAtTail(Node *&tail, Node *curr)
{
    tail->next = curr;
    tail = curr;
}
Node *sortList(Node *head)
{
    // initialize head and tail of each of the smaller linked lists (dummy node)
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;
    // now perform insertionAtTail(Node *tail, Node* curr)
    // mistake: insertionAtTail(Node* tail, int value){ Node* temp = new Node(value); }
    Node *curr = head;
    while (curr != NULL)
    {
        int value = curr->data;
        if (value == 0)
        {
            insertAtTail(zeroTail, curr);
        }
        else if (value == 1)
        {
            insertAtTail(oneTail, curr);
        }
        else if (value == 2)
        {
            insertAtTail(twoTail, curr);
        }
        curr = curr->next;
    }
    // merge three linked lists
    // zeroTail->next = oneHead->next (node just after the dummy node)
    // oneTail->next = twoHead->next (node just after the dummy node)
    // twoTail->next = NULL;

    // edge case optimization: peform null checks
    // if(oneHead->next != NULL) ? zeroTail->next = oneHead->next : zeroTail->next = twoHead->next

    // revolves around the condition whether the ones linked list is empty or not
    if (oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next;
    }
    else
    {
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;
    head = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return head; // head = zeroHead->next (node after dummy node)
}
// time complexity: O(n)
// space complexity: O(1)