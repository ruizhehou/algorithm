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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        bool noCycle = true;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                noCycle = false;
                break;
            }
        }
        if (noCycle) return nullptr;
        fast = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};

int main() {
    // 有环: 3->2->0->-4->2, 入环节点为2
    ListNode *n1 = new ListNode(3);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(0);
    ListNode *n4 = new ListNode(-4);
    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n2;
    Solution sol;
    ListNode *entry = sol.detectCycle(n1);
    cout << (entry ? entry->val : -1) << endl; // 2
    // 无环
    ListNode *m1 = new ListNode(1);
    entry = sol.detectCycle(m1);
    cout << (entry ? entry->val : -1) << endl; // -1
    return 0;
}