#include <iostream>
#include <string>
#include <stack>

//For inspections//
void printStack(std::stack<char> s) {
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}

class Solution {
public:
    bool backspaceCompare(std::string s, std::string t) {
        std::stack<char> stackForS;
        std::stack<char> stackForT;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] != '#') {
                stackForS.push(s[i]);
            } else if(!stackForS.empty() && s[i] == '#') {
                stackForS.pop();
            }
        }
        for(int i = 0; i < t.size(); ++i) {
            if(t[i] != '#') {
                stackForT.push(t[i]);
            } else if(!stackForT.empty() && t[i] == '#') {
                stackForT.pop();
            }
        }
        return stackForS == stackForT;
    }
};

int main() {
    Solution solution;

    std::string s1 = "ab#c", t1 = "ad#c";
    std::cout << (solution.backspaceCompare(s1, t1) ? "true" : "false") << std::endl;

    std::string s2 = "ab##", t2 = "c#d#";
    std::cout << (solution.backspaceCompare(s2, t2) ? "true" : "false") << std::endl;

    std::string s3 = "a#c", t3 = "b";
    std::cout << (solution.backspaceCompare(s3, t3) ? "true" : "false") << std::endl;

    std::string s4 = "y#fo##f", t4 = "y#f#o##f";
    std::cout << (solution.backspaceCompare(s4, t4) ? "true" : "false") << std::endl;

    return 0;
}