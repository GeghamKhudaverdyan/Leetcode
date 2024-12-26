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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* keep = new ListNode();
        ListNode* hold = keep;
        while(list1 != nullptr && list2 != nullptr) {
            if(list1->val < list2->val) {
                keep->next = list1;
                list1 = list1->next;
            } else {
                keep->next = list2;
                list2 = list2->next;
            }
            keep = keep->next;
        }
        if(list1 != nullptr) {
            keep->next = list1;
        } else if(list2 != nullptr) {
            keep->next = list2;
        }
        ListNode* del = hold->next;
        delete hold;
        return del;
    }
};

ListNode* createList() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);
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
    /////////// 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
    ListNode* head1 = createList();
    ListNode* head2 = createList();
    Solution solution;
    printList(head1);
    printList(head2);
    
    ListNode* merge = solution.mergeTwoLists(head1, head2);

    printList(merge);
    dealocateList(merge);    
    return 0;
}