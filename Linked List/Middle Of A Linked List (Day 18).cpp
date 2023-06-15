#include <bits/stdc++.h>
using namespace std;

// approach 1
// time complexity: O(n) solution
// idea: 1) getlength(Node* head) => get the length of the entire linked list
// 2) findMiddle(Node* head) => ans = (len/2) + 1, temp = temp->next for "ans - 1" number of times

// encapsulating properties of a Node
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

// getLength(Node* head)
int getlength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

// findMiddle(Node* head)
Node *findMiddle(Node *head)
{
    // zero or one element(s)
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    // two elements
    if (head->next->next == NULL)
    {
        return head->next;
    }

    // time complexity: O(n)
    int len = getlength(head);
    Node *temp = head;
    // actual position of node is (len/2)+1
    // so for ans--, keeping in mind that we would perform temp = temp->next one more than we actually need, we set ans = (len/2) and not (len/2)+1
    int ans = (len / 2);
    while (ans--)
    {
        temp = temp->next;
    }
    return temp;
}

// optimized approach 2: slowPlayer/fastPlayer approach
// time complexity: O(n) solution
// space complexity: O(1) solution

// idea: 1) one fastPlayer and another slowPlayer (fastPlayer runs twice as fast as the slowPlayer)
// 2) by the end of race-time, fastPlayer would have covered not only the entire length of the track, but most importantly *twice the distance covered by the slowPlayer*
// 3) so, by the end of the race, fastPlayer would be at the finish line, and *the slowPlayer would be at the middle of the track length*

Node *findMiddle(Node *head)
{
    // zero or one element(s)
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    // two elements
    if (head->next->next == NULL)
    {
        return head->next;
    }
    // n elements
    Node *fast = head;
    Node *slow = head;
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        else
        {
            return slow;
        }
    }
    return slow; // slowPlayer is at the middle of the linked list by the end, whereas the fastPlayer is at the end of the linked list (finished the race)
}