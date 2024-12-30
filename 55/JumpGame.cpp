#include <iostream>
#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int last = nums.size() - 1;
        int prev = last - 1;

        while(last != 0) {
            if(prev < 0) {
                return false;
            }
            if(last - prev > nums[prev]) {
                --prev;
            } else {
                last = prev;
                --prev;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {2, 1, 1, 0, 4};

    if (solution.canJump(nums)) {
        std::cout << "Can reach the last index." << std::endl;
    } else {
        std::cout << "Cannot reach the last index." << std::endl;
    }
    return 0;
}