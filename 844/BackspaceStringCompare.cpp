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

void pushOrPop(std::string str, std::stack<char>& stack) {
    for(char ch : str) {
        if(ch != '#') {
            stack.push(ch);
        } else if(!stack.empty()) {
            stack.pop();    
        }
    }
}

class Solution {
public:
    bool backspaceCompare(std::string s, std::string t) {
        std::stack<char> stackForS;
        std::stack<char> stackForT;
        pushOrPop(s, stackForS);
        pushOrPop(t, stackForT);
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