#include <bits/stdc++.h>
using namespace std;
// idea: 1) given an integer n, our task is to print the digits of the integer in words
// 2) recursively get the last digit of the integer (n % 10) and divide by 10 (n = n / 10) with each iteration
// 3) call sayDigit(n / 10, mapping), and set n == 0 as the base case (no more digits left to convert to text)
// question: why did it not print the number backwards in text? => answer is given by the recursive tree diagram (dry run)

void sayDigit(int n, string mapping[])
{
    if (n == 0)
    {
        return;
    }
    int digit = n % 10;
    sayDigit(n / 10, mapping);
    cout << mapping[digit] << " ";
}

int main(void)
{
    int n;
    cin >> n;
    string mapping[11] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten"};
    sayDigit(n, mapping);
}