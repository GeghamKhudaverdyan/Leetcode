#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int trap(std::vector<int>& height) {
       
        if(height.size() < 3) {return 0;}

        int water = 0;
        int begin = 1;
        int end = height.size() - 2;
        int leftBiger = 0;
        int rightBiger = height.size() - 1;

        while (begin <= end) {
            if(height[leftBiger] < height[rightBiger]) {
                if(height[begin] <=  height[leftBiger]) {
                    water += height[leftBiger] - height[begin];
                    ++begin;
                } else {
                    leftBiger = begin;
                }
            } else {
                if(height[end] <= height[rightBiger]) {
                    water += height[rightBiger] - height[end];
                    --end;
                } else {
                    rightBiger = end;
                }
            }
        }
        return water;
    }
};

int main() {
    std::vector<int> vec{4,2,0,3,2,5};
    Solution solution;
    int result = solution.trap(vec);
    std::cout << "Trapped water: " << result << std::endl;
    return 0;
}