#include <bits/stdc++.h>
using namespace std;

// task: detect a cycle in a linked list and return the head of the cycle (the element that is visited twice during linked list traversal)

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

// naive approach: visited map
// idea: map<Node*, bool> visitedMap;
// if the node is visited again, return true, else continue exploring until temp == NULL
bool detectCycle(Node *head)
{
    // edge case optimization
    if (head == NULL)
    {
        return false;
    }
    map<Node *, bool> visited;
    Node *temp = head;
    while (temp != NULL)
    {
        // cycle is present
        // without this condition, for a loop it would be stuck in an infinite loop
        if (visited[temp])
        {
            cout << "Cycle head is: " << temp->data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

// optimized approach: floyd's cycle detection for linked lists
// return true or false
// same (slow/fast) oriented approach

// idea: 1) slow/fast approach
// 2) but in case of a loop, slow would meet fast *eventually*, at some point of time
// 3) in case of no loops, slow would never meet fast, most importantly, fast would *reach NULL* before they could have the chance to meet
// one issue: does not always return the head of the cycle, but may return a node that is a part of the cycle in the linked list

// why does it work: https://youtu.be/VxOFflTXlXo (see LoveBabbar's explanation)
Node *floydCycleDetection(Node *head)
{
    // edge case optimization: linked list is empty, no loops
    if (head == NULL)
    {
        return false;
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
            cout << "The node that definitely lies on the cycle is: " << fast->data; // or slow->data
            return slow;
        }
    }
    return NULL;
}

// time complexity: O(n)
// space complexity: O(1)