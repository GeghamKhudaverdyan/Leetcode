#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        const int size = nums.size();
        if(nums.empty()) {return 0;}

        for(int i = 0, k = size; i < size; ++i) {
            if(nums[i] == nums[i + 1]) {
                int j = i;
                for( ;j < size; ++j) {
                    nums[j] = nums[j + 1];
                }
                nums[--k] = '_';
            }
        }

        int k = 0;
        for(int i = 0; nums[i] != '_'; ++i) {
            ++k;
        }
        return k;
    }
};

int main() {
    std::vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    Solution solution;

    int k = solution.removeDuplicates(nums);
    std::cout << k << std::endl;

    for(int i = 0; i < k; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}