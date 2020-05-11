#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print_linklist(ListNode *head){
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *forward = head;
    ListNode *beh = head;
    for(int i = 0;i <= n;i++){
        if(forward == NULL){
            return head->next;
        }
        forward = forward->next;
    }
    while(forward != NULL){
        forward = forward->next;
        beh = beh->next;
    }
    ListNode *del = beh->next;
    beh->next = beh->next->next;
    del->next = NULL;
    return head;
}


int main(){
    ListNode a1(1),a2(2),a3(3),a4(4),a5(5);
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = &a5;
    ListNode *head = removeNthFromEnd(&a1,2);
    print_linklist(head);
    return 0;
}