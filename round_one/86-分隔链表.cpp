#include <iostream>


#include "utils/myutil.hpp"

using namespace std;
// 分组即可，大小各一组
ListNode *partition(ListNode *head, int x) {
    ListNode *large = new ListNode(0);
    ListNode *small = new ListNode(0);
    ListNode *smallHead = small;
    ListNode *largeHead = large;
    while (head != nullptr) {
        if (head->val < x) {
            small->next = head;
            small = small->next;
        } else {
            large->next = head;
            large = large->next;
        }

        head = head->next;
    }

    large->next = nullptr;
    small->next = largeHead->next;
    return smallHead->next;
}

int main() {
    vector<int> list = {1, 4, 3, 2, 5, 2};
    ListNode *head = initLinkList(list);
    printLinkList(partition(head, 3));
    return 0;
}