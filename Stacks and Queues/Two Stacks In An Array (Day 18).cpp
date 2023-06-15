#include <bits/stdc++.h>
using namespace std;
// idea: stack 1 elements would be filled from left to right (top1 = -1), and stack2 elements would be filled from right to left (top2 = size)
// alternative: (size = n/2) for each stack (leads to under-utlilization of memory)

class TwoStack
{
    int *arr;
    int top1;
    int top2;
    int size;

public:
    // initialize TwoStack
    TwoStack(int s)
    {
        this->size = s;
        this->top1 = -1;
        this->top2 = s;
        arr = new int[s];
    }
    // push in stack 1
    void push1(int num)
    {
        // atleast one empty space must be present
        if (top2 - top1 > 1)
        {
            arr[++top1] = num;
            return;
        }
    }
    // push in stack 2
    void push2(int num)
    {
        if (top2 - top1 > 1)
        {
            arr[--top2] = num;
            return;
        }
    }
    // pop from stack 1 and return popped element
    int pop1()
    {
        if (top1 >= 0)
        {
            return arr[top1--];
        }
        return -1;
    }
    // pop from stack 2 and return popped element
    int pop2()
    {
        if (top1 < size)
        {
            return arr[top2++];
        }
        return -1;
    }
};
