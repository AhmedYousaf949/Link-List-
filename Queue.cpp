#include<iostream>
using namespace std;
class Queue {
    private:
    int arr[5];
    int front, rear;
    public:
    Queue(){
        front = -1;
        rear = -1;
    }
    void enqueue(int val){
        if(rear == 4){
            cout << "Overflow: " << endl;
            return;
        }
        if(front == -1){
            front = 0;
        }
        arr[++rear] = val;
    }
    void dequeue(){
        if(front == -1 || front > rear){
            cout << "Underflow: " << endl;
            return;
        }
        front++;
    }
    void display(){
        if(front == -1){
            cout << "Error: Queue is Empty: " << endl;
            return;
        }
        for(int i = front; i <= rear; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    Queue q;
    q.enqueue(25);
    q.enqueue(26);
    q.enqueue(69);
    q.display();
    //q.dequeue();
    return 0;
}