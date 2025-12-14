#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
class LinkedList {
private:
    Node* head1;
    Node* head2;
    Node* mergehead;
    public:
    LinkedList(){
        head1 = nullptr;
        head2 = nullptr;
        mergehead = nullptr;
    }
    void insert(Node*& head, int val){
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void sortlist(Node* head){
       // Node* temp;
        for(Node* i = head; i != nullptr; i = i->next){
            for(Node* j = i->next; j != nullptr; j= j->next){
                if(i->data > j->data){
                    int temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
    }
    void display(Node* head){
        while(head != NULL){
            cout << head->data << " ";
            head = head->next;
        }
    }
    void insertlist1(int val){
        insert(head1, val);
    }
    void sortlist1(){
        sortlist(head1);
    }
    void display1(){
        display(head1);
    }
    void insertlist2(int val){
        insert(head2, val);
    }
    void sortlist2(){
        sortlist(head2);
    }
    void display2(){
        display(head2);
    }
    void merge(){
        Node* p1 = head1;
        Node* p2 = head2;
        if(!head1){
            mergehead = head2;
            return;
        } 
        if(!head2){
            mergehead = head1;
            return ;
        }
        if(p1->data < p2->data){
            mergehead = p1;
            p1 = p1->next;
        }
        else {
            mergehead = p2;
            p2 = p2->next;
        }
        Node* tail = mergehead;
        while(p1 != nullptr && p2 != nullptr){
            if(p1->data < p2->data){
                tail->next = p1;
                p1 = p1->next;
            }
            else{
                tail->next = p2;
                p2 = p2->next;
            }
            tail = tail->next;
        }
        if(p1 != nullptr){
            tail->next = p1;
        }
        else{
            tail->next = p2;
        }
    }
    void displaymerge(){
        display(mergehead);
    }
};
int main(){
    LinkedList ahmi;
    ahmi.insertlist1(12);
    ahmi.insertlist1(6);
    ahmi.insertlist1(8);
    ahmi.sortlist1();
    ahmi.display1();
    //ahmi.sortlist();
    ahmi.insertlist2(2);
    ahmi.insertlist2(26);
    ahmi.insertlist2(55);
    ahmi.sortlist2();
    ahmi.display2();
    cout << "\nMerged List: \n";
    ahmi.merge();
    ahmi.displaymerge();
    return 0;
}