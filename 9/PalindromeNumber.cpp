#include <iostream>
#include <vector>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        std::vector<int> s;
        while (x > 0) {
            int a = x % 10;
            s.push_back(a);
            x /= 10;
        }

        int size = s.size();
        for (int i = 0; i < size / 2; ++i) {
            if (s[i] != s[size - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution{};
    int num = 0;

    std::cout << "Enter a number to check if it's a palindrome: ";
    std::cin >> num;

    if (solution.isPalindrome(num)) {
        std::cout << num << " is a palindrome." << std::endl;
    } else {
        std::cout << num << " is not a palindrome." << std::endl;
    }

    return 0;
}
