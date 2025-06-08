//给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。
//你可以假设除了数字 0 之外，这两个数字都不会以零开头。
//初等数学知识，逆序存储只需按照链表顺序从前往后相加即可
//如果链表不是逆序存储，可以按照链表顺序依次将值压入栈，然后从栈取出依次相加，结果压入结果栈最后按弹出顺序组成链表即可
#include<iostream>
#include<string>
#include<vector>

using namespace std;
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * temp1 = l1;
        ListNode * temp2 = l2;
        ListNode * temp3 = NULL;
        ListNode * temp4 = NULL;
        ListNode * result = NULL;
        int carry = 0;
        while(temp1 != NULL && temp2 != NULL)
        {
            carry = temp1->val + temp2->val + carry;
            temp3 = new ListNode(carry % 10);
            carry = carry / 10;
            if(result == NULL)
            {
                result = temp3;
                temp4 = temp3;
            }
            else
            {
                temp4->next = temp3;
                temp4 = temp3;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
            
        }
        while(temp1 != NULL)
        {
            carry = temp1->val + carry;
            temp3 = new ListNode(carry % 10);
            carry = carry / 10;
            if(result == NULL)
            {
                result = temp3;
                temp4 = temp3;
            }
            else
            {
                temp4->next = temp3;
                temp4 = temp3;
            }
            temp1 = temp1->next;            
        }
        while(temp2 != NULL)
        {
            carry = temp2->val + carry;
            temp3 = new ListNode(carry % 10);
            carry = carry / 10;
            if(result == NULL)
            {
                result = temp3;
                temp4 = temp3;
            }
            else
            {
                temp4->next = temp3;
                temp4 = temp3;
            }
            temp2 = temp2->next;  
        }
        if(carry != 0)
        {
            temp3 = new ListNode(carry % 10);
            if(result == NULL)
            {
                result = temp3;
                temp4 = temp3;
            }
            else
            {
                temp4->next = temp3;
                temp4 = temp3;
            }
        }
        return result;
        
    }
