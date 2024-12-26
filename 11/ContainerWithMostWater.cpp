#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_area = 0;
        
        while (left < right) {
            int current_area = (right - left) * std::min(height[left], height[right]);
            max_area = std::max(max_area, current_area);
            
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return max_area;
    }
};

int main() {
    std::vector<int> nums = {1,8,6,2,5,4,8,3,7};
    Solution solution;

    int answer = solution.maxArea(nums);

    std::cout << "The max area of water is: " << answer << std::endl;

    return 0;
}