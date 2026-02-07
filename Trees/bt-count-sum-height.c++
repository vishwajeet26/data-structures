#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
    int val;
    Node* left;
    Node* right;
    Node(int data){
        val = data;
        left = right = NULL;
    }
};

Node* buildBt(vector<int>& values, int& idx){
    idx++;
    if(values[idx] == -1) return NULL;

    Node* root = new Node(values[idx]);
    root -> left = buildBt(values, idx);
    root -> right = buildBt(values, idx);
    return root;
}

int height(Node* root){
    if(root == NULL) return 0;
    int leftHt = height(root -> left);
    int rightHt = height(root -> right);
    return max(leftHt, rightHt) + 1;
}
int countNodes(Node* root){
    if(root == NULL) return 0;
    int leftNodes = countNodes(root -> left);
    int rightNodes = countNodes(root -> right);
    return leftNodes + rightNodes + 1;
}
int sumOfNodes(Node* root){
    if(root == NULL) return 0;
    int leftSum = sumOfNodes(root -> left);
    int rightSum = sumOfNodes(root -> right);
    return leftSum + rightSum + root -> val;
}
int main(){
    vector<int> preOrder = {1,2,-1,-1, 3, 4, -1, -1, 5, -1, -1};
    int idx = -1;
    Node* root = buildBt(preOrder, idx);

    cout << "height: "<< height(root) <<endl;
    cout << "sum of nodes: "<< sumOfNodes(root) <<endl;
    cout << "no. of nodes: "<< countNodes(root) <<endl;
}