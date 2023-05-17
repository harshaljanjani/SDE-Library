// approach: naive (loop through the array to find min and max)
class Solution
{
public:
    int findSum(int A[], int N)
    {
        int max = A[0], min = A[0];
        for (int i = 0; i < N; i++)
        {
            if (A[i] > max)
            {
                max = A[i];
            }
            if (A[i] < min)
            {
                min = A[i];
            }
        }
        return (min + max);
    }
};