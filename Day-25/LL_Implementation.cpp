#include<iostream>
using namespace std;

class Node{
    public:
            int data;
            Node* next;
            Node(int val){
                data = val;
                next = NULL;
            }
};

class List{
    Node* head;
    Node* tail;
    public:
        List(){
            head = NULL;
            tail = NULL;
        }

void printList(){
    Node* temp = head;
    while (temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

//Push Front in LL
    void push_front(int val){
        Node* newNode = new Node(val); //dynamic
        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode-> next = head;
            head = newNode;
        }
    }

//Push Back in LL
    void push_back(int val){
        Node* newNode = new Node(val);
        if(head = NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
};

int main(){
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printList();

    ll.push_back(4);
    ll.push_back(5);
    ll.printList();
    return 0;
}