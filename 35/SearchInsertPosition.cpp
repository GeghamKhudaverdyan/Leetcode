#include <iostream>
#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        if(nums.empty()) {return 0;}
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;
            
            if(nums[mid] == target) {
                return mid;
            } else if(target > nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};

int main() {
    const int TARGET = 50;
    std::vector<int> nums = {1,3,5,6,7};
    Solution solution;

    int answer = solution.searchInsert(nums, TARGET);
    
    std::cout << answer << std::endl;

    return 0;
}