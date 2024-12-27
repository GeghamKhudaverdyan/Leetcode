#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

class Solution {
public:
    std::vector<int> kWeakestRows(std::vector<std::vector<int>>& mat, int k) {
        std::vector<std::pair<int, int>> vec{};
        for(int i = 0; i < mat.size(); ++i) {
            vec.push_back({std::count(mat[i].begin(), mat[i].end(), 1), i});
        }
        std::sort(vec.begin(), vec.end());
        std::vector<int> answer{};
        for(int i = 0; i < k; ++i) {
            answer.push_back(vec[i].second);
        }
        return answer;
    }
};

int main() {

    std::vector<std::vector<int>> mat = {
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 1, 0, 0}
    };

    int k = 3;

    Solution solution;
    std::vector<int> weakestRows = solution.kWeakestRows(mat, k);

    std::cout << "The " << k << " weakest rows are: ";
    for (int row : weakestRows) {
        std::cout << row << " ";
    }
    std::cout << std::endl;

    return 0;
}