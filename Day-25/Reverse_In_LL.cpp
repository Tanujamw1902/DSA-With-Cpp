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

    void reverse(){
        Node* curr = head;
        Node* prev = NULL;
        while(curr != NULL){
            Node* next = curr->next;
            curr->next = prev;
            //updations for next iteration
            prev= curr;
            curr = next;
        }
        head = prev;
    }
};

int main(){
    List ll;
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printList();
    
    ll.reverse();
    ll.printList();
    return 0;
}