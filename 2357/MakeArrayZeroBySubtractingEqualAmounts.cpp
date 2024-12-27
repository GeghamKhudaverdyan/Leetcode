#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    int minimumOperations(std::vector<int>& nums) {
        std::unordered_set<int> uSet;
        for(int i : nums) {
            if(i != 0) {
                uSet.insert(i);
            }
        }
        return uSet.size();
    }
};

int main() {
    std::vector<int> vec{1,5,0,3,5};
    Solution solution;
    int result = solution.minimumOperations(vec);
    std::cout << "Minimum operations: " << result << std::endl;
    return 0;
}
