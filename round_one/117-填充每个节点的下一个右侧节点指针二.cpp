#include <iostream>

#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

//层序遍历
Node *connect(Node *root) {
    if (root == nullptr) {
        return nullptr;
    }

    queue<Node *> q;
    q.emplace(root);
    while (!q.empty()) {
        int len = q.size();
        for (int i = 0; i < len; ++i) {
            Node *temp = q.front();
            q.pop();
            if (i != len - 1) {
                temp->next = q.front();
            }

            if (temp->left != nullptr) {
                q.emplace(temp->left);
            }

            if (temp->right != nullptr) {
                q.emplace(temp->right);
            }            
        }
    }
    return root; 
}


//使用已建立的next指针降低空间复杂度
/*
从根节点开始。因为第 00 层只有一个节点，不需要处理。可以在上一层为下一层建立 
nextnext 指针。该方法最重要的一点是：位于第 xx 层时为第 x + 1x+1 层建立
nextnext 指针。一旦完成这些连接操作，移至第 x + 1x+1 层为第 x + 2x+2 层建立 
nextnext 指针。
当遍历到某层节点时，该层节点的
nextnext 指针已经建立。这样就不需要队列从而节省空间。
每次只要知道下一层的最左边的节点，就可以从该节点开始，像遍历链表一样遍历该层的所有节点。
*/
void handle(Node* &last, Node* &p, Node* &nextStart) {
    if (last) {
        last->next = p;
    } 
    if (!nextStart) {
        nextStart = p;
    }
    last = p;
}

Node* connect(Node* root) {
    if (!root) {
        return nullptr;
    }
    Node *start = root;
    while (start) {
        Node *last = nullptr, *nextStart = nullptr;
        for (Node *p = start; p != nullptr; p = p->next) {
            if (p->left) {
                handle(last, p->left, nextStart);
            }
            if (p->right) {
                handle(last, p->right, nextStart);
            }
        }
        start = nextStart;
    }
    return root;
}