//
// Created by Ruizhe Hou on 2020/10/9.
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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

int main() {
    // 有环: 3->2->0->-4->2
    ListNode *n1 = new ListNode(3);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(0);
    ListNode *n4 = new ListNode(-4);
    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n2;
    Solution sol;
    cout << sol.hasCycle(n1) << endl; // 1
    // 无环
    ListNode *m1 = new ListNode(1);
    ListNode *m2 = new ListNode(2);
    m1->next = m2;
    cout << sol.hasCycle(m1) << endl; // 0
    return 0;
}