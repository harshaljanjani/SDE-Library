#include <bits/stdc++.h>
using namespace std;
// implementation of a singly linked list in C++ (insertion)
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

// utility function: print(head)
void print(Node *&head)
{
    // edge case optimization
    if (head == NULL)
    {
        cout << "Linked List Is Empty" << endl;
        return;
    }
    Node *iterNode = head;
    while (iterNode != NULL)
    {
        cout << iterNode->data << " ";
        iterNode = iterNode->link;
    }
    cout << endl;
}

// note: for all the below functions, Node* &head has been taken, since if we just take in Node* head, a copy would be created
// instead, we want to reference the original linked list head

// ALL INSERTIONS:
// insertion at the head of a singly linked list:
void insert_at_head(Node *&head, int value)
{
    // syntax: Node* newNode = new Node(value);
    // idea: wrap the data/value in a node
    Node *newNode = new Node(value);
    // edge case condition: when the head is NULL, or there is no node yet in the linked list
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->link = head;
        head = newNode;
    }
}

// insertion at tail of a singly linked list
void insert_at_tail(Node *&head, int value)
{
    // syntax: Node* newNode = new Node(value);
    // idea: wrap the data/value in a node
    Node *newNode = new Node(value);
    // edge case condition: when the head is NULL, or there is no node yet in the linked list
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    // it is an object of the Node class, that would iterate through the linked list until it reaches the very end
    Node *tail = head;
    while (tail->link != NULL)
    {
        tail = tail->link;
    }
    // we have reached the last node / tail of the linked list
    tail->link = newNode;
    newNode->link = NULL;
}

// insertion in the middle (at a given position)
void insert_at_position(Node *&head, int position, int value)
{
    // smart work
    if (position == 0)
    {
        insert_at_head(head, value);
        return;
    }
    // edge case optimization
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *iterNode = head;
    // we want to reach one position before the insertion position (which is i - 1), so that iterNode->link could be the newNode, at the correct position of insertion, i => hence position -= 1;
    position -= 1;
    while (position--)
    {
        iterNode = iterNode->link;
    }
    // otherwise we will lose any connection to that node
    Node *temp = iterNode->link;
    iterNode->link = newNode;
    newNode->link = temp;
}

int main(void)
{
    Node *head = new Node(10);
    // INSERTION:
    cout << "Insertion At Head/Tail/Position" << endl;
    print(head);
    insert_at_head(head, 5);
    print(head);
    insert_at_head(head, 15);
    print(head);
    insert_at_tail(head, 25);
    print(head);
    insert_at_tail(head, 30);
    print(head);
    insert_at_position(head, 0, 44);
    print(head);
    insert_at_position(head, 6, 34);
    print(head);
}