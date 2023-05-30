// most efficient solution: reverse(s.begin(),s.end())
// without STL functions:
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        if (s.size() && s.size() != 1)
        {
            int low = 0, high = s.size() - 1;
            while (low < high)
            {
                swap(s[low], s[high]);
                low++;
                high--;
            }
        }
    }
};