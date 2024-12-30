#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int size = matrix.size();
        
        for(int i = 0; i < size / 2; ++i) {
            std::swap(matrix[i], matrix[size - 1 - i]);
        }

        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < size; ++j) {
                if(j > i) {
                    std::swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
    }
};

int main() {

    Solution solution;
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::cout << "Original matrix:" << std::endl;
    for (const auto& row : matrix) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    solution.rotate(matrix);

    std::cout << "Rotated matrix:" << std::endl;
    for (const auto& row : matrix) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}