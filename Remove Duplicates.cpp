#include<iostream>
#include<string>
using namespace std;
class Node {
    public:
    int id;
    string name;
    float marks;
    Node* next;
    Node(int id, string name, float marks){
        this->id = id;
        this->name = name;
        this->marks = marks;
        this->next = nullptr;
    }
};
class Student {
    private:
    Node* head;
    public:
    Student(){
        head = nullptr;
    }
    void insert(int id, string name, float marks){
        Node* newNode = new Node(id, name, marks);
        if(head == nullptr){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void removeduplicates(){
        if(head == nullptr){
            return;
        }
        for(Node* i = head; i != nullptr; i = i->next){
            Node* prev = i;
            for(Node* j = i->next; j != nullptr;){
                if(i->id == j->id){
                    Node* temp = j;
                    prev->next = j->next;
                    j = j->next;
                    delete temp;
                }
                else{
                    prev = j;
                    j = j->next;
                }
            }
        }
    }
    void display(){
        Node* temp = head;
        while(temp != nullptr){
            cout << "\nID: " << temp->id << "\nName: " << temp->name << "\nMarks: " << temp->marks;
            temp = temp->next;
        }
        cout << "\nF*ck Off:";
    }
};
int main(){
    Student ahmi;
    ahmi.insert(584, "Summer", 98);
    ahmi.insert(589, "Winter", 45);
    ahmi.insert(589, "Spring", 87);
    ahmi.insert(784, "Autumn", 97);
    ahmi.removeduplicates();
    ahmi.display();
    return 0;
}