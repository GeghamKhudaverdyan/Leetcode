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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode* fast = head->next->next;
        ListNode* slow = head;

        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* keepNextToErasable = slow->next->next;
        delete slow->next;
        slow->next = keepNextToErasable;
        return head;
    }
};

ListNode* createList() {
    ListNode* head = new ListNode(1);
    // head->next = new ListNode(3);
    // head->next->next = new ListNode(4);
    // head->next->next->next = new ListNode(7);
    // head->next->next->next->next = new ListNode(1);
    // head->next->next->next->next->next = new ListNode(2);
    // head->next->next->next->next->next->next = new ListNode(6);
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
    /////////// 1 -> 3 -> 4 -> 7 -> 1 -> 2 -> 6
    ListNode* head = createList();
    Solution solution;
    printList(head);

    head = solution.deleteMiddle(head);

    printList(head);
    dealocateList(head);    
    return 0;
}