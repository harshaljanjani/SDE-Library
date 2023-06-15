#include <bits/stdc++.h>
using namespace std;

// stack -> LIFO
// 1) idea: using STL
int main(void)
{
    // https://en.cppreference.com/w/cpp/container/stack
    stack<int> s;
    s.push(2);
    s.push(3);
    s.pop();                                     // 3 is removed
    cout << "Printing top element: " << s.top(); // 2 is added
    cout << "Size of stack is: " << endl
         << s.size() << endl;
    s.empty() ? cout << "Stack is empty" << endl : cout << "Stack is not empty" << endl;
}

// 2) implementing stack using classes
class StackUsingArray
{
    // properties
public:
    int top;
    int *arr;
    int size;
    // constructor
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    // functions / behavior
    // time complexity: O(1)
    void push(int value)
    {
        if (top < size - 1)
        {
            arr[++top] = value;
            return;
        }
        cout << "Stack overflow" << endl;
    }
    // time complexity: O(1)
    void pop()
    {
        if (top >= 0)
        {
            cout << "The popped element is: " << arr[top--] << endl;
            return;
        }
        cout << "Stack underflow" << endl;
    }
    // time complexity: O(1)
    int peek()
    {
        if (top >= 0 && top < size - 1)
        {
            cout << "The peeked element is: " << arr[top] << endl;
            return;
        }
        cout << "Stack is empty or stack overflow" << endl;
    }
    // time complexity: O(1)
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
};

// 3) idea: stack implementation using a linked list
class Node
{
public:
    int data;
    Node *next;
    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class StackUsingLinkedList
{
    Node *top;

public:
    StackUsingLinkedList()
    {
        top = NULL;
    }
    // functions / behavior
    // time complexity: O(1)
    void push(int data)
    {
        Node *temp = new Node(data);
        // check if stack (heap) is full.
        // then inserting an element would
        // lead to stack overflow
        if (!temp)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        temp->data = data;
        temp->link = top;
        top = temp;
    }
    // time complexity: O(1)
    void pop()
    {
        Node *temp;
        if (top == NULL)
        {
            cout << "\nStack underflow" << endl;
            return;
        }
        else
        {
            temp = top;
            top = top->link;
            // this will automatically destroy the link between the first node and the second node
            // delete the temp node (old top)
            free(temp);
        }
    }
    // time complexity: O(1)
    void peek()
    {
        // if stack is not empty , return the top element
        if (!isEmpty())
            cout << "The peeked element is: " << top->data << endl;
        else
            cout << "Stack underflow" << endl;
    }
    // time complexity: O(1)
    bool isEmpty()
    {
        return top == NULL;
    }
    // time complexity: O(1)
    void display()
    {
        Node *temp;
        if (top == NULL)
        {
            cout << "Stack underflow" << endl;
            return;
        }
        else
        {
            temp = top;
            while (temp != NULL)
            {
                cout << temp->data;
                temp = temp->link;
                if (temp != NULL)
                    cout << " -> ";
            }
        }
    }
};