#include <iostream>
using namespace std;


class Node {
    public: 
    int data;
    Node* next;
    //constructor
    Node(int val) {
        this -> data = val;
        this -> next = NULL;
    }
    // destructor
    ~Node(){
        int value = this -> data;
        // memory free;
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        };
        cout << "Memory is free for data " << value << endl;
    }
};

// insertion methods
void insertAtHead(Node* &head, int val){
    Node* n = new Node(val);
    n -> next = head;
    head = n ;
}
void insertAtTail(Node* &tail, int val){
    Node* n = new Node(val);
    tail -> next = n;
    tail = n;
}
void insertAtIndex(Node* &tail, Node* &head, int val, int index){
    //inserting at start
    if(index == 1){
        insertAtHead(head,val);
        return;
    }
    Node* n = new Node(val);
    Node* temp = head;
    int cnt = 1;
    while(cnt < index - 1){
        temp = temp -> next;
        cnt++;
    };
    //inserting at last
    if(temp -> next == NULL){
        insertAtTail(tail, val);
        return;
    };
    n -> next = temp -> next;
    temp -> next = n;
};



void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << "  ";
        temp = temp -> next;
    };
    cout << endl;
}


//deletion 
void deleteAtIndex(Node* &tail, Node* &head, int index){
    if(index == 1){
        Node* curr = head;
        head = curr -> next;
        curr -> next = NULL;
        delete curr;
    } 
    else
     {
    int counter = 1;
    Node* prev = NULL;
    Node* curr = head;
    while(counter < index && curr != NULL){
        prev = curr;
        curr = curr -> next;
        counter++;
    };
    // index out of range
    if (curr == NULL) {
        return;
    }

    prev -> next = curr -> next;
    curr -> next = NULL;
    //update tail if it is the last index
    if(prev -> next == NULL){
        tail = prev;
    }
    delete curr;
}
}


int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    insertAtTail(tail, 20);
    insertAtTail(tail, 30);

    insertAtIndex(tail, head, 25, 1);
    print(head);
    deleteAtIndex(tail, head, 4);
    print(head);
    cout << tail << endl;
    

    return 0;
}