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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* current = head;
        ListNode dummyFirstPart;
        ListNode* firstPart = &dummyFirstPart;
        ListNode dummySecondPart;
        ListNode* secondPart = &dummySecondPart;

        while(current != nullptr) {
            if(current->val < x) {
                firstPart->next = current;
                firstPart = firstPart->next;
            } else {
                secondPart->next = current;
                secondPart = secondPart->next;
            }
            current = current->next;
        }
        secondPart->next = nullptr;

        firstPart->next = dummySecondPart.next;
        return dummyFirstPart.next;
    }
};

ListNode* createList() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);
    // head->next->next->next->next->next->next = new ListNode(7);
    // head->next->next->next->next->next->next->next = new ListNode(8);
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
    /////////// 1 -> 4 -> 3 -> 2 -> 5 -> 2
    ListNode* head = createList();
    Solution solution;
    printList(head);

    head = solution.partition(head, 3);

    printList(head);
    dealocateList(head);    
    return 0;
}