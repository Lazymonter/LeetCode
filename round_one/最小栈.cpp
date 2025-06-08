#include <iostream>
#include <stack>
#include <climits>

using namespace std;

class MinStack{
public:
    MinStack(){
        min_stack.push(INT_MAX);//最小栈要有一个用于比较的初值
    }
    ~MinStack(){}
    void push(int x){
        ori.push(x);
        int min_temp = min_stack.top();
        min_temp < x ? min_stack.push(min_temp) : min_stack.push(x);
    }
    void pop(){
        ori.pop();
        min_stack.pop();
    }
    int top(){
        return ori.top();
    }
    int getMin(){
        return min_stack.top();
    }
private:
    stack<int> ori;
    stack<int> min_stack;
};
int main(){
    MinStack *obj = new MinStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(0);
    cout << obj->getMin() << endl;
    cout << obj->top() << endl;
    obj->pop();
    cout << obj->getMin() << endl;
    return 0;
}