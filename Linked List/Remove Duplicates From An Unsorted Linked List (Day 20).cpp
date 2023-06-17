#include <bits/stdc++.h>
using namespace std;
// type 2: from an unsorted linked list
// https://www.codingninjas.com/codestudio/problems/remove-duplicates-from-unsorted-linked-list_1069331
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

// approach 1: using loops (gives TLE)
// time complexity: O(n^2)
// space complexity: O(1)
// idea: 1) for each node, check the entire linked list after it for the same data, and delete the node if (temp->data == curr->data)
Node *removeDuplicates(Node *head)
{
    // edge case optimization: empty linked list and a linked list with a single node
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *curr = head;
    while (curr != NULL)
    {
        Node *prev = curr;
        Node *temp = curr->next;
        while (temp != NULL)
        {
            if (curr->data == temp->data)
            {
                Node *delnode = temp;
                prev->next = temp->next;
                delete delnode;
            }
            else
            {
                prev = temp;
            }
            temp = temp->next;
        }
        curr = curr->next;
    }
    return head;
}

// approach 2: use std::unordered_map<int, bool> (no TLE)
// idea: 1) if the node has been visited before, prev->next = curr->next && delete prev->next
// 2) the loop continues until (temp != NULL)
// time complexity: O(n)
// space complexity: O(n) (because of the map => worst case scenario, when all are unique)
Node *removeDuplicates(Node *head)
{
    // edge case optimization: empty linked list and a linked list with a single node
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *temp = head;
    Node *prev = NULL;
    unordered_map<int, bool> visited;
    while (temp)
    {
        if (visited[temp->data] == true)
        {
            prev->next = temp->next;
            temp = temp->next;
        }
        else
        {
            visited[temp->data] = true;
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}