#include <bits/stdc++.h>
using namespace std;
// implementation of a circular linked list
// idea: only uses a tail pointer
// 1) create a class to encapsulate the attributes of a node in the linked list
// 2) create a constructor to initialize the start node / head node
// 3) create a destructor to free the memory of a node if the link of the given node is NULL
class Node
{
public:
    int data;
    Node *link;
    // constructor
    Node(int value)
    {
        this->data = value;
        this->link = NULL;
    }
    // destructor is called whenever a node pointer is prefixed with the "delete" keyword
    // idea: if the node is not null, then *cut the connection* with any of the rest of the nodes linked to this node, by setting *this->link = NULL*
    ~Node()
    {
        // save value for console trace of deletion
        int value = this->data;
        if (this->link != NULL)
        {
            delete this->link;
            this->link = NULL;
        }
        cout << "Memory Has Been Freed For The Node With Data " << value << endl;
    }
};

// utility function: display all elements
void print(Node *&tail)
{
    // edge case condition: when the tail is NULL, or there is no node yet in the linked list
    if (tail == NULL)
    {
        cout << "Underflow, The Linked List Is Empty!";
        return;
    }
    Node *iterNode = tail;
    // if we use a simple while(iterNode != tail) loop, the loop would not even execute once (at the start, (iterNode == tail)) so the condition fails)
    // thus we use a post-test do/while loop to execute the loop atleast once, and then only check the condition
    do
    {
        cout << iterNode->data << " ";
        iterNode = iterNode->link;
    } while (iterNode != tail);
    cout << endl;
}

// note: for all the below functions, Node* &head has been taken, since if we just take in Node* head, a copy would be created
// instead, we want to reference the original linked list head

// INSERTION:
// insertion after a certain element of a circular linked list:
void insert_after_element(Node *&tail, int element, int value)
{
    Node *newNode = new Node(value);
    // edge case condition: when the tail is NULL, or there is no node yet in the linked list
    if (tail == NULL)
    {
        tail = newNode;
        // important
        // tail->link = tail not NULL, since it is a circular linked list
        tail->link = tail;
        return;
    }
    Node *iterNode = tail;
    // reach the node after which the newNode has to be inserted
    while (iterNode->data != element)
    {
        iterNode = iterNode->link;
    }
    // visualize it in this mannner:
    //           newNode
    // iterNode           iterNode->link
    newNode->link = iterNode->link;
    iterNode->link = newNode;
}

// DELETION:
// deletion after a certain element of a linked list
void delete_element(Node *&tail, int element)
{
    Node *iterNode = tail;
    // edge case condition: when the tail is NULL, or there is no node yet in the linked list
    if (tail == NULL)
    {
        cout << "Underflow, The Linked List Is Empty!";
        return;
    }
    // idea: keep in mind, we have two edge cases here
    // 1) a circular linked list with a single node (tail->link = tail)
    // 2) a circular linked list with two nodes ((tail->link)->link = tail)
    // edge case 1: one node
    if (tail->link == tail)
    {
        // there is only one node in the linked list, delete it
        delete tail;
        return;
    }
    Node *prev = tail;
    Node *curr = tail->link;
    while (curr->data != element)
    {
        curr = curr->link;
        prev = prev->link;
    }
    // edge case 2: two nodes
    if (curr->link == prev)
    {
        delete curr;
        tail = prev;
        tail->link = tail;
        return;
    }
    prev->link = curr->link;
    curr->link = NULL;
    delete curr;
    return;
}

int main(void)
{
    Node *tail = NULL;
    insert_after_element(tail, 0, 10); // even though the parameter element = 0 is nonsensical, it won't check it since at the beginning, (tail == NULL) and the value of element does not matter
    print(tail);
    insert_after_element(tail, 10, 20);
    print(tail);
    insert_after_element(tail, 10, 30);
    print(tail);
    insert_after_element(tail, 10, 40);
    print(tail);
    insert_after_element(tail, 40, 50);
    print(tail);
    delete_element(tail, 30);
    print(tail);
    delete_element(tail, 50);
    print(tail);
}