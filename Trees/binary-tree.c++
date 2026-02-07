#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// building and traversing binary tree;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};


Node* buildTree(vector<int>& preOrder, int& index){
    index++;
    if(preOrder[index]==-1) return NULL;
    Node* root = new Node(preOrder[index]);
    root -> left =  buildTree(preOrder, index);
    root -> right =  buildTree(preOrder, index);
    return root;
}

void preOrderT(Node* root){
    if(root == NULL) return;
    cout<< root -> data << " ";
    preOrderT(root -> left);
    preOrderT(root -> right);
}
void inOrderT(Node* root){
    if(root == NULL) return;
    inOrderT(root -> left);
    cout<< root -> data << " ";
    inOrderT(root -> right);
}
void postOrderT(Node* root){
    if(root == NULL) return;
    postOrderT(root -> left);
    postOrderT(root -> right);
    cout<< root -> data << " ";
}

void levelOrderT(Node* root){
    queue<Node*> q;
    q.push(NULL);
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr == NULL){
            if(!q.empty()){
                cout << endl;
                q.push(NULL);
                continue;
            } else {
                break;
            }
        }
        cout << curr -> data;
        if(curr -> left != NULL) q.push(curr -> left);
        if(curr -> right != NULL) q.push(curr -> right);
        cout << " ";
    }
}

int main(){
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int index = -1;
    Node* root = buildTree(preOrder, index);

    cout <<"pre order: ";
    preOrderT(root);
    cout << endl;

    cout <<"in order: ";
    inOrderT(root);
    cout << endl;

    cout <<"post order: ";
    postOrderT(root);
    cout << endl;

    cout <<"level order: ";
    levelOrderT(root);
}
