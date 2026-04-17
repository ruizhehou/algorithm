//
// Created by Ruizhe Hou on 2020/10/13.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *cur = dummy, *tmp, *firstNode, *secondNode;
        while (head != NULL && head->next != NULL) {
            firstNode = head;
            secondNode = head->next;
            cur->next = secondNode;
            firstNode->next = secondNode->next;
            secondNode->next = firstNode;

            cur = firstNode;
            head = firstNode->next;
        }
        return dummy->next;
    }
};

int main() {
    // 1->2->3->4 => 2->1->4->3
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    Solution sol;
    ListNode *res = sol.swapPairs(head);
    while (res) { std::cout << res->val << " "; res = res->next; }
    std::cout << std::endl;
    return 0;
}