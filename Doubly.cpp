#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
class DoublyLL {
    private:
    Node* head;
    public:
    DoublyLL(){
        head = NULL;
    }
    void insertAtHead(int data){
        Node* n = new Node(data);
        n->next = head;
        if(head != NULL){
            head->prev = n;
        }
        head = n;
    }
    void insertAtTail(int data){
        Node* n = new Node(data);
        if(head == NULL){
            head = n;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
    }
    void insertAtPosition(int pos, int data) {
    if (pos == 1) {
        insertAtHead(data);
        return;
    }
    Node* n = new Node(data);
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Position out of range!" << endl;
        delete n;
        return;
    }
    n->next = temp->next;
    n->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = n;
    }
    temp->next = n;
}
    void deleteAtHead() {
    if(head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    if(head != NULL) {
        head->prev = NULL;
    }
    delete temp;
}
    void deleteAtTail() {
    if(head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    if(head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    delete temp;
}
    void deleteAtPosition(int pos) {
    if(head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    if(pos == 1) {
        deleteAtHead();
        return;
    }
    Node* temp = head;
    for(int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }
    if(temp == NULL) {
        cout << "Position out of range!" << endl;
        return;
    }
    if(temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if(temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    delete temp;
}
    bool search(int key) {
    Node* temp = head;
    while(temp != NULL) {
        if(temp->data == key) {
            return true; 
        }
        temp = temp->next;
    }
    return false; 
}
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;  
        }
    }
};
int main(){
    DoublyLL dll;
    dll.insertAtHead(10);
    dll.insertAtHead(20);
    dll.insertAtHead(30);
    dll.insertAtTail(5);
    dll.insertAtPosition(2, 15);
    dll.deleteAtHead();
    dll.deleteAtTail();
    dll.deleteAtPosition(3);
    if(dll.search(15)){
        cout << "15 Found." << endl;
    } else {
        cout << "15 Not Found." << endl;
    }
    dll.display();
    return 0;
}