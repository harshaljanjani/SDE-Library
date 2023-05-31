#include <bits/stdc++.h>
using namespace std;
// implementation of a doubly linked list
// idea: only uses a head pointer
// 1) create a class to encapsulate the attributes of a node in the linked list
// 2) create a constructor to initialize the start node / head node
// 3) create a destructor to free the memory of a node if the link of the given node is NULL
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    // constructor (new keyword)
    Node(int value)
    {
        this->data = value;
        this->next = NULL;
        this->prev = NULL;
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
        iterNode = iterNode->next;
    }
    cout << endl;
}

// note: for all the below functions, Node* &head has been taken, since if we just take in Node* head, a copy would be created
// instead, we want to reference the original linked list head

// ALL INSERTIONS:
// insertion at the head of a doubly linked list:
void insert_at_head(Node *&head, int value)
{
    Node *newNode = new Node(value);
    // edge case condition: when the tail is NULL, or there is no node yet in the linked list
    if (head == NULL)
    {
        head = newNode;
        newNode->prev = NULL;
        newNode->next = NULL;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// insertion in the middle (at a given position)
void insert_at_position(Node *&head, int position, int value)
{
    if (position == 0)
    {
        insert_at_head(head, value);
        return;
    }
    Node *newNode = new Node(value);
    Node *currNode = head;
    Node *nextNode = head->next;
    // we want to reach one position before the insertion position (which is i - 1), at the correct position of insertion, i => hence position -= 1;
    position -= 1;
    while (position--)
    {
        currNode = currNode->next;
        nextNode = nextNode->next;
    }
    // visualize it in this mannner:
    //           newNode
    // currNode           nextNode
    currNode->next = newNode;
    newNode->next = nextNode;
    nextNode->prev = newNode;
    newNode->prev = currNode;
}

// insertion at tail of a doubly linked list
void insert_at_tail(Node *&head, int value)
{
    Node *newNode = new Node(value);
    // edge case condition: when the tail is NULL, or there is no node yet in the linked list
    if (head == NULL)
    {
        head = newNode;
        newNode->prev = NULL;
        newNode->next = NULL;
        return;
    }
    Node *iterNode = head;
    while (iterNode->next != NULL)
    {
        iterNode = iterNode->next;
    }
    iterNode->next = newNode;
    newNode->prev = iterNode;
    newNode->next = NULL;
}

// ALL DELETIONS:
// deletion at the head of a doubly linked list
void delete_at_head(Node *&head)
{
    // edge case condition: when the tail is NULL, or there is no node yet in the linked list
    if (head == NULL)
    {
        cout << "Underflow, Linked List Is Empty" << endl;
        return;
    }
    Node *temp = head;
    head = head->next; // move head pointer to head->next
    temp->next->prev = NULL;
    temp->next = NULL;
    temp->prev = NULL;
    delete temp;
}

// deletion in the middle (at a given position)
void delete_at_position(Node *&head, int position)
{
    // edge case condition 1: when the tail is NULL, or there is no node yet in the linked list
    if (head == NULL)
    {
        cout << "Underflow, Linked List Is Empty" << endl;
        return;
    }
    // smart work
    if (position == 0)
    {
        delete_at_head(head);
        return;
    }
    position -= 1; // we want to reach one position before the deletion position (which is i - 1), at the correct position of deletion, i => hence position -= 1;
    Node *currNode = head;
    Node *nextNode = head->next;
    // edge case condition 2: when there are only two elements in the linked list
    if (nextNode->next == NULL)
    {
        // it will only reach till this condition if position != 0, so position == 1 by deduction
        currNode->next = NULL;
        nextNode->prev = NULL;
        delete nextNode;
        return;
    }
    while (position--)
    {
        currNode = currNode->next;
        nextNode = nextNode->next;
    }
    currNode->next = nextNode->next;
    nextNode->next->prev = currNode;
    nextNode->next = NULL;
    nextNode->prev = NULL;
    delete nextNode;
}

// deletion at the tail of a doubly linked list
void delete_at_tail(Node *&head)
{
    // edge case condition: when the tail is NULL, or there is no node yet in the linked list
    if (head == NULL)
    {
        cout << "Underflow, Linked List Is Empty" << endl;
        return;
    }
    Node *prevTail = head;
    Node *tail = head->next;
    while (tail->next != NULL)
    {
        tail = tail->next;
        prevTail = prevTail->next;
    }
    prevTail->next = NULL;
    tail->prev = NULL;
    delete tail;
}

int main(void)
{
    Node *head = new Node(10);
    // insertion:
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
    insert_at_position(head, 4, 34);
    print(head);
    // deletion:
    cout << "Deletion At Head/Tail/Position" << endl;
    print(head);
    delete_at_head(head);
    print(head);
    delete_at_head(head);
    print(head);
    delete_at_position(head, 2);
    print(head);
    delete_at_tail(head);
    print(head);
    delete_at_position(head, 0);
    print(head);
    delete_at_position(head, 1);
    print(head);
}