#include<iostream>
using namespace std;
class Stack {
    public:
    int top;
    int arr[100];
    Stack() {
        top = -1;
    }
    void push(int x){
        if(top == 99){
            cout << "Stack Overflow: " << endl;
            return; 
        }
        arr[++top] = x;
    }
    int pop(){
        if(top == -1){
            cout << "Stack Underflow: " << endl;
            return -1;
        }
        return arr[top--];
    }
    int peek(){
        if(top == -1){
            cout << "Stack is empty: " << endl;
            return -1;
        }
        return arr[top];
    }
    bool isEmpty(){
        return top == -1;
    }
};
int main(){
    Stack st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    //st.pop();
    st.peek();
    return 0;
}