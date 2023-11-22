#include <bits/stdc++.h>
using namespace std;
// idea: 1) if we have two extremes, the left and the right bounds, the water would be stored at the height of the minimum of the two, and in the area between (right - left)
// 2) we keep moving the right and left inwards, until we find the maximum area
// 3) we would move right inwards, if the height[left] > height[right], else we would move left inwards (move lesser height inwards, because it has chance to go greater)
// 4) variables: currentArea to be compared with each iteration with maxArea, minHeight (currentArea = minHeight * (right-left))

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0, right = height.size() - 1, maxArea = INT_MIN;
        for (int i = 0; i < height.size(); i++)
        {
            int minHeight = min(height[left], height[right]);
            int currentArea = minHeight * (right - left);
            maxArea = max(currentArea, maxArea);
            if (height[left] > height[right])
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return maxArea;
    }
};