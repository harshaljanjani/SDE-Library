#include <bits/stdc++.h>
using namespace std;
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

// approach 1
// idea: 1) copy the contents of the linked list into an array, and apply the same palindrome logic as that of an array or string (start++/end--)
class Solution
{
private:
    bool checkPalindrome(vector<int> &arr)
    {
        int start = 0, end = arr.size() - 1;
        while (start <= end)
        {
            if (arr[start] != arr[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

public:
    bool isPalindrome(Node *head)
    {
        vector<int> arr;
        Node *temp = head;
        while (temp != NULL)
        {
            arr.push_back(temp->data);
            temp = temp->next;
        }
        return checkPalindrome(arr);
    }
};
// time complexity: O(n) (copy content O(n) + check palindrome O(n))
// space complexity: O(n)

// approach 2
// idea: 1) find middle node of the linked list
// 2) reverse the linked list after the middle node
// 3) compare both halves node by node -> if equal, return true else return false
class Solution
{
private:
    // function to find the middle node
    Node *findMiddle(Node *head)
    {
        Node *slow = head;
        Node *fast = head->next;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
            }
        }
        return slow;
    }
    // function to reverse the entire linked list starting from (Node* middle->next)
    Node *reverse(Node *middle)
    {
        // technically, it is middle->next and middle->next->next
        Node *prev = NULL;
        Node *next = NULL;
        Node *curr = middle;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    // comparison of pair of nodes, starting from the node pair (Node* head, Node* middle->next)
    bool compareByNode(Node *head, Node *middle)
    {
        while (middle != NULL)
        {
            if (head->data != middle->data)
            {
                return false;
            }
            head = head->next;
            middle = middle->next;
        }
        return true;
    }

public:
    bool isPalindrome(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        // find the middle of the linked list
        Node *middle = findMiddle(head);
        // reverse the linked list after the middle node;
        Node *temp = middle->next;
        middle->next = reverse(temp);
        // compare both halves node by node
        return compareByNode(head, middle->next);
    }
};
// time complexity: O(n)
// space complexity: O(n)