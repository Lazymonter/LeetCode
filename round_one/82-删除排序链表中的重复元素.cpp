
#include <iostream>
#include <vector>

#include "utils/myutil.hpp"


using namespace std;

ListNode *deleteDuplicates(ListNode *head) {
    if (nullptr == head || nullptr == head->next) {
        return head;
    }

    ListNode *node = new ListNode(0);
    node->next = head;
    ListNode *headTemp = head;
    ListNode *diffNode = node;
    int preDel = 500;
    while(nullptr != headTemp->next) {
        if (headTemp->val == headTemp->next->val || headTemp->val == preDel) {
            ListNode *temp = headTemp;
            preDel = headTemp->val;
            diffNode->next = headTemp->next;
            headTemp = headTemp->next;
            delete temp;
        } else {
            diffNode = headTemp;
            headTemp = headTemp->next;
        }
    }
    
    if (headTemp->val == preDel) {
        diffNode->next = nullptr;
        delete headTemp;
    }

    return node->next;
}

ListNode *deleteDuplicates_o(ListNode *head) {
    if (!head) return head;

    ListNode *dummy = new ListNode(0, head);
    ListNode *cur = dummy;
    while (cur->next && cur->next->next) {
        if (cur->next->val == cur->next->next->val) {
            int x = cur->next->val;
            while (cur->next && cur->next->val == x) {
                cur->next = cur->next->next;
            }
        } else {
            cur = cur->next;
        }
    }
    return dummy->next;
}


int main() {
    vector<int> node1 = {1, 2, 3, 3, 4, 4, 5};
    vector<int> node2 = {1, 1, 1, 2, 3};
    vector<int> node3 = {1, 2, 3, 4, 4, 5, 5};
    ListNode *head1 = initLinkList(node1);
    ListNode *head2 = initLinkList(node2);
    ListNode *head3 = initLinkList(node3);
    printLinkList(deleteDuplicates(head1));
    printLinkList(deleteDuplicates(head2));
    printLinkList(deleteDuplicates(head3));
    return 0;
}