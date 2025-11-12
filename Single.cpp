#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }
    void insertAtHead(int data) {
        Node* n = new Node(data);
        n->next = head;
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
    }
    void insertAtPosition(int pos, int data){
        if(pos == 1){
            insertAtHead(data);
            return;
        }
        Node* n = new Node(data);
        Node* temp = head;
        for(int i = 1; i < pos-1 && temp != NULL; i++){
            temp = temp->next;
            if(temp == NULL){
                cout <<"Out OF Range." << endl;
                delete n;
                return;
            }
            n->next = temp->next;
            temp->next = n;
        }
    }
    bool search(int key){
        Node* temp = head;
        while(temp != NULL){
            if(temp->data == key){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    void deleteAtHead(){
        if(head == NULL){
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void deleteAtTail(){
        if(head == NULL){
            return;
        }
        if(head->next == NULL){
            delete head;
            head = NULL;
        }
        Node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    void deleteAtPosition(int pos){
        if(head == NULL){
            return;
        }
        if(pos == 1){
            deleteAtHead();
            return;
        }
        Node* prev = head;
        for(int i = 1; i < pos - 1 && prev->next != NULL; i++){
            prev = prev->next;
        }
        if(prev == NULL || prev->next == NULL){
            cout << "Out Of Range." << endl;
            return;
        }
        Node* temp = prev->next;
        prev->next = temp->next;
        delete temp;
    }
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    LinkedList list;
    list.insertAtHead(5);
    list.insertAtHead(10);
    list.insertAtHead(11);
    list.insertAtTail(14);
    list.insertAtPosition(3, 21);
    list.display();
    if(list.search(21)){
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }
    list.deleteAtHead();
    list.deleteAtTail();
    return 0;
}