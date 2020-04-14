#include <iostream>
#include <stack>

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
/*
// 反转法
ListNode *reverseLinkList(ListNode *l){
    ListNode *pCur = l->next;
    ListNode *prev = l;
    ListNode *pNext = l->next;
    l->next = NULL;
    while(pCur != NULL){
        pNext = pCur->next;
        pCur->next = prev;
        prev = pCur;
        pCur = pNext;
    }
    return prev;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if(l1->val == 0){
        return l2;
    }
    else if(l2->val == 0){
        return l1;
    }
    else{
        ListNode result(0);
        ListNode * result_cur = &result;
        l1 = reverseLinkList(l1);
        l2 = reverseLinkList(l2);
        int carry = 0;
        while(l1 != NULL && l2 != NULL){
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            result_cur->next = new ListNode(sum % 10);
            result_cur = result_cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL){
            int sum = l1->val + carry;
            carry = sum / 10;
            result_cur->next = new ListNode(sum % 10);
            result_cur = result_cur->next;
            l1 = l1->next;
        }
        while(l2 != NULL){
            int sum = l2->val + carry;
            carry = sum / 10;
            result_cur->next = new ListNode(sum % 10);
            result_cur = result_cur->next;
            l2 = l2->next;
        }
        if(carry != 0){
            result_cur->next = new ListNode(carry);
        }
        return reverseLinkList(result.next);
    }
}
*/

// 非反转法
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *result = NULL;
    int carry = 0;
    stack<int> num1,num2;
    while(l1){
        num1.push(l1->val);
        l1 = l1->next;
    }
    while(l2){
        num2.push(l2->val);
        l2 = l2->next;
    }
    while(!num1.empty() or !num2.empty() or carry != 0){
        int a = num1.empty() ? 0 : num1.top();
        int b = num2.empty() ? 0 : num2.top();
        if(!num1.empty()){
            num1.pop();
        }
        if(!num2.empty()){
            num2.pop();
        }
        int sum = a + b + carry;
        carry = sum / 10;
        auto temp = new ListNode(sum % 10);
        temp->next = result;
        result = temp;
    }
    return result;
}
int main(){
    ListNode a1(1),a2(2),a3(3),a4(4),a5(5);
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = &a5;
    ListNode b1(1),b2(2),b3(3),b4(4),b5(5);
    b1.next = &b2;
    b2.next = &b3;
    b3.next = &b4;
    b4.next = &b5;
    ListNode c(5),d(5);
    ListNode *head = addTwoNumbers(&d,&c);
    print_linklist(head);
    return 0;
}