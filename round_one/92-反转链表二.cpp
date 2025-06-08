#include <iostream>
#include <vector>


#include "utils/myutil.hpp"

ListNode *reverseBetween(ListNode *head, int m, int n) {
    if (m >= n || head == nullptr) {
        return head;
    }
    ListNode *node = new ListNode(0);
    node->next = head;

    int i = 1;
    ListNode *cursor = head;
    ListNode *pre = node;
    ListNode *startOri = nullptr;
    ListNode *endOri = nullptr;
    ListNode *headPre = nullptr;
    ListNode *endNext = nullptr;

    while (cursor != nullptr) {
        if (i == m) {
            headPre = pre;
            startOri = cursor;
            pre = cursor;
            cursor = cursor->next;
            i++;
        } else if (i > m && i <= n) {
            ListNode *temp = cursor->next;
            endOri = cursor;
            cursor->next = pre;
            pre = cursor;
            cursor = temp;
            endNext = cursor;
            i++;
        } else {
            pre = cursor;
            cursor = cursor->next;
            i++;
        }
    }

    headPre->next = endOri;
    startOri->next = endNext;
    return node->next;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode *head = initLinkList(nums);
    printLinkList(reverseBetween(head, 2, 4));
    return 0;
}