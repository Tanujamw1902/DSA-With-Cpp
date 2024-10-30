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

    int helper(Node* temp, int key){
        if (temp== NULL){
            return -1;
            if(temp->data == key){
                return 0;
            }
            int idx = helper(temp->next, key);
            if(idx == -1){
                return -1;
            }
            return idx + 1;
        }
    }

    int searchRec(int key){
        return helper(head, key);
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
    cout << ll.searchRec(4) << endl;
    return 0;
}