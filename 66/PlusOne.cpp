#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        const int size = digits.size();
        int num = 0;
        for(int i = size - 1; i >= 0; --i) {
            if(digits[i] < 9) {
                ++digits[i];
                return digits;
            }
            digits[i] = 0;
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    std::vector<int> nums = {1,9,9,9};
    Solution solution;

    std::vector<int> answer = solution.plusOne(nums);

    std::cout << "The result:" << std::endl; 
    for(int i = 0; i < answer.size(); ++i) {
        std::cout << answer[i];
    }
    std::cout << std::endl;

    return 0;
}