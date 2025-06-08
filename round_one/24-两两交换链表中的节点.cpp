#include <iostream>


#include "utils/myutil.hpp"

using namespace std;
//迭代法
ListNode *swapPairs(ListNode *head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode *cur = head;
    head = head->next;
    ListNode *pre = cur->next;
    cur->next = pre->next;
    pre->next = cur;
    pre = cur;
    cur = cur->next;
    while (cur != nullptr && cur->next != nullptr) {
        ListNode *temp = cur->next;
        cur->next = temp->next;
        temp->next = cur;
        pre->next = temp;
        pre = cur;
        cur = cur->next;
    }

    return head;
}

//递归法
ListNode *swapPairs(ListNode *head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode *newHead = head->next;
    head->next = swapPairs(newHead->next);
    newHead->next = head;
    return newHead;
}