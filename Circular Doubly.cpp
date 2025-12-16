#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node* previous;
    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->previous = nullptr;
    }
};
class Doubly {
    private:
    Node* head;
    public:
    Doubly(){
        head = nullptr;
    }
    void inserthead(int data){
        Node* newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
            newNode->next = newNode;
            newNode->previous = newNode;
        }
        else {
            Node* last = head->previous;
            newNode->next = head;
            newNode->previous = last;
            last->next = newNode;
            head = newNode;
        }
    }
    void display(){ 
        if(head == nullptr){
            return;
        }
        Node* temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        
    }
};
int main(){
    Doubly ahmi;
    ahmi.inserthead(25);
    ahmi.inserthead(68);
    ahmi.inserthead(77);
    ahmi.display();
    return 0;
}