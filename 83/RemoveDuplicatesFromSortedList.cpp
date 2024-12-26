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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) {
            return head;
        }
        ListNode* current = head;
        ListNode* hold = current->next;

        while(current->next != nullptr) {
            if(current->val == current->next->val) {
                hold = current->next->next;
                delete current->next;
                current->next = hold;
            } else {
                current = current->next;
            }
        }
        return head;
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
    printList(head);

    ListNode* singleNumbers = solution.deleteDuplicates(head);

    printList(singleNumbers);
    dealocateList(singleNumbers);
    return 0;
}