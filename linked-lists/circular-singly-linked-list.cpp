#include <iostream>
using namespace std;

// in circular singly ll we only need tail, no head required;

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
        cout << "Memory is free for data " << data << endl;
    }
};

void insertAtIndex(Node* &tail, Node* &head, int val, int index){
   
};

void print(Node* &head){
    Node* orgHead = head;
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << "  ";
        temp = temp -> next;
    };
    cout << endl;
}

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;

    print(head);


    return 0;
}