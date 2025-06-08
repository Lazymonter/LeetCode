#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode *mergeTwoLists(ListNode *a,ListNode *b){
    if((!a) || (!b)) return a ? a : b;
    ListNode head(0);
    ListNode *pCur = &head;
    ListNode *aPtr = a;
    ListNode *bPtr = b;
    while(aPtr && bPtr){
        if(aPtr->val < bPtr->val){
            pCur->next = aPtr;
            aPtr = aPtr->next;
        }
        else{
            pCur->next = bPtr;
            bPtr = bPtr->next;
        }
        pCur = pCur->next;
    }
    pCur->next = (aPtr ? aPtr : bPtr);
    return head.next;
}

ListNode *merge(vector<ListNode *> &lists,int l,int r){
    if(l == r) return lists[l];
    if(l > r) return NULL;
    int mid = (l + r) >> 1;
    return mergeTwoLists(merge(lists,l,mid),merge(lists,mid + 1,r));
}

ListNode *mergeTwoLists_s(vector<ListNode *> &lists){
    return merge(lists,0,lists.size() - 1);
}

ListNode *mergeKLists(vector<ListNode *> &lists){
    ListNode *result = NULL;
    for(ListNode *a : lists){
        result = mergeTwoLists(result,a);
    }
    return result;
}

int main(){
    vector<ListNode *> lists;

    return 0;
}