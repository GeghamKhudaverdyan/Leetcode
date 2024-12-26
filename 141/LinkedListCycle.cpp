#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) {
            return false;
        }
        ListNode* current = head->next;
        while(current != nullptr && current->next != nullptr) {
            if(head == current) {
                return true;
            }
            head = head->next;
            current = current->next->next;
        }
        return false;
    }
};

ListNode* createList() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next->next = new ListNode(4);
    return head;
}

void printList(ListNode* head) {
    ListNode* print = head;
    while(print != nullptr) {
        std::cout << print->val << " -> ";
        print = print->next;
    }
    std::cout << 'x' << std::endl;
}

void dealocateList(ListNode* head) {
    while(head != nullptr) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    /////////// 1 -> 1 -> 1 -> 1 -> 3 -> 4 -> 4 -> 4
    ListNode* head = createList();
    Solution solution;
    if(solution.hasCycle(head)) {
        std::cout << "There is a cycle in the linked list." << std::endl;
    } else {
        std::cout << "There is not a cycle in the linked list." << std::endl;
    }
    dealocateList(head);
    return 0;
}