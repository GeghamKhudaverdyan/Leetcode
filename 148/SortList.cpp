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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* mid = devide(head);
        ListNode* holdMid = mid->next;
        mid->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(holdMid);
        return merge(left, right);
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) {
            return list2;
        }
        if(list2 == nullptr) {
            return list1;
        }
        ListNode* hold = new ListNode();
        ListNode* keep = hold;

        while(list1 != nullptr && list2 != nullptr) {
            if(list1->val < list2->val) {
                hold->next = list1;
                list1 = list1->next;
            } else {
                hold->next = list2;
                list2 = list2->next;
            }
            hold = hold->next;
        }
        hold->next = (list1 == nullptr) ? list2 : list1;
        ListNode* tmpNode = keep->next;
        delete keep;
        return tmpNode;
    }
    ListNode* devide(ListNode* head) {
        if(head == nullptr && head->next == nullptr) {
            return head;
        }
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

ListNode* createList() {
    ListNode* head = new ListNode(110);
    head->next = new ListNode(5);
    head->next->next = new ListNode(-1);
    head->next->next->next = new ListNode(0);
    head->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(6);
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
    /////////// 110 -> 5 -> (-1) -> 0 -> 1 -> 5 -> 7 -> 6
    ListNode* head = createList();
    Solution solution;
    printList(head);

    ListNode* sortedList = solution.sortList(head);

    printList(sortedList);
    dealocateList(sortedList);
    return 0;
}