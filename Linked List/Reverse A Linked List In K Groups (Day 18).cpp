// important question
#include <bits/stdc++.h>
using namespace std;
// idea: recursion
// 1) "ek case solve kardo (just reverse one group of k), baaki recursion dekh lega (the rest of the k groups would be automatically handled by recursion)"
// 2) head->next = (output of recursion)
// 3) return (prev) (three pointers -> curr, prev, forward/next)

class Node
{
    int data;
    Node *next;
    Node(int value)
    {
        this->data = value;
        this->next = NULL;
    }
};

// getLength(head) -> returns the length of the linked list
int getLength(Node *head)
{
    int length = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        length++;
    }
    return length;
}

// kReverse(head, k) -> reverse the linked list in groups of k using the recursion paradigm
Node *kReverse(Node *head, int k)
{
    // edge case optimization -> what if in any recursive call, k < length(linked list)
    int count = getLength(head);
    if (count < k)
    {
        return head;
    }
    // base case
    if (head == NULL)
    {
        return NULL;
    }
    // step 1: reverse first k nodes
    Node *next = NULL;
    Node *curr = head;
    Node *prev = NULL;
    int cnt = 0;
    while (curr != NULL && cnt < k)
    {
        //          [curr]-->[next]
        next = curr->next;
        // [prev]<--[curr]
        curr->next = prev;
        // [....]<--[prev]-->[next]
        prev = curr;
        // [....]<--[prev]-->[curr]
        curr = next;
        cnt++;
    }
    // step 2: recursion sambhal lega
    if (next != NULL)
    {
        head->next = kReverse(next, k);
    }
    // step 3: return the head of reversed list
    return (prev);
}