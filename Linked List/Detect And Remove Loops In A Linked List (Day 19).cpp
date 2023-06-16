#include <bits/stdc++.h>
using namespace std;

// idea: 1) detecting the *head of the cycle in the linked list* using floyd's cycle detection algorithm (slow/fast)
// idea: 1) find point of intersection of slow and fast using floyd's cycle detection algorithm
// 2) now, revert slow back to head (slow = head), and increment both slow and fast only by one node with each iteration this time around, *until the two meet*
// 3) their new point of intersection is now the head of the cycle in the linked list

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

// why does it work: https://youtu.be/VxOFflTXlXo (see LoveBabbar's explanation)
Node *floydCycleDetection(Node *head)
{
    // edge case optimization: linked list is empty, no loops
    if (head == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        if (fast == slow)
        {
            return slow;
        }
    }
    return NULL;
}

// getStartingNode(Node* head): find starting node of the cycle in the linked list
// assumption: at this stage, we are sure that the linked list has a cycle
Node *getStartingNode(Node *head)
{
    // edge case optimization: if the linked list is empty
    if (head == NULL)
    {
        return NULL;
    }
    Node *intersection = floydCycleDetection(head);
    // adding null checks
    if (intersection == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    // starting point of cycle
    return intersection;
}

// task: remove the loop
// removeCycle(Node* head)
// idea: 1) remove the link between the node previous to the startingNode (prevNode), and the startingNode
// 2) instead, prevNode->next = NULL (successfully removed the cycle)
Node *removeCycle(Node *head)
{
    // edge case optimization: if the linked list is empty
    if (head == NULL)
    {
        return NULL;
    }
    Node *startOfLoop = getStartingNode(head);
    // adding null checks
    if (startOfLoop == NULL)
    {
        return head;
    }
    // instead of Node* prev = head, saves time complexity
    Node *prev = startOfLoop;
    while (prev->next != startOfLoop)
    {
        prev = prev->next;
    }
    prev->next = NULL;
    return head;
}