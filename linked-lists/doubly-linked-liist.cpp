#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int d) {
        data = d;
        prev = NULL;
        next = NULL;
    }

    ~Node() {
        cout << "Memory is free for data " << data << endl;
    }
};

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

void insertAtHead(Node*& head, Node*& tail, int val) {
    if (head == NULL) {
        head = new Node(val);
        tail = head;
        return;
    }
    Node* n = new Node(val);
    n->next = head;
    head->prev = n;
    head = n;
}

void insertAtTail(Node*& head, Node*& tail, int val) {
    if (tail == NULL) {
        head = new Node(val);
        tail = head;
        return;
    }
    Node* n = new Node(val);
    tail->next = n;
    n->prev = tail;
    tail = n;
}

void insertAtBetween(Node*& head, Node*& tail, int val, int index) {
    if (index <= 1) {
        insertAtHead(head, tail, val);
        return;
    }

    int cnt = 1;
    Node* temp = head;

    while (cnt < index - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL || temp->next == NULL) {
        insertAtTail(head, tail, val);
        return;
    }

    Node* n = new Node(val);
    n->next = temp->next;
    n->prev = temp;
    temp->next->prev = n;
    temp->next = n;
}

void deletionAtNode(int position, Node*& head, Node*& tail) {
    if (head == NULL) return;

    // delete head
    if (position == 1) {
        Node* temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL;

        delete temp;
        return;
    }

    int cnt = 1;
    Node* curr = head;

    while (cnt < position && curr != NULL) {
        curr = curr->next;
        cnt++;
    }

    if (curr == NULL) return;

    // delete tail
    if (curr->next == NULL) {
        tail = curr->prev;
        tail->next = NULL;
    }
    // delete middle
    else {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    delete curr;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtBetween(head, tail, 39, 2);

    print(head);

    deletionAtNode(3, head, tail);

    if (head) cout << "Head: " << head->data << endl;
    if (tail) cout << "Tail: " << tail->data << endl;

    print(head);
    cout << "Length: " << getLength(head) << endl;

    return 0;
}
