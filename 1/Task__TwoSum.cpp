#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        const int size = nums.size();
        std::vector<int> answer;
        bool flag = false;

        for(int i = 0; i < size; ++i) {
            for(int j = i + 1; j < size; ++j) {
                if(nums[i] + nums[j] == target) {
                    answer.push_back(i);
                    answer.push_back(j);
                    flag = true;
                    break;                    
                }
            }
            if(flag) {
                return answer;
            }
        }
        return {};
    }
};

int main() {
    const int TARGET = 6;
    std::vector<int> nums = {3,2,4};
    Solution solution;

    std::vector<int> answer = solution.twoSum(nums, TARGET);
    if(answer.empty()) {
        std::cout << "There are no numbers in this array whose sum is equal to target." << std::endl;
    } else {
        std::cout << "The sum of the numbers in these two indexes is equal to the target:" << std::endl;
        for(int i = 0; i < answer.size(); ++i) {
            std::cout << answer[i] << std::endl;
        }
    }
    
    return 0;
}