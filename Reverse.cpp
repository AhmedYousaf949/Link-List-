#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
class Reverselist {
    public:
    Node* head;
    Reverselist() {
        head = NULL;
    }
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    void display() {
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
int main(){
    Reverselist list;
    list.insertAtTail(5);
    list.insertAtTail(6);
    list.insertAtTail(7);
    list.insertAtTail(8);
    list.insertAtTail(9);
    list.reverse();
    list.display();
    return 0;
}