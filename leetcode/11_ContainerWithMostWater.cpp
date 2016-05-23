#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int sz = height.size();
        int max = 0;
        int start = 0;
        int end = sz -1;
        while (start<end) {
            int contain = min(height[start], height[end])*(end-start);
            if (max<contain)
                max=contain;
            if (height[start]<height[end])
                start++;
            else
                end--;
        }

        return max;
    }
};

int main() {
    Solution s;
    s.maxArea();
}
