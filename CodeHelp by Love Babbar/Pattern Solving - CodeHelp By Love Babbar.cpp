#include <iostream>
using namespace std;
// all my pattern solving practice (27.05.2023):
// n - j + 1 (reverse square nxn), i + j - 1 (1 2 3; 2 3 4; 3 4 5)
int main()
{
    // numerical patterns
    // pattern 1:
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j >= 1; j--)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;

    // pattern 2:
    // 1 2 3; 1 2 3; 1 2 3; -> 3 2 1; 3 2 1; 3 2 1;
    // formula: n - j + 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << n - j + 1 << " ";
        }
        cout << endl;
    }
    cout << endl;

    // pattern 3:
    int j = 1;
    while (j <= n * n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << j++ << " ";
        }
        cout << endl;
    }
    cout << endl;

    // pattern 4:
    int i = 1;
    while (i <= n)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "* ";
        }
        i++;
        cout << endl;
    }
    cout << endl;

    // pattern 5:
    i = 1;
    while (i <= n)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i << " ";
        }
        i++;
        cout << endl;
    }
    cout << endl;

    // pattern 6:
    i = 1;
    int count = 1;
    j = 1;
    while (i <= n)
    {
        for (int i = 0; i < count; i++)
        {
            cout << j++ << " ";
        }
        cout << endl;
        count++;
        i++;
    }
    cout << endl;

    // pattern 7 (important pattern):
    /*
    1
    2 3
    3 4 5
    4 5 6 7
    */
    i = 1;
    int temp;
    while (i <= n)
    {
        temp = i;
        for (int j = 0; j < i; j++)
        {
            cout << temp++ << " ";
        }
        cout << endl;
        i++;
    }
    cout << endl;

    // pattern 8:
    // without the use of a temporary variable:
    // for (int j = 1; j < i + 1; j++){ cout << j + i - 1 << " ";}
    i = 1;
    while (i <= n)
    {
        for (int j = 1; j < i + 1; j++)
        {
            cout << j + i - 1 << " ";
        }
        cout << endl;
        i++;
    }
    cout << endl;

    // pattern 9:
    i = 1;
    while (i <= n)
    {
        for (int j = i; j >= 1; j--)
        {
            cout << j << " "; // formula: i - j + 1
        }
        cout << endl;
        i++;
    }
    cout << endl;

    // alphabetical patterns
    // pattern 10:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << (char)('A' + i);
        }
        cout << endl;
    }
    cout << endl;

    // pattern 11:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << (char)('A' + j);
        }
        cout << endl;
    }
    cout << endl;

    // pattern 12:
    count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << (char)('A' + count++);
        }
        cout << endl;
    }
    cout << endl;

    // pattern 13:
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << (char)('A' + i + j - 1);
        }
        cout << endl;
    }
    cout << endl;

    // pattern 14:
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << (char)('A' + i - 1);
        }
        cout << endl;
    }
    cout << endl;

    // pattern 15:
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << (char)('A' + i + j - 1);
        }
        cout << endl;
    }
    cout << endl;

    // pattern 16:
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            cout << (char)('A' + n - j + 1); // ('A' + n - i -> starting character)
        }
        cout << endl;
    }
    cout << endl;

    // star/asterisk patterns
    // pattern 17:
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;

    // pattern 18:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;

    // pattern 19:
    for (int i = n; i >= 1; i--)
    {
        int j;
        for (j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;

    // pattern 20:
    for (int i = n; i >= 1; i--)
    {
        int j;
        for (j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (j = 1; j <= i; j++)
        {
            cout << n - i + 1;
        }
        cout << endl;
    }
    cout << endl;

    // pattern 21:
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
    cout << endl;

    // pattern 22:
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            cout << " ";
        }
        for (int j = i; j <= n; j++)
        {
            cout << j;
        }
        cout << endl;
    }
    cout << endl;

    // pattern 23:
    count = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            if (count == 10)
            {
                count = 0;
            }
            cout << count++;
        }
        cout << endl;
    }
    cout << endl;

    // pattern 24 (important):
    /*    1
        1 2 1
      1 2 3 2 1
    1 2 3 4 3 2 1
    */
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        for (int j = i - 1; j >= 1; j--)
        {
            cout << j;
        }
        cout << endl;
    }
}