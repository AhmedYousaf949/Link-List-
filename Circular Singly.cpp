#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};
class Circular {
    private:
    Node* head;
    public:
    Circular(){
        head = nullptr;
    }
    void inserthead(int data){
        Node* newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    void inserttail(int data){
        Node* newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    void anyposition(int pos, int data){
        Node* newNode = new Node(data);
        if(pos == 1){
            inserthead(data);
            return;
        }
        Node* temp = head;
        for(int i = 1; i < pos - 1 && temp->next != head; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void deletehead(){
        if(head == nullptr){
            return;
        }
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        Node* del = head;
        temp->next = head->next;
        head = head->next;
        delete del;
    }
    void deletetail(){
        if(head == nullptr){
            return;
        }
        Node* temp = head;
        while(temp->next->next != head){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = head;
    }
    void deleteposition(int pos){
        if(pos == 1){
            deletehead();
            return;
        }
        Node* temp = head;
        for(int i = 1; i < pos - 1 && temp->next != head; i++){
            temp = temp->next;
        }
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
    void sortlist(){
        if(head == nullptr){
            return;
        }
        Node* i = head;
        int temp;
        do
        {
            Node* j = i->next;
            while(j != head){
                if(i->data > j->data){
                    //swap(i->data > j->data);
                    temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
                j = j->next;
            }
            i = i->next;
        } while (i->next != head);
    }
    void searchnupdate(int oldval, int newval){
        if(head == nullptr){
            return;
        }
        Node* temp = head;
        do
        {
            if(temp->data == oldval){
                temp->data = newval;
                cout << "Updated:";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Not Found:";
    }
    void display(){
        if(head == nullptr){
            cout << "Empty List. ";
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
    Circular ahmi;
    ahmi.inserthead(25);
    ahmi.inserthead(88);
    ahmi.inserthead(56);
    ahmi.inserttail(22);
    ahmi.inserttail(15);
    ahmi.anyposition(4, 19);
    ahmi.anyposition(5, 87);
    // ahmi.deletehead();
    // ahmi.deletetail();
    // ahmi.deleteposition(2);
    ahmi.searchnupdate(25, 69);
    ahmi.sortlist();
    ahmi.display();
    return 0;
}