#include <bits/stdc++.h>
using namespace std;
// case 1: without removing extra whitespaces
// time: 6:00 AM to 6:35 AM (implemented the code without removing extra whitespaces)
// idea: 1) we start from the highest index, and initialize two integer pointers, high and low.
// 2) until s[low] is a whitespace, decrement low by 1
// 3) once s[low] is a whitespace, add the substring from (low + 1) to high to the new resultant string, res, and also add an extra whitespace (seperation between two words)
// 4) set high and low to (low - 1) (the index just before the whitespace)
// terminal condition optimization: once low becomes -1, we know we have exhausted the length of the string, so add the substring from low + 1 (0) to high to the resultant array (an extra whitespace is not added since this is the last word in the string)

// case 2: stack implementation to remove extra whitespaces
// time: 6:45 AM to 7:00 AM (implemented the code with removal of extra whitespaces)
// idea: 1) initialize a string array, and a TOP integer pointer at -1 (stack implementation as an array)
// 2) each word is taken, and if it is not a blank space or an empty string, it is pushed on to the stack
// 3) the words are popped and added to a result string until the TOP pointer becomes -1 (we use a stack to get the words in reverse order, naturally)
// 4) we insert a whitespace after each word, unless (TOP equals -1, thus the last word had just been popped from the stack)

// case 1: without removing extra whitespaces (leading, trailing and in the middle)
class Solution
{
public:
    string reverseWords(string s)
    {
        int high = s.size() - 1, low = s.size() - 1;
        string res;
        while (low >= -1)
        {
            if (low == -1)
            {
                res += s.substr(low + 1, high + 1);
                low--;
            }
            else if (s[low] != ' ')
            {
                low--;
            }
            else
            {
                res += (s.substr(low + 1, high - low));
                res.push_back(' ');
                low--;
                high = low;
            }
        }
        return res;
    }
};

// case 2: with removing extra whitespaces: stack implementation
class Solution
{
private:
    string A[1000];
    int TOP = -1;
    void push(string s)
    {
        A[++TOP] = s;
    }
    string pop()
    {
        return A[TOP--];
    }

public:
    string reverseWords(string s)
    {
        string result = "", temp = "";
        int i = 0;
        // split the strings and enqueue
        while (i < s.size())
        {
            while (i < s.size() && s[i] != ' ')
            {
                temp += s[i++];
            }
            i++;
            if (temp != " " && temp != "")
            {
                push(temp);
            }
            temp = "";
        }
        while (TOP != -1)
        {
            result += pop();
            if (TOP != -1)
            {
                result += " ";
            }
        }
        return result;
    }
};