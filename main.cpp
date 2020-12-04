#include <iostream>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node*middle;
};

class TernaryTree{
private:
    Node *root;
    int leaf_count_h(Node *);
    int degree_one_nodes_count_h(Node *current);
    void insert_h(int, Node * );
    void traverse_LMRW_h(Node *current);

public:
    void construct_tree(int A[], int n);
    void traverse_LMRW();
    int leaf_count();
    int degree_one_nodes_count();
    void insert(int value);

    TernaryTree() {
        root = nullptr;
    }
};
void TernaryTree::insert_h(int value, Node *leaf) {
    if(value < leaf->data) {
        if(leaf->left != nullptr)
            insert_h(value, leaf->left);
        else {
            leaf->left = new Node;
            leaf->left->data = value;
            leaf->left->left = nullptr;
            leaf->left->right = nullptr;
            leaf->middle->middle = nullptr;
        }
    }
    else if (value == leaf -> data){
        if(leaf ->middle != nullptr)
            insert_h(value, leaf ->middle);
        else {
            leaf ->middle = new Node;
            leaf ->middle->data = value;
            leaf->left->left = nullptr;
            leaf->left->right = nullptr;
            leaf->middle->middle = nullptr;
        }

    }
    else if(value > leaf->data) {
        if(leaf->right != nullptr)
            insert_h(value, leaf->right);
        else {
            leaf->right = new Node;
            leaf->right->data = value;
            leaf->right->left = nullptr;
            leaf->right->right= nullptr;
            leaf->middle->middle = nullptr;
        }
    }
}
void TernaryTree::insert(int value){
    if(root != nullptr)
        insert_h(value, root);
    else {
        root = new Node;
        root->data = value;
        root->left = nullptr;
        root->right = nullptr;
        root->middle = nullptr;

    }
}

void TernaryTree::construct_tree(int A[], int n) {
    for(int i =0; i < n; i++){
        insert(A[i]);
    }
}

void TernaryTree::traverse_LMRW_h(Node *current) {
    if (current != nullptr) {
        traverse_LMRW_h(current->left);
        traverse_LMRW_h(current->right);
        traverse_LMRW_h(current->middle);
        cout<< current-> data << endl;
    }
}

void TernaryTree::traverse_LMRW(){
    return traverse_LMRW_h(root);
}

int TernaryTree::leaf_count_h(Node *current){
    static int cnt = 0;
    if (current != nullptr) {
        if ((current->left == nullptr) and (current->right == nullptr))
            cnt += 1;
        leaf_count_h(current->left);
        leaf_count_h(current->right);
        leaf_count_h(current->middle);
    }
    return cnt;
}

int TernaryTree::leaf_count() {
    return leaf_count_h(root);
}
int TernaryTree::degree_one_nodes_count_h(Node *current){
    static int sum = 0;
    if (current != nullptr) {
        sum += current->data;
        degree_one_nodes_count_h(current->left);
        degree_one_nodes_count_h(current->right);
        degree_one_nodes_count_h(current->middle);
    }
    return sum;
}

int TernaryTree::degree_one_nodes_count() {
    return degree_one_nodes_count_h(root);
}

int main(){
    int A[14] = {7,4,2,2,3,1,8,4,0,6,5,9,4,6};
    int n = sizeof(A)/sizeof(A[0]);
    TernaryTree T;
    T.construct_tree(A, n);
    T.traverse_LMRW();
    cout << T.leaf_count() << endl;
    cout << T.degree_one_nodes_count() << endl;
    return 0;
}

