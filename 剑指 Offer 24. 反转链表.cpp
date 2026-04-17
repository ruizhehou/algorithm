//
// Created by Ruizhe Hou on 2020/10/10.
//


#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = NULL;
        ListNode *cur = head;
        while (cur != NULL) {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};

int main() {
    // 1->2->3->4->5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution sol;
    ListNode *res = sol.reverseList(head);
    while (res) { std::cout << res->val << " "; res = res->next; }
    std::cout << std::endl; // 5 4 3 2 1
    return 0;
}